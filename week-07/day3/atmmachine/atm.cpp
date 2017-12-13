#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

#include "atm.h"

Atm::Atm() {};

Atm::Atm(double atm_money){
    this->atm_money = atm_money;
};


Atm::~Atm() {
    for(int i = 0; i < users.size(); i++){
        //delete users.at(i).Users();
    }
};

void Atm::add(Users *user) {
    users.push_back(*user);
};

void Atm::set_atmmoney(double atm_money){
    this->atm_money = atm_money;
};

int Atm::get_atmmoney(){
    return atm_money;
};

int Atm::get_fault(){
    return fault;
};

void Atm::main_menu() {

cout << "Please log in: " << endl;
cout << "Enter your user name: ";
string user_name;
getline(cin, user_name);

    for(unsigned int j = 0; j < users.size(); j++){
        if(user_name != users.at(j).get_name() && j == users.size()-1 ) {
            cout << "\nInvalid check-in!!" << endl << "The program is exiting now." << endl;
            exit(0);
        } else if(user_name == users.at(j).get_name() ) {
            break;
        } /*else {
            continue;
        } */

    }


    while(1){

        cout << "Enter your PIN code: ";
        string user_pin_str;
        getline(cin, user_pin_str);
        int user_pin = atoi(user_pin_str.c_str());

        for(unsigned int j = 0; j < users.size(); j++ ){
            if(user_name == users.at(j).get_name() && user_pin == users.at(j).get_pin() && users.at(j).get_admin() == 1) {
                administrator_menu(user_name);

            } else if(user_name == users.at(j).get_name() && user_pin == users.at(j).get_pin() && users.at(j).get_admin() == 0) {
                costumer_menu(user_name);

            } else if(user_name == users.at(j).get_name() && user_pin != users.at(j).get_pin() && users.at(j).get_admin() == 0) {
                fault++;
                if(fault == 3){
                    cout << "\nInvalid check-in!!" << endl << "The program is exiting now." << endl;
                    exit(0);
                }else{
                    continue;
                }

            } else if(j == users.size() && user_pin != users.at(j).get_pin() ){
                cout << "you moron" << endl;
                exit(0);

            } else{
                continue;
            }

        }

    }
};
