#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <ctime>

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
            this->atm_money = atm_money;
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

        void main_menu();

        void costumer_menu(string x);
        void costumer_commands(string x);
        void withdraw_money(string x);
        void check_balance(string x);
        void print_balance(string x);

        void administrator_menu(string x);
        void administrator_commands(string x);
        void load_up();
        void check_atm();
        void print_atmBalance(string x);

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
            } else if(user_name == users.at(j).get_name() && user_pin != users.at(j).get_pin() && users.at(j).get_admin() == 0 && fault < 3){
                fault++;
                continue;
            } else if(j == users.size()-1 && user_pin != users.at(j).get_pin() ){
                cout << "you moron" << endl;
                exit(0);
            } else{
                continue;
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
            break;

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
    outfile.open("probe.txt");

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


int main()
{
    Atm ATM;

    ATM.add(new Users("Kiss", 1234, 234256, 0));
    ATM.add(new Users("John", 1234, 235662, 0));
    ATM.add(new Users("Pamela Anderson", 1234, 2964542, 0));
    ATM.add(new Users("Brave", 12345678, 0, 1));
    ATM.add(new Users("Admin", 12345678, 0, 1));
    ATM.add(new Users("Elon", 1234, 2634543, 0));

    ATM.main_menu();

    return 0;
}
