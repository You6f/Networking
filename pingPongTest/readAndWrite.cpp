#include <iostream>
#include <fstream>
#include "json.hpp" // Include the nlohmann/json library

using json = nlohmann::json;
using namespace std;

json read(string fichier)
{
    // Read the JSON file
    ifstream file(fichier);
    json data;
    file >> data;
    file.close();

    return data;
}

void write(string cible, int resultat, string fichier)
{

    // Create a JSON object
    json copy = read(fichier);

    copy[cible] = resultat; // write the data

    ofstream file(fichier);

    file << setw(4) << copy << endl; // Pretty print with indentation
    file.close();

    cout << "JSON data has been written to data.json" << endl;
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

void clean(string fichier)
{
    ofstream file(fichier);
}

void copyJson(string fromf, string tof)
{
    json copy = read(fromf);
    ofstream file3(tof);
    file3 << setw(4) << tof << endl; // Pretty print with indentation
    file3.close();
}

void createJson(string fichier)
{

    ofstream file(fichier);
}
