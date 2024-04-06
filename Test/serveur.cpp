#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h> // Pour fcntl et O_NONBLOCK
#include <errno.h>

#define PORT 8080

int serveur()
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
    std::cout << "on est laa" << std::endl;

    // Avant d'appeler accept
    fcntl(server_fd, F_SETFL, O_NONBLOCK);

    // Appel à accept
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (new_socket < 0)
    {
        // Si errno == EAGAIN ou errno == EWOULDBLOCK, alors il n'y a pas de connexions entrantes
        if ((errno == EAGAIN) || (errno == EWOULDBLOCK))
        {
            // Pas de connexions entrantes
        }
        else
        {
            std::cerr << "Accept failed" << std::endl;
            return -1;
        }
    }

    std::cout << "mais pas la" << std::endl;

    // Receive file
    int valread = read(new_socket, buffer, 1024);
    std::cout << "File received" << std::endl;

    // Write received data to file
    std::ofstream file("ficher.txt", std::ios::binary);
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
