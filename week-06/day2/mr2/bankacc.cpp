#include "bankacc.h"

using namespace std;

bankacc::bankacc(int pin_code, float money)
{
    this->pin_code = pin_code;
    this->money = money;
}

bankacc::~bankacc()
{
    cout << "sms with acc data have been sent" << endl;
}

void bankacc::print_data(){
    cout << "My pin is " << pin_code << " and I have " << money << " forint." << endl;
}

void bankacc::set_money(int pin_code, float money){
    if(this->pin_code == pin_code){
        this->money = money;
    } else {
        cout << "Nice try hacker!" << endl;
    }
}

