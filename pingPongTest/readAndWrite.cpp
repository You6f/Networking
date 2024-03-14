#include <iostream>
#include <fstream>
#include "json.hpp" // Include the nlohmann/json library

using json = nlohmann::json;
using namespace std;

json read(string fichier)
{
    ifstream file_in(fichier); // Ouvrir le fichier en mode lecture
    if (file_in.peek() != std::ifstream::traits_type::eof())
    {

            // Read the JSON file
            ifstream file(fichier);
            json data;
            file >> data;
            file.close();
            return data;
        
    }
    else{
        cout<<"le fichier est vide "<<endl; 

    }
 return -1;   
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



void updateFile(string cible, json resultat, string fichier) // cette fonction permet d'ajouter des élements à un fichier Json, en renseignant une cible(elle est utile si on veut imbriquer les données)
{

    // Créer un objet JSON en lisant à partir du fichier existant
    json copy;

    ifstream file_in(fichier); // Ouvrir le fichier en mode lecture
    if (file_in.peek() != std::ifstream::traits_type::eof())
    {
        if (file_in.is_open())
        {
            file_in >> copy; // Lire le contenu JSON depuis le fichier
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

void updateFile(json datafile, string destinationfile)// c'est la même fonction que just au dessus mais sans cible.
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

void mergeJson(string fromfile, string tofile)// cette fonction permet de fusionner un ficher Json dans un autre,(donc garde les infos du ficher de destination et en ajoute d'autres)
{

    updateFile(read(fromfile), tofile);
}

void copyJson(string fromfile, string tofile)//copy un json  et le met dans au autre (elle écrase le fichier de destination)
{
    json copy = read(fromfile);
    ofstream file3(tofile);
    file3 << setw(4) << tofile << endl; // Pretty print with indentation
    file3.close();
}


void clearJson(string fichier)
{
    ofstream file(fichier);
    file.close();
}



void createJson(string fichier)
{

    ofstream file(fichier);
    file.close();
    putbraks(fichier);
}

void afficher(json data){

    cout<< data <<endl;
}


void testwrite(string fichier)
{

    // Create a JSON object
    json data;
    json data2;

    data2["name"] = "John f";
    data2["age"] = 45;
    data2["city"] = "New York";


    // Add some data to the JSON object
    data["name"] = data2;
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