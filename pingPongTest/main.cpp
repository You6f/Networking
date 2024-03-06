#include <iostream>
#include "readAndWrite.cpp"
#include "reciever.cpp"
#include "sender.cpp"

int main()
{

    write("thetest", 66, "data.json");
    recieve();

    return 0;
}
