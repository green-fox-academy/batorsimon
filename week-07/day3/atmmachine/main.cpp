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

        void main_menu();

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

};


void Users::main_menu() {
    string user_name;
    string user_pin;

    cout << " Please log in: " << endl;
    cout << " Enter your user name: ";
    cin >> user_name;
    cout << " Enter your PIN code: ";
    cin >> user_pin;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < users.size(); j++ ){
            if(user_name == users(j).name && user_pin == users(j).pin ) {
                if(users.admin == 1){
                        Administrator.administratormenu();
                    } else if(users.admin == 0){
                        Costumer.costumermenu();
                    } else {
                        cout << "Wrong login!!" << endl;
                        exit(0);
                    }
            }
        }

    }


}

class Costumer : public Users{
    private:
        vector<Users> costumer;
        int costumer_money;

    public:
        void withdraw_money();
        void get_richest();
        void costumer_menu();
        void costumer_commands();
        void check_balance();
        void print_balance();

        void set_costumermoney(int costumer_money){
            this->costumer_money = costumer_money;
        }
        int get_costumermoney(){
            return costumer_money;
        }

};

void Costumer::costumer_menu() {
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
}

void Costumer::costumer_commands() {
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
            withdraw_money();

        } else if (command == "check") {
            check_balance();

        } else if (command == "print") {
            print_balance();

        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (command != "exit");
}

void Costumer::withdraw_money() {

}

void Costumer::check_balance() {

}

void Costumer::print_balance() {

}



class Administrator : public Users{
    private:
        vector<Users> administrator;
        string user_name;
        string password;
    public:
        void load_up();
        void administrator_menu();
        void administrator_commands();

};

void Administrator::administrator_menu() {
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
}

void Administrator::administrator_commands() {
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

void Administrator::load_up() {

}


int main()
{
    Users u;
    u.main_menu();

    Atm ATM;
    ATM.add(new Users("Kiss Balazs", 1234, 2342342, 0));
    ATM.add(new Users("John Wick", 4444, 235662, 0));
    ATM.add(new Users("Pamela Anderson", 5555, 2964542, 0));
    ATM.add(new Users("Brave Simon", 8888, 123456543, 1));
    ATM.add(new Users("Elon Musk", 7777, 2634543, 0));

    return 0;
}
