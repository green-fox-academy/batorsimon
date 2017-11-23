#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "SerialPortWrapper.h"

using namespace std;

SerialPortWrapper *serial = new SerialPortWrapper("COM3", 115200);

class Lines{
    private:
       // vector<Port_vector> port_vector;

    public:

};


void menu(){

    system("cls");
    cout << "          Temperature Logger Application                " << endl;
    cout << "=========================================================" << endl;
    cout << " Commands:                                              " << endl;
    cout << " h        Show command list                             " << endl;
    cout << " o        Open port                                     " << endl;
    cout << " s        Start logging / Stop logging                  " << endl;
    cout << " c        Close port                                    " << endl;
    cout << " l        List after error handling                     " << endl;
    cout << " f        Store datas in a file                         " << endl;
    cout << " r        Read datas from a file                        " << endl;
    cout << " a        Avarage temperature handling by days          " << endl;
    cout << " max      Maximum temperature handling by days          " << endl;
    cout << " min      Minimum temperature handling by days          " << endl;
    cout << " at       Avarage temperature handling by temperatures  " << endl;
    cout << " maxt     Maximum temperature handling by temperatures  " << endl;
    cout << " mint     Minimum temperature handling by temperatures  " << endl;
    cout << " e        Exit from the program                         " << endl;
    cout << "=========================================================" << endl << endl;
    system("pause");
    system("cls");

}



void open_port(){
     serial->openPort();
    cout << "The port has been opened." << endl;
}

void start_logging(){
    string line;
    while(1) {
        serial->readLineFromPort(&line);
        if (line.length() > 0){
            cout << line << endl;

            //log_vector->push_back(line);
        }

        if(kbhit()) {
            if (getch() == 's'){
                break;
            }
        }

    }
}

void close_port(){
    serial->closePort();
    cout << "The port has been closed." << endl;
}

void list_after_error_handling(){

    cout << "Listing contents of the log on screen: " << endl;
/*
    for (unsigned int i = 0; i < log_vector.size(); ++i) {
        cout << i << ".: " << log_vector.at(i) << endl;
    }
    */
}

void store_datas_in_file(){

}
void read_datas_from_file(){

}

void avarage_temperature_by_days(){

}

void maximum_temperature_by_days(){

}

void minimum_temperature_by_days(){

}

void avarage_temperature_by_temperatures(){

}

void minimum_temperature_by_temperatures(){

}

void maximum_temperature_by_temperatures(){

}

void commands() {
    string command;

    do {
        cin >> command;
        if (command == "e") {
            cout << "The program is exiting now. Goodbye!" << endl;
            exit(0);
        } else if (command == "h") {
            menu();
            continue;

        } else if(command == "o"){
            open_port();
            continue;

        } else if(command == "s"){
            start_logging();
            continue;

        } else if(command == "c"){
            close_port();
            continue;

        } else if(command == "l"){
            list_after_error_handling();
            continue;

        } else if(command == "f"){
            store_datas_in_file();
            continue;

        } else if(command == "r"){
            read_datas_from_file();
            continue;

        } else if(command == "a"){
            avarage_temperature_by_days();
            continue;

        } else if(command == "max"){
            maximum_temperature_by_days();
            continue;

        } else if(command == "min"){
            minimum_temperature_by_days();
            continue;

        } else if(command == "at"){
            avarage_temperature_by_temperatures();
            continue;

        } else if(command == "maxt"){
            maximum_temperature_by_temperatures();
            continue;

        } else if(command == "mint"){
            minimum_temperature_by_temperatures();
            continue;

        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (command != "exit");

}

void port_info(){
    vector<string> ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of found serial ports: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << "\tPort name: " << ports.at(i) << endl;
    }
}

int main()
{
    menu();
    port_info();
    commands();

    return 0;
}
