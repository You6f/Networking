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

void putbraks(string fichier)
{
    json test;
    // test["age"] = 30;
    ofstream file(fichier);

    file << setw(4) << test << endl; // Pretty print with indentation
    file.close();
    cout << "JSON data has been written to " << fichier << endl;
}

void write(string fichier)
{

    // Create a JSON object
    json data;

    // Add some data to the JSON object
    data["name"] = "John rick";
    data["age"] = 30;
    data["city"] = "New York";
    data["numero"] = "53";
    data["numero2"] = "53";
    // Write the JSON object to a file
    ofstream file(fichier);

    file << setw(4) << data << endl; // Pretty print with indentation
    file.close();
    cout << "JSON data has been written to " << fichier << endl;
}

void addData(string cible, string resultat, string fichier)
{
    // Create a JSON object
    json data;

    // Add some data to the JSON object
    data[cible] = resultat;
    // Write the JSON object to a file
    fstream file(fichier);
    file << setw(4) << data << endl; // Pretty print with indentation
    file.close();
    cout << "JSON data has been written to " << fichier << endl;
}

void updateFileWithJson(json datafile, string destinationfile)
{

    json datafile2;
    ifstream file_in(destinationfile); // Ouvrir le fichier en mode lecture
    if (file_in.is_open())
    {
        file_in >> datafile2; // Lire le contenu JSON depuis le fichier
        file_in.close();      // Fermer le fichier après la lecture
    }
    datafile.merge_patch(datafile2);
    // Ouvrir le fichier en mode écriture

    ofstream file_out(destinationfile);

    if (file_out.is_open())
    {

        // Écrire les données JSON dans le fichier avec une indentation pour une meilleure lisibilité
        file_out << setw(4) << datafile << endl;
        // file_out << datafile2 << endl;
        file_out.close();                                                    // Fermer le fichier après l'écriture
        cout << "JSON data has been written to " << destinationfile << endl; // Message de sortie
    }
    else
    {
        cout << "Failed to open file " << destinationfile << " for writing." << endl;
    }
}

void mergeJson(string fromfile, string tofile)
{

    updateFileWithJson(read(fromfile), tofile);
}

void updateFile(string cible, int resultat, string fichier)
{

    // Créer un objet JSON en lisant à partir du fichier existant
    json copy;

    ifstream file_in(fichier); // Ouvrir le fichier en mode lecture
    if (file_in.peek() != std::ifstream::traits_type::eof())
    {
        if (file_in.is_open())
        {
            file_in >> copy; // Lire le contenu JSON depuis le fichier
            file_in.close(); // Fermer le fichier après la lecture
        }
    }

    // Écrire les nouvelles données dans l'objet JSON
    copy[cible] = resultat;

    // Ouvrir le fichier en mode écriture
    ofstream file_out(fichier);
    if (file_out.is_open())
    {
        // Écrire les données JSON dans le fichier avec une indentation pour une meilleure lisibilité
        file_out << setw(4) << copy << endl;
        file_out.close();                                            // Fermer le fichier après l'écriture
        cout << "JSON data has been written to " << fichier << endl; // Message de sortie
    }
    else
    {
        cout << "Failed to open file " << fichier << " for writing." << endl;
    }
}

void write3(string cible, int resultat, string fichier)
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
    file.close();
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
    file.close();
}
