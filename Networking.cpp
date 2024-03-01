#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sstream>

#define PORT 8080

char ipAddress[20];
void setIpAddress(char address[20])
{

    strcpy(ipAddress, address);
}

int receive()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }

    // Forcefully attaching socket to the port 8080
    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        std::cerr << "Setsockopt failed" << std::endl;
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        std::cerr << "Bind failed" << std::endl;
        return -1;
    }

    // Listening
    if (listen(server_fd, 3) < 0)
    {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }

    // Accept connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        std::cerr << "Accept failed" << std::endl;
        return -1;
    }

    // Receive file
    int valread = read(new_socket, buffer, 1024);
    std::cout << "File received" << std::endl;

    // Write received data to file
    std::ofstream file("received_file.txt", std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return -1;
    }

    file.write(buffer, valread);
    file.close();

    close(new_socket);
    close(server_fd);

    return 0;
}

int sendd()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 192.168.1.182
    //  Convert IPv4 and IPv6 addresses from text to binary form

    if (inet_pton(AF_INET, ipAddress, &serv_addr.sin_addr) <= 0)
    {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }

    // Open file
    std::ifstream file("data.json", std::ios::binary | std::ios::ate);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return -1;
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read file and send
    file.read(buffer, size);
    send(sock, buffer, size, 0);
    std::cout << "File sent successfully" << std::endl;

    file.close();
    close(sock);

    return 0;
}