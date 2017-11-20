#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

bool error_handling(string x, bool finished){
    while(finished == false){
            if(x.length() > 5 && x.length() < 30){
            return (finished = true);
            }
    }
}

string printing(string x){
    if(x.length() < 5){
        x = "is too short";
        return x;
    } else if(x.length() > 30){
        x = "is too long";
        return x;
    } else {
        return 0;
    }
}

int main(){
    string user_name;
    string password;
    while(1) {
        bool finished1 = false;
        bool finished2 = false;

        cout << "Type in your username: ";
        getline(cin, user_name);
        if(user_name.length() > 5 && user_name.length() < 30){
             finished1 = error_handling(user_name, finished1);
        } else {
            cout << "User name " << printing(user_name) << endl;
        }

        cout << "Type in your password: ";
        getline(cin, password);
        if(user_name.length() > 5 && user_name.length() < 30){
             finished2 = error_handling(user_name, finished2);
        } else {
            cout << "Password " << printing(password) << endl;
        }

        if(user_name == password){
            cout << "user_name equals password" << endl;
            finished1 = false;
        }
        if(finished1 == true && finished2 == true){
            time_t now = time(0);
            char *dt = ctime(&now);
            cout << "Successful registration at: " << dt;
            break;
        } else {
            Sleep(1000);
            system("cls");
        }
    }

    return 0;
}
