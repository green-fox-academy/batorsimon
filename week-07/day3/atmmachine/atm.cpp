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
    //delete users
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

    while(1){
        system("cls");
        string user_name;
        int user_pin;

        cout << "Please log in: " << endl;

        cout << "Enter your user name: ";
        getline(cin, user_name);

        cout << "Enter your PIN code: ";
        cin >> user_pin;

        for(unsigned int j = 0; j < users.size(); j++ ){
            if(user_name == users.at(j).get_name() && user_pin == users.at(j).get_pin() && users.at(j).get_admin() == 1) {
                administrator_menu(user_name);
            } else if(user_name == users.at(j).get_name() && user_pin == users.at(j).get_pin() && users.at(j).get_admin() == 0) {
                costumer_menu(user_name);
            } else if(user_name == users.at(j).get_name() && user_pin != users.at(j).get_pin() && users.at(j).get_admin() == 0 && this->get_fault() < 3){
                fault++;
                continue;
            } else if(j == users.size() && user_pin != users.at(j).get_pin() ){
                cout << "you moron" << endl;
                exit(0);
            } else{
                continue;
            }

        }

    }
};
