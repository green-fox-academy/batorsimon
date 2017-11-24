#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;
int fault = 0;

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
        double atm_money;
        vector<Users> users;

    public:
        Atm() {};
        Atm(double atm_money){
            this->atm_money = 2000000;
        };

        void add(Users *user) {
            users.push_back(*user);
        };

        void set_atmmoney(double atm_money){
            this->atm_money = atm_money;
        }
        int get_atmmoney(){
            return atm_money;
        }

        string main_menu();

        void costumer_menu(string x);
        void costumer_commands(string x);
        void withdraw_money(string x);
        void check_balance(string x);

        void administrator_menu(string x);
        void administrator_commands(string x);
        void load_up();
        void check_atm();

};


string Atm::main_menu() {

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
                return user_name;
            } else if(user_name == users.at(j).get_name() && user_pin == users.at(j).get_pin() && users.at(j).get_admin() == 0) {
                costumer_menu(user_name);
                return user_name;
            } else if(user_name == users.at(j).get_name() && user_pin != users.at(j).get_pin() && users.at(j).get_admin() == 0 && fault < 3){
                fault++;
                continue;
            } else{
                cout << "you moron22" << endl;
                string x = "Wrong login flag 2";
                return x;
            }

        }
    }
}

void Atm::costumer_menu(string x) {
    system("cls");
    cout << "-------------------------------------------" << endl;
    cout << "|        Welcome to Brave Bank            |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "| Commands:                               |" << endl;
    cout << "| wm      withdraw money                  |" << endl;
    cout << "| check   shows your current balance      |" << endl;
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

    unsigned int i = 0;
    for(unsigned int i = 0; i < users.size(); i++){
        if(users.at(i).get_name() == x){
            //cout << "i: " << i << endl;
        }
    }

    while(1){
        if(!cin){
            cout << "You can put in only numbers!" << endl;
            cin.clear();
            break;
        } else if(a % 1000 == 0 && users.at(i).get_balance() > a){
                b = (users.at(i).get_balance() - a);
                users.at(i).set_balance(b);
                break;
        } else{
            cout << "Invalid operation. " << endl;
            break;
        }
    }

}

void Atm::check_balance(string x) {

    for(unsigned int i = 0; i < users.size(); i++){
        if(users.at(i).get_name() == x){
            cout << "Your current balance is: " << users.at(i).get_balance() << endl;
        }
    }

}


void Atm::administrator_menu(string x) {
    system("cls");
    cout << "------------------------------------------" << endl;
    cout << "|        Welcome to Brave Bank           |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| Logged in as administrator             |" << endl;
    cout << "| Commands:                              |" << endl;
    cout << "| up      upload money                   |" << endl;
    cout << "| check   check money                    |" << endl;
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
            continue;
        } else if(command == "up"){
            load_up();

        } else if(command == "check"){
            check_atm();

        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (command != "exit");


}

void Atm::load_up() {

    int a;
    int b;
    //cout << "Write down how much money you want to add: ";
    cin >> a;

    while(1){
        if(!cin){
            cout << "not a number" << endl;
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

    cout << "how much money is in the Atm: ";
    cout << get_atmmoney() << endl;

}


int main()
{
    Atm ATM;

    ATM.add(new Users("Kiss", 1234, 2342, 0));
    ATM.add(new Users("John", 1234, 235662, 0));
    ATM.add(new Users("Pamela", 1234, 2964542, 0));
    ATM.add(new Users("Brave", 1234, 0, 1));
    ATM.add(new Users("Elon", 1234, 2634543, 0));

    ATM.main_menu();

    return 0;
}
