#include <string>

using namespace std;

#include "users.h"

Users::Users() {};

Users::Users(string name, int pin, int balance, bool admin) {
    this->name = name;
    this->pin = pin;
    this->balance = balance;
    this->admin = admin;
};

void Users::set_name(){
    this->name = name;
}

string Users::get_name(){
    return name;
}

void Users::set_pin(int pin){
    this->pin = pin;
}

int Users::get_pin(){
    return pin;
}

void Users::set_balance(int balance){
    this->balance = balance;
}

int Users::get_balance(){
    return balance;
}

int Users::get_admin(){
    return admin;
}
