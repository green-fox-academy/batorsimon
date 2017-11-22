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
        int costumer_money;
        int atm_money;
    public:
        Atm() {};
        Atm(int costumer_money, int atm_money){
            this->costumer_money = costumer_money;
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
        void set_costumermoney(int costumer_money){
            this->costumer_money = costumer_money;
        }
        int get_costumermoney(){
            return costumer_money;
        }
        void set_atmmoney(int atm_money){
            this->atm_money = atm_money;
        }
        int get_atmmoney(){
            return atm_money;
        }

};

class Costumer : public Atm{
    private:
        vector<Atm> Costumer;
        // Costumer c;
    public:
        int withdraw(int a);
        string login(string x);
        store_people();
        get_richest();
        void menu();
        void commands();
};

class Administrator : public Atm{
    private:

    public:
        load_up();
        logging();
};

void Costumer::menu() {
    system("cls");
    cout << "------------------------------------------" << endl;
    cout << "|        Welcome to Brave Bank           |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| Commands:                              |" << endl;
    cout << "| wm     withdraw money                  |" << endl;
    cout << "| check  checks your current balance     |" << endl;
    cout << "| print  prints a recipe of your balance |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| menu  Opens the main menu              |" << endl;
    cout << "| exit  Exiting from the program         |" << endl;
    cout << "------------------------------------------" << endl;
    system("pause");
    system("cls");
}

void Costumer::commands() {
string command;

    do {
        cin >> command;
        if (command == "exit") {
            cout << "The program is exiting now. Goodbye!" << endl;
            exit(0);
        } else if (command == "menu") {
            menu();
            continue;
        } else if(command == "wm"){
            //new_task();

        } else if (command == "check") {
            // Costumer c;
            //cout << "The money the costumer have: " << c.get_costumermoney() << endl;

        } else if (command == "print") {
            //read_from_file

        } else if (command == "administrator") {
           cout << "logging in as administrator" << endl;

        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (command != "exit");


}


void Administrator::load_up() {

}

void Administrator::logging() {

}

int main()
{
    Costumer c;
    /*
    c.set_atmmoney(20000000);
    c.set_costumermoney(200000);
    cout << "The money in the ATM: " << c.get_atmmoney() << endl;
    cout << "The money the costumer have: " << c.get_costumermoney() << endl;
    */
    c.menu();
    c.commands();
    return 0;
}
