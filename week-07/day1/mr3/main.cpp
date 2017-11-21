#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main(){
    string user_name;
    string password;
    bool finished1 = false;
    bool finished2 = false;
    while(1) {
        cout << "Type in your username: ";
        getline(cin, user_name);
        if(user_name.length() < 5){
            cout << "username too short" << endl;
            finished1 = false;
        } else if(user_name.length() > 30) {
            cout << "username is too long" << endl;
            finished1 = false;
        } else{
            finished1 = true;
        }
        cout << "Type in your password: ";
        getline(cin, password);
        if(password.length() < 5){
            cout << "password too short" << endl;
            finished2 = false;
        } else if(password.length() > 30) {
            cout << "password is too long" << endl;
            finished2 = false;
        } else {
            finished2 = true;
        }
        if(user_name == password){
            cout << "user_name equals password" << endl;
            continue;
        }
        if(finished1 == true && finished2 == true) {
            time_t now = time(0);
            char *dt = ctime(&now);
            cout << "Successful registration at: " << dt;
            break;
        } else{
            Sleep(1500);
            system("cls");
            continue;
        }
    }

    return 0;
}
