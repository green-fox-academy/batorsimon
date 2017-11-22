#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

class Users{
    public:
        Users() {}
        Users(string name, int pin, int balance, bool admin) {
            this->name = name;
            this->pin = pin;
            this->balance = balance;
            this->admin = admin;
        };

        void set_name(){
            this->name = name;
        }
        string get_name(){
            return name;
        }

        void set_pin(int pin){
            this->pin = pin;
        }
        int get_pin(){
            return pin;
        }

        void set_balance(int balance){
            this->balance = balance;
        }
        int get_balance(){
            return balance;
        }

        int get_admin(){
            return admin;
        }

     private:
        string name;
        int pin;
        int balance;
        bool admin;

};

class Atm{
    private:
        int huszezer = 20000;
        int tizezer = 10000;
        int otezer = 5000;
        int ketezer = 2000;
        int ezer = 1000;
        int atm_money;
        vector<Users> users;

    public:
        Atm() {};
        Atm(int atm_money){
            this->atm_money = atm_money;
        };

        void add(Users *user) {
            users.push_back(*user);
        };

        int get_huszezer(){
            return huszezer;
        }
        int get_tizezer(){
            return tizezer;
        }
        int get_otezer(){
            return otezer;
        }
        int get_ketezer(){
            return ketezer;
        }
        int get_ezer(){
            return ezer;
        }

        void set_atmmoney(int atm_money){
            this->atm_money = atm_money;
        }
        int get_atmmoney(){
            return atm_money;
        }

        void main_menu();

        void costumer_menu();
        void costumer_commands();
        void withdraw_money();
        void print_balance();
        void check_balance();

        void administrator_menu();
        void administrator_commands();
        void load_up();

};


void Atm::main_menu() {
    string user_name;
    int user_pin;

    cout << " Please log in: " << endl;
    cout << " Enter your user name: ";
    getline(cin, user_name);
    cout << " Enter your PIN code: ";
    cin >> user_pin;

    int i = 0;
    for(unsigned int j = 0; j < users.size(); j++ ){
        if(user_name == users.at(j).get_name() && user_pin == users.at(j).get_pin() && users.at(j).get_admin() == 1) {
            administrator_menu();
            cout << "jeee";
        } else if(user_name == users.at(j).get_name() && user_pin == users.at(j).get_pin() && users.at(j).get_admin() == 0) {
            costumer_menu();
            cout << "neee";
        } else {
            cout << "Wrong login!!" << endl;
        }
    }

}

void Atm::costumer_menu() {
    system("cls");
    cout << "-------------------------------------------" << endl;
    cout << "|        Welcome to Brave Bank            |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "| Commands:                               |" << endl;
    cout << "| wm      withdraw money                  |" << endl;
    cout << "| check   shows your current balance      |" << endl;
    cout << "| print   print out your balance          |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "| menu  Opens the main menu               |" << endl;
    cout << "| exit  Exiting from the program          |" << endl;
    cout << "-------------------------------------------" << endl;
    system("pause");
    system("cls");

    costumer_commands();
}

void Atm::costumer_commands() {
    string command;

    do {
        cin >> command;
        if (command == "exit") {
            cout << "The program is exiting now. Goodbye!" << endl;
            exit(0);
        } else if (command == "menu") {
            costumer_menu();
            continue;
        } else if(command == "wm"){
            //withdraw_money();
            continue;
        } else if (command == "check") {
            //check_balance();
            continue;
        } else if (command == "print") {
            //print_balance();
            continue;
        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (command != "exit");
}

void Atm::withdraw_money() {

}

void Atm::check_balance() {

}

void Atm::print_balance() {

}



void Atm::administrator_menu() {
    system("cls");
    cout << "------------------------------------------" << endl;
    cout << "|        Welcome to Brave Bank           |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| Logged in as administrator             |" << endl;
    cout << "| Commands:                              |" << endl;
    cout << "| up     upload money                    |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| menu  Opens the main menu              |" << endl;
    cout << "| exit  Exiting from the program         |" << endl;
    cout << "------------------------------------------" << endl;
    system("pause");
    system("cls");

    administrator_commands();
}

void Atm::administrator_commands() {
    string command;

    do {
        cin >> command;
        if (command == "exit") {
            cout << "The program is exiting now. Goodbye!" << endl;
            exit(0);
        } else if (command == "menu") {
            administrator_menu();
            continue;
        } else if(command == "up"){
            //load_up();

        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (command != "exit");


}

void Atm::load_up() {

}


int main()
{
    Atm ATM;

    ATM.add(new Users("Kiss", 1234, 2342342, 0));
    ATM.add(new Users("John", 1234, 235662, 0));
    ATM.add(new Users("Pamela", 1234, 2964542, 0));
    ATM.add(new Users("Brave", 1234, 123456543, 1));
    ATM.add(new Users("Elon", 1234, 2634543, 0));

    ATM.main_menu();

    return 0;
}
