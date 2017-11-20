#include <iostream>
#include <time.h>
using namespace std;

    /*
    do{
    do {
        cout << "Type in your username: ";
        getline(cin, user_name);
        error_handling(user_name, finished1);
    } while(finished1 == false);
    continue;
    do {
        cout << "Type in your password: ";
        getline(cin, password);
        error_handling(password, finished2);
    } while(finished2 == false);

    }  while(user_name != password);

    */

    /*
void user_input(string x){
    cout << "Type in your " << x << " : " << endl;
    getline(cin, x);
}
*/

int main(){
    string user_name;
    string password;
    bool finished1 = false;
    bool finished2 = false;

     do {
        cout << "Type in your username: " << endl;
        getline(cin, user_name);
        if(user_name.length() < 5){
            cout << "username is too short" << endl;
        } else if (user_name.length() > 30){
            cout << "username is too long" << endl;
        } else{
            finished1 == true;
        }

        cout << "Type in your password: " << endl;
        getline(cin, password);
         if(password.length() < 5){
            cout << " is too short" << endl;
        } else if(password.length() > 30){
            cout << "is too long" << endl;
        } else{
            finished2 == true;
        }
    } while(finished1 == false && finished2 == false && user_name == password);

    if(finished1 && finished2){
        time_t now = time(0);
        char *dt = ctime(&now);
        cout << "Successful registration at: " << dt;
    }

    return 0;
}
