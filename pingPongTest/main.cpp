#include <iostream>
#include "readAndWrite.cpp"
#include "reciever.cpp"
#include "sender.cpp"
#include <string>

int main()
{
    cout << "are you the host (yes/NO)";
    string reponse;
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
    else
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

    // recieve();

    return 0;
}
