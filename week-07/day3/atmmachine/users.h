#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

#include <string>

using namespace std;

class Users{
    public:
        Users();
        Users(string name, int pin, int balance, bool admin);

        void set_name();
        string get_name();

        void set_pin(int pin);
        int get_pin();

        void set_balance(int balance);
        int get_balance();

        int get_admin();

     private:
        string name;
        int pin;
        int balance;
        bool admin;

};

#endif // USERS_H_INCLUDED
