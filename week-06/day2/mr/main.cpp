#include <iostream>

using namespace std;

//namespace dinamikusan huzogatja be amire sz��ks�ge van

class BankAcc{
public:
    int pin_code;
    float money;

    BankAcc(int pin_code, float money){
        this->pin_code = pin_code;
        this->money = money;
        //this szinte egy pointer ami a classon k�v�lre mutat
    }

    void print_data(){
        cout << "My pin is " << pin_code << " and I have " << money << " forint." << endl;
    }

};

int main()
{
    BankAcc ba(1234, 33.33);
    ba.print_data();

    ba.money = 100;
    ba.print_data();

    return 0;
}
