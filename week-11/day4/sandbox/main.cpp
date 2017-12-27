#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

void date_error_handling(string date);

int main()
{
    string user_input_date = "2016.02.29.";
    cout << user_input_date << endl << endl;

    date_error_handling(user_input_date);

     /*
    while ((pos = user_input_date.find(delimiter)) != std::string::npos) {
        token = user_input_date.substr(0, pos);
        cout << token << endl;
        user_input_date.erase(0, pos + delimiter.length());
    }
    cout << "Tokenized." << endl << endl;
    */


    // day == 28 nem szoköév
    // day == 29 szökõév


    return 0;
}

void date_error_handling(string date){
    string user_input_date = date;
    int year = 0;
    int mounth = 0;
    int day = 0;
    int error = 0;
    string delimiter = ".";
    size_t pos = 0;
    string token;

    pos = user_input_date.find(delimiter);
    while (pos != std::string::npos) {
        token = user_input_date.substr(0, pos);
        year = atoi(token.c_str());

        if(year > 2017 || year < 1990){
            error++;
            break;
        } else {
            cout << "year: " << year << endl;
            user_input_date.erase(0, pos + delimiter.length());
            break;
        }

    }

    pos = user_input_date.find(delimiter);
    while (pos != std::string::npos) {
        token = user_input_date.substr(0, pos);
        mounth = atoi(token.c_str());

        if(mounth < 13 && mounth > 0){
             cout << "mounths: " << mounth << endl;
            user_input_date.erase(0, pos + delimiter.length());
            break;
        } else {
            error++;
            break;
        }

    }

    pos = user_input_date.find(delimiter);
    while (pos != std::string::npos) {
        token = user_input_date.substr(0, pos);
        day = atoi(token.c_str());

        if(mounth == 2 && day > 29 && (year == 1992 || year == 1996 || year == 2000 || year == 2004 || year == 2008 || year == 2012 || year == 2016)) {
            cout << "Invalid date. Even it's a Leap year, February only can be 29 days long." << endl;
            error++;
            break;

        } else if(mounth == 2 && day > 0 && day < 30 && (year == 1992 || year == 1996 || year == 2000 || year == 2004 || year == 2008 || year == 2012 || year == 2016)) {
            cout << "day: " << day << endl;
            user_input_date.erase(0, pos + delimiter.length());
            break;

        } else if(mounth == 2 && day > 28 && (year != 1992 || year != 1996 || year != 2000 || year != 2004 || year != 2008 || year != 2012 || year != 2016)) {
            cout << "Invalid date. It's not a Leap year. February only can be 28 days long." << endl;
            error++;
            break;

        } else if(mounth == 2 && day < 29 && day > 0 && (year != 1992 || year != 1996 || year != 2000 || year != 2004 || year != 2008 || year != 2012 || year != 2016)) {
            cout << "day: " << day << endl;
            user_input_date.erase(0, pos + delimiter.length());
            break;

        } else if(day < 32 && day > 0){
            cout << "day: " << day << endl;
            user_input_date.erase(0, pos + delimiter.length());
            break;

        } else {
            error++;
            break;
        }

    }

    if(year ==0 || mounth == 0 ||day == 0){
        error++;
    }

    if(error > 0){
        cout << "Invalid date. Try it again!" << endl;
    }

};
