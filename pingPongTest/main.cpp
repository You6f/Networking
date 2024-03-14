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
  

    //updateFile("lacible","resklsdfjml","update.json");
    //createJson("test2.json");
    //clearJson("test2");
    cout<<read("update.json")<<endl;

   // write("test.json");
    //afficher(read("test.json")["name"]["age"]);
   /*srand(time(NULL));

    while (true)
    {
        updateFile(genererMotAleatoire(), 6, "update.json");
        mergeJson("update.json", "data.json");
        send();
        clean("update.json");
        recieve();
        mergeJson("update.json", "data.json");
        clean("update.json");
        sleep(2);
    }*/ 

    return 0;
}
int mainn2()
{
    while (true)
    {
        srand(time(NULL));
        string hasard = genererMotAleatoire();
        updateFile(hasard, 1, "data3.json");
        send();

        recieve();
        sleep(10);
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

            updateFile(texte, 50000000, "data.json");
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
            updateFile(texte, 66, "data.json");
            send();
            cout << "appuyer sur une touche";
            cin >> hasard;
            recieve();
        }
    }
    // recieve();

    return 0;
}
