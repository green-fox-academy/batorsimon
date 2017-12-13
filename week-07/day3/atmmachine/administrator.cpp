#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <ctime>

#include "administrator.h"
#include "atm.h"

using namespace std;

void Atm::administrator_menu(string x) {
    system("cls");
    cout << "------------------------------------------" << endl;
    cout << "|        Welcome to Brave Bank           |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| Logged in as administrator             |" << endl;
    cout << "| Commands:                              |" << endl;
    cout << "| up      upload money                   |" << endl;
    cout << "| check   check money                    |" << endl;
    cout << "| print   print Atm Balance              |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| menu  Opens the main menu              |" << endl;
    cout << "| exit  Exiting from the program         |" << endl;
    cout << "------------------------------------------" << endl;
    system("pause");
    system("cls");

    administrator_commands(x);
}

void Atm::administrator_commands(string x) {
    string command;

    do {
        cin >> command;
        if (command == "exit") {
            cout << "The program is exiting now. Goodbye!" << endl;
            exit(0);

        } else if (command == "menu") {
            administrator_menu(x);

        } else if(command == "up"){
            load_up();

        } else if(command == "check"){
            check_atm();

        } else if(command == "print"){
            print_atmBalance(x);

        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (command != "exit");


}

void Atm::load_up() {

    int a;
    int b;
    cout << "Write down how much money you want to add: ";
    cin >> a;

    while(1){
        if(!cin){
            cout << "The given parameter was not a number" << endl;
            cin.clear();
            break;
        } else if(a % 1000 == 0) {
            b = (get_atmmoney() + a);
            set_atmmoney(b);
            cout << "Operation done. " << endl;
            break;
        } else {
            cout << "Invalid operation. " << endl;
            break;
        }
    }


}

void Atm::check_atm() {

    cout << "How much money is in the Atm: " << get_atmmoney() << endl;

}

void Atm::print_atmBalance(string x) {

    time_t now = time(0);
    char* dt = ctime(&now);

    ofstream outfile;
    outfile.open("atmbalance.txt", ios::app);

    outfile << "         Brave Bank             " <<endl;
    outfile << "      Atm code:  8542446        " <<endl;
    outfile << "--------------------------------" <<endl;

    for(unsigned int i = 0; i < users.size(); i++){
        if(users.at(i).get_name() == x){
            outfile << "Who made the changes: " << endl << users.at(i).get_name() << endl;
            outfile << "The ATM actual balance: " << endl << get_atmmoney() << endl;
            outfile << "The changes were made at: " << endl << dt << endl << endl;
        }
    }
    outfile.close();
}
