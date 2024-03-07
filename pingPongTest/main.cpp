#include <iostream>
#include "readAndWrite.cpp"
#include "reciever.cpp"
#include "sender.cpp"
#include <string>

int main()
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
