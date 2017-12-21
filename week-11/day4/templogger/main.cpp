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

void starting_screen();
void user_input();
void logger(string x, unsigned int a, string y);

int main()
{
    srand(time(NULL));
    starting_screen();
    user_input();

    cout << "End of the program. You can check the created file in the same folder." << endl;
    return 0;
}


void starting_screen(){
    cout << "___________                                        __                        " << endl;
	cout << "\\__    ___/___   _____ ______   ________________ _/  |_ __ _________   ____  " << endl;
	cout << "  |    |_/ __ \\ /     \\\\____ \\_/ __ \\_  __ \\__  \\\\   __\\  |  \\_  __ \\_/ __ \\ " << endl;
	cout << "  |    |\\  ___/|  Y Y  \\  |_> >  ___/|  | \\// __ \\|  | |  |  /|  | \\/\\  ___/ " << endl;
	cout << "  |____| \\___  >__|_|  /   __/ \\___  >__|  (____  /__| |____/ |__|    \\___  >" << endl;
	cout << "             \\/      \\/|__|        \\/           \\/                        \\/ " << endl;
	cout << "              .____                                                          " << endl;
	cout << "              |    |    ____   ____   ____   ___________                     " << endl;
	cout << "              |    |   /  _ \\ / ___\\ / ___\\_/ __ \\_  __ \\                    " << endl;
	cout << "              |    |__(  <_> ) /_/  > /_/  >  ___/|  | \\/                    " << endl;
	cout << "              |_______ \\____/\\___  /\\___  / \\___  >__|                       " << endl;
	cout << "                      \\/    /_____//_____/      \\/                           " << endl << endl;

    cout << "Welcome to my temperature logger" << endl;
    cout << "Usage: give in 3 parameters: " << endl;
    cout << "Firstly the date. Enter it with . separators. E.g.: 2017.12.21." << endl;
    cout << "Secondly how many days you want to get the temperatures. It should be between 1 and 30." << endl;
    cout << "Thirdly the name of the file you want to write the temperatures." << endl;

    cout << "So lets start it!!\n" << endl;

}

void user_input(){

    string user_input_date;
    unsigned int user_input_days;
    string user_input_file_name;

    cout << "Enter the date: ";
    cin >> user_input_date;

    // token !!!
    // token !!!
    if(!cin){
        cout << "Please give in a valid date." << endl;
         cin.clear();
    }

    cout << "Enter the number of days: ";
    cin >> user_input_days;
    if(!cin || user_input_days > 30 || user_input_days < 1){
        cout << "Please give in a valid number: ";
        cin.clear();
        cin >> user_input_days;
    }

    cout << "Enter the file name: ";
    cin >> user_input_file_name;
// try catch
    logger(user_input_date, user_input_days, user_input_file_name);

}

void logger(string x, unsigned int a, string y){

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

    for(unsigned int i = 0; i < a; i++){
        outfile << "The " << i+1 << ". day temperatures: " << endl;
        outfile << "-----------------------------" << endl;

        for(unsigned int j = 0; j < 24; j++){
        outfile << "The temperature at the " << j << ". hour:" << endl;

        tn.set_temp(rand() % 20 - 10);  //outfile << "The temperature: " << tn.get_temp() << endl;

        cs.set_temp(tn.get_temp());
        outfile << "The temperature in Celsius: " << cs.get_temp() << endl;

        ft.set_temp(tn.get_temp());
        outfile << "The temperature in Fahrenheit: " << ft.get_temp() << endl;

        kn.set_temp(tn.get_temp());
        outfile << "The temperature in Kelvin: " << kn.get_temp() << endl << endl;
        }
    }

    outfile.close();

}
