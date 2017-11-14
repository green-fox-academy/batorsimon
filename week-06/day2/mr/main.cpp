#include <iostream>

using namespace std;

//namespace dinamikusan huzogatja be amire szöüksége van

class BankAcc{
public:
    int pin_code;
    float money;

    BankAcc(int given_pin_code, float given_money){
        cout << "I have moneeeey" << endl;
        pin_code = given_pin_code;
        money = given_money;
    }

};

int main()
{
    BankAcc ba(1234, 33.33);

    cout << "My pin is " << ba.pin_code << " and I have " << ba.money << " forint." << endl;

    return 0;
}
