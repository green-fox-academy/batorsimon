#include <iostream>

using namespace std;

int main()
{
    string name = "Kiss Balazs";
    int pin = 1234;
    bool admin = 0;

    string user_name;
    int user_pin;

    cout << " Please log in: " << endl;
    cout << " Enter your user name: ";
    getline(cin, user_name);
    cout << " Enter your PIN code: ";
    cin >> user_pin;

    int i = 0;
        if(user_name == name && user_pin == pin) {
            if(admin== 1){
                administrator_menu();
            } else {
                cout << "Wrong login!!" << endl;
                exit(0);
            }

            if(users.at(j).get_admin() == 0){
                costumer_menu();
            } else {
                cout << "Wrong login!!" << endl;
                i++;
                if(i < 3){
                    continue;
                } else {
                    exit(0);
                }

            }

        } else{
            cout << "noo" << endl;
        }

    }
}
