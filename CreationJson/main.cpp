#include <iostream>
#include <fstream>
#include "json.hpp" // Include the nlohmann/json library
#include <string>

using json = nlohmann::json;
using namespace std;

void write(string cible, int resultat)
{

    // Create a JSON object
    json data;
    json data2;

    // Add some data to the JSON object
    data["name"] = "John rick";
    data["age"] = 30;
    data["city"] = "New York";
    data["numero"] = "53";
    data[cible] = resultat;
    // Write the JSON object to a file
    data2 = data;
    ofstream file("data.json");

    ofstream file2("data2.json");

    file << setw(4) << data << endl; // Pretty print with indentation
    file.close();

    file2 << setw(4) << data2 << endl; // Pretty print with indentation
    file2.close();
    cout << "JSON data has been written to data.json" << endl;
}

json read()
{
    // Read the JSON file
    ifstream file("data.json");
    json data;
    file >> data;
    file.close();

    return data;
}

void menu()
{
    /*    string c;
        int r;
        cout << "veiller entrer une cible ";
        cin >> c;
        cout << "veiller entrer un resultat ";
        cin >> r;

        write(c, r);*/
}

int main()
{
    menu();
    json jsonData = read();

    write("hello", 43);

    // Read the JSON file

    jsonData["sdfqdf"] = 67;
    ofstream file("data.json");

    file << setw(4) << jsonData << endl;

    json copie = jsonData;
    cout << "JSON data read from file:" << endl;
    cout << setw(4) << jsonData << endl;

    return 0;
}
