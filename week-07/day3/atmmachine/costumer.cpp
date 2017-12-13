#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <ctime>

#include "costumer.h"
#include "atm.h"

using namespace std;

void Atm::costumer_menu(string x) {
    system("cls");
    cout << "-------------------------------------------" << endl;
    cout << "|        Welcome to Brave Bank            |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "| Commands:                               |" << endl;
    cout << "| wm      withdraw money                  |" << endl;
    cout << "| check   shows your current balance      |" << endl;
    cout << "| print   prints you a receipt            |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "| menu  Opens the main menu               |" << endl;
    cout << "| exit  Exiting from the program          |" << endl;
    cout << "-------------------------------------------" << endl;
    system("pause");
    system("cls");

    costumer_commands(x);
}

void Atm::costumer_commands(string x) {
    string command;

    do {
        cin >> command;
        if (command == "exit") {
            cout << "The program is exiting now. Goodbye!" << endl;
            exit(0);
        } else if (command == "menu") {
            costumer_menu(x);
            continue;
        } else if(command == "wm"){
            withdraw_money(x);
            continue;
        } else if (command == "check") {
            check_balance(x);
            continue;
        } else if (command == "print") {
            print_balance(x);
            continue;
        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (command != "exit");
}

void Atm::withdraw_money(string x) {

    cout << "Write down how much money you need: ";
    int a;
    int b = 0;
    cin >> a;

    while(1){
        if(!cin){
            cout << "You can put in only numbers!" << endl;
            cin.clear();
            break;

        } else if(a % 1000 == 0){
            for(unsigned int i = 0; i < users.size(); i++){
                if(users.at(i).get_name() == x && users.at(i).get_balance() > a){
                    b = (users.at(i).get_balance() - a);
                    users.at(i).set_balance(b);
                    cout << "Operation done. " << endl;
                    break;
                }
            }
            break;   // need this break from the whole loop

        } else{
            cout << "Invalid operation. " << endl;
            break;
        }
    }

}

void Atm::print_balance(string x) {

    time_t now = time(0);
    char* dt = ctime(&now);

    ofstream outfile;
    outfile.open("balance.txt");

    outfile << "          Brave Bank         " <<endl;
    outfile << "       Your bank receipt     " <<endl;
    outfile << "-----------------------------" <<endl;
    for(unsigned int i = 0; i < users.size(); i++){
        if(users.at(i).get_name() == x){
            outfile << "Your name: "<< endl << users.at(i).get_name() << endl << endl;
            outfile << "Your actual balance: " << endl << users.at(i).get_balance() << endl << endl;
            //outfile << "Withdrawn money: " << endl << b << endl << endl;
            outfile << "The changes were made at: " << endl << dt << endl << endl;
        }
    }
    outfile.close();
}


void Atm::check_balance(string x) {

    for(unsigned int i = 0; i < users.size(); i++){
        if(users.at(i).get_name() == x){
            cout << "Your current balance is: " << users.at(i).get_balance() << endl;
        }
    }

}
