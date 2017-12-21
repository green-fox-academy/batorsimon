/* Készíts egy aplikációt, ami temperature loggert imitál.
Legyen egy temperature generátor õsosztály. Ez tud random alapon hõmérsékletet generálni.
Dátum alapján az aznapi középhõmérséklet körül valamekkora (-10, +10) szórással. Ebbõl leszármazik 3,
 ami megvalósítja ezeket. Celsius, Kelvin és Fahrenheit fokokra.
Legyen egy logger ami ezeket hívja, kap tõle számot és kiírja fileba.
A program induljon úgy, hogy 3 parametert kap a command lineon.
Egy datumot es, hogy hany naponyi  adatot generaljin. Egy nap 24 random adatot taroljon.
A 3. Parameter a file neve amibe berakja  */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

class TempGen{
    protected:
        float temp;

    public:
        void set_temp(float temp){
            this->temp = temp;
        }

        float get_temp(){
            return temp;
        }

};

class Celsius: public TempGen{
public:
      void set_temp(float temp){
            this->temp = temp;
        }

        float get_temp(){
            return temp;
        }
};

class Kelvin: public TempGen{
public:
     void set_temp(float temp){
            this->temp = temp + 273.15;
        }

        float get_temp(){
            return temp;
        }
};

class Fahrenheit: public TempGen{
public:
     void set_temp(float temp){
            this->temp = temp * 1.8000 + 32.00;
        }

        float get_temp(){
            return temp;
        }
};

void user_input();
void logger(string x, int a, string y);

int main()
{
    srand(time(NULL));
    user_input();

    return 0;
}

void user_input(){

    string user_input_date;
    int user_input_days;
    string user_input_file_name;

    cout << "Give in 3 parameters: " << endl << "Firstly the date without separation." << endl;
    cout << "Secondly how many days you want to get the temperatures." << endl;
    cout << "Thirdly the name of the file you want to write the temperatures. \n" << endl;

    cin >> user_input_date;
    if(!cin){
        cout << "Please give in a valid date." << endl;
         cin.clear();
    }

    cin >> user_input_days;
    if(!cin){
        cout << "Please give in a valid number." << endl;
         cin.clear();
    }


    cin >> user_input_file_name;
     if(!cin){
        cout << "Please give in a valid file name." << endl;
         cin.clear();
    }

    logger(user_input_date, user_input_days, user_input_file_name);

}

void logger(string x, int a, string y){

    TempGen tn;
    Celsius cs;
    Fahrenheit ft;
    Kelvin kn;

    time_t now = time(0);
    char* dt = ctime(&now);

    string file_name = y + ".txt";
    ifstream infile;
    ofstream outfile;
    outfile.open(file_name.c_str());

    outfile << "The given date: " << x <<endl;
    outfile << "The given number of days: " << a <<endl;
    outfile << "The request were made at: " << endl << dt << endl;
    outfile << "-----------------------------" << endl;

    for(unsigned int i = 0; i < (a*24); i++){
        tn.set_temp(rand() % 20 - 10);
        outfile << "The temperature in Fahrenheit: " << tn.get_temp() << endl;

        cs.set_temp(tn.get_temp());
        outfile << "The temperature in Celsius: " << cs.get_temp() << endl;

        ft.set_temp(tn.get_temp());
        outfile << "The temperature in Fahrenheit: " << ft.get_temp() << endl;

        kn.set_temp(tn.get_temp());
        outfile << "The temperature in Kelvin: " << kn.get_temp() << endl;
    }

    outfile.close();

}
