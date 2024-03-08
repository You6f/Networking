#include <iostream>
using namespace std;
#include "readAndWrite.cpp"
#include "reciever.cpp"
#include "sender.cpp"
#include <string>
#include <unistd.h>

string genererMotAleatoire()
{
    // utilise l'heure actuelle comme graine pour le générateur de nombres aléatoires
    int longueur = rand() % 6 + 5; // génère une longueur aléatoire entre 5 et 10
    string mot;
    for (int i = 0; i < longueur; ++i)
    {

        char lettre = 'a' + rand() % 26; // génère une lettre aléatoire
        mot.push_back(lettre);
    }
    return mot;
}

int main()
{
    while (true)
    {
        srand(time(NULL));
        string hasard = genererMotAleatoire();
        write(hasard, 66, "data.json");
        send();

        recieve();
        sleep(2);
    }
}

int mainn()
{
    cout << "are you the host (yes/NO)";
    string reponse;
    cin >> reponse;
    while (true)
    {
        if (reponse == "yes")
        {
            string hasard;
            cout << "ok vous être sender";
            recieve();
            string texte;
            cout << "veiller entrer une cible";
            cin >> texte;

            write(texte, 66, "data.json");
            send();
            cout << "appuyer sur une touche";
            cin >> hasard;
        }
        else if (reponse == "NO")
        {
            string texte;
            string hasard;
            cout << "veiller entrer une cible";
            cin >> texte;
            write(texte, 66, "data.json");
            send();
            cout << "appuyer sur une touche";
            cin >> hasard;
            recieve();
        }
    }
    // recieve();

    return 0;
}
