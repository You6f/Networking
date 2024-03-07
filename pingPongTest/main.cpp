#include <iostream>
#include "readAndWrite.cpp"
#include "reciever.cpp"
#include "sender.cpp"

int main()
{
    recieve();
    string texte;
    cout << "veiller entrer une cible";
    cin >> texte;

    write(texte, 66, "data.json");
    send();

    // recieve();

    return 0;
}
