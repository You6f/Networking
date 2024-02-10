#include <iostream>
#include <fstream>
#include "json.hpp" // Include the nlohmann/json library

using json = nlohmann::json;

int main() {
    // Create a JSON object
    json data;
    
    

    // Add some data to the JSON object
    data["name"] = "John belugaaa";
    data["age"] = 30;
    data["city"] = "New York"; 

    // Write the JSON object to a file
    std::ofstream file("data.json");

    file << std::setw(4) << data << std::endl; // Pretty print with indentation
    file.close();

    std::cout << "JSON data has been written to data.json" << std::endl;

    return 0;
}
