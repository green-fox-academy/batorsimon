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

using namespace std;

class TempGen{
    private:
        int temp;

    public:
        void set_temp(int temp){
            this->temp = temp;
        }

        int get_temp(){
            return temp;
        }

};

class Celsius{

};

class Fahrenheit{

};

class Kelvin{

};

int main()
{
    srand(time(NULL));

    TempGen tn;
    tn.set_temp(rand() % 20 - 10);
    cout <<  tn.get_temp() << endl;


    return 0;
}
