#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "SerialPortWrapper.h"

using namespace std;

void menu(){
system("cls");
cout << "Temperature Logger Application         " << endl;
cout << "====================================== " << endl;
cout << " Commands:                             " << endl;
cout << " h        Show command list            " << endl;
cout << " o        Open port                    " << endl;
cout << " s        Start logging / Stop logging " << endl;
cout << " c        Close port                   " << endl;
cout << " l        List after error handling    " << endl;
cout << " e        Exit from the program        " << endl;
cout << "====================================== " << endl << endl;
system("pause");
system("cls");

}


int main()
{
    menu();

    vector<string> ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of found serial ports: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << "\tPort name: " << ports.at(i) << endl;
    }

    // connection

        SerialPortWrapper *serial = new SerialPortWrapper("COM3", 115200);
        serial->openPort();
        string line;
        while(1){
            serial->readLineFromPort(&line);
            if (line.length() > 0){
            cout << line << endl;
            }
        }
        serial->closePort();
    return 0;
}
