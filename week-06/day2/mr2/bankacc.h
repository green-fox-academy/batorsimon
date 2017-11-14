#ifndef BANKACC_H
#define BANKACC_H
#include <iostream>

using namespace std;

class bankacc
{
    public:
        bankacc(int pin_code, float money);
        virtual ~bankacc();
        void print_data();
        void set_money(int pin_code, float money);

    protected:

    private:
        int pin_code;
        float money;
        string name;
};

#endif // BANKACC_H
