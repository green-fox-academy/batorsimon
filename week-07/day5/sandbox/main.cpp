#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    int b = 32342322;
    cout << "Your balance: " << b << endl;
    cout << "Write down how much money you need: " << endl;
    int a;
    cin >> a;

    while(isdigit(a)){
        if(!cin){
            cout << "not a number" << endl;
            break;
        } else if(a % 1000 == 0){
            if(b > a) {
                b = b - a;
                cout << b;
                break;
            } else {
                cout << "You do not have enough money." << endl;
                break;
            }

        } else{
            cout << "You can withdraw only valid banknotes! " << endl;
            break;
        }

    }
    return 0;
}
