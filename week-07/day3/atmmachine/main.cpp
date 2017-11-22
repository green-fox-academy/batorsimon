#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

class Atm{
    private:
        int huszezer = 20000;
        int tizezer = 10000;
        int otezer = 5000;
        int ketezer = 2000;
        int ezer = 1000;
        int atm_money;
    public:
        Atm() {};
        Atm(int atm_money){
            this->atm_money = atm_money;
        }

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

class Users{
    public:
        User(string name, int pinCode, int balance) {
            this->name = name;
        };
        string getName();
        bool matchPin(string pinCode);

        void main_menu();
     private:
        string _name;
        string _pinCode;
        int _balance;

};

void Users::main_menu() {
    /*
    cout << " Please log in: " << endl;
    cout << " Enter your user name: ";
    cin >> username;
    cout << endl;
    cout << " Enter your password: ";
    cin >> password;
    cout << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < sizeof vector<Atm> Costumer; j++ ){
            if (user_name == vector(j).username && password == vector(j).password ) {
                if(Administrator){
                        Administrator.administratormenu();
                    } else if(costumer){
                        Costumer.costumermenu();
                    } else {
                        cout << "Wrong login!!" << endl;
                        exit(0);
                    }
            }
        }

    }
 */
}

class Costumer : public Users{
    private:
        vector<Users> Costumer;
        int costumer_money;
    public:
        int withdraw(int a);
        void get_richest();
        void costumer_menu();
        void costumer_commands();

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
            //new_task();

        } else if (command == "check") {
            // Costumer c;
            //cout << "The money the costumer have: " << c.get_costumermoney() << endl;

        } else if (command == "print") {
            //read_from_file

        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (command != "exit");
}



class Administrator : public Users{
    private:
        vector<Users> Administrator;

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

    return 0;
}
