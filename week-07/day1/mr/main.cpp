#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

bool error_handling(string x, bool finished){
    while(finished == false){
        if(x.length() < 5){
            cout << "Type in more than 5 characters" << endl;
            return 0;
        } else if (x.length() > 30){
            cout << "Type in less than 30 characters" << endl;
            return 0;
        } else {
            finished = true;
            return finished;
        }
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
        finished1 = error_handling(user_name, finished1);
        cout << "Type in your password: ";
        getline(cin, password);
        finished2 = error_handling(password, finished2);
        if(user_name == password){
            cout << "user_name equals password" << endl;
            continue;
        }
        if(finished1 == true && finished2 == true){
            time_t now = time(0);
            char *dt = ctime(&now);
            cout << "Successful registration at: " << dt;
            break;
        } else {
            Sleep(3000);
            system("cls");
        }
    }

    return 0;
}
