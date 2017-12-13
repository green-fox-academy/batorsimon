#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED

#include "users.h"

#include <string>
#include <vector>

using namespace std;

class Atm{
    private:
        double atm_money;
        vector<Users> users;
         int fault = 0;

    public:
        Atm();
        Atm(double atm_money);

        ~Atm();
        void add(Users *user);
        void set_atmmoney(double atm_money);
        int get_atmmoney();

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

        int get_fault();

};


#endif // ATM_H_INCLUDED
