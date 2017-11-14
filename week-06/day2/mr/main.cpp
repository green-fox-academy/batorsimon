#include <iostream>

using namespace std;

//namespace dinamikusan huzogatja be amire szöüksége van

class BankAcc{
private:
    int pin_code;
    float money;

public:
    BankAcc(int pin_code, float money){
        this->pin_code = pin_code;
        this->money = money;
        //this szinte egy pointer ami a classon kívûlre mutat
    }

    void print_data(){
        cout << "My pin is " << pin_code << " and I have " << money << " forint." << endl;
    }

    void set_money(int pin_code, float money){
        if(this->pin_code == pin_code){
            this->money = money;
        } else {
            cout << "Nice try hacker!" << endl;
        }
    }

};

int main()
{
    BankAcc ba(1234, 33.33);
    ba.print_data();

    ba.set_money(123, 1000);
    ba.print_data();

    return 0;
}
