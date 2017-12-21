/* K�sz�ts egy aplik�ci�t, ami temperature loggert imit�l.
Legyen egy temperature gener�tor �soszt�ly. Ez tud random alapon h�m�rs�kletet gener�lni.
D�tum alapj�n az aznapi k�z�ph�m�rs�klet k�r�l valamekkora (-10, +10) sz�r�ssal. Ebb�l lesz�rmazik 3,
 ami megval�s�tja ezeket. Celsius, Kelvin �s Fahrenheit fokokra.
Legyen egy logger ami ezeket h�vja, kap t�le sz�mot �s ki�rja fileba.
A program induljon �gy, hogy 3 parametert kap a command lineon.
Egy datumot es, hogy hany naponyi  adatot generaljin. Egy nap 24 random adatot taroljon.
A 3. Parameter a file neve amibe berakja  */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void logger();

int main()
{
    srand(time(NULL));

    TempGen tn;
    Celsius cs;
    Fahrenheit ft;
    Kelvin kn;
/*
    tn.set_temp(rand() % 20 - 10);
    cout <<  tn.get_temp() << endl;

    cs.set_temp(tn.get_temp());
    cout <<  cs.get_temp() << endl;

    ft.set_temp(tn.get_temp());
    cout <<  ft.get_temp() << endl;

    kn.set_temp(tn.get_temp());
    cout <<  kn.get_temp() << endl;
*/
    user_input();
    logger();

    return 0;
}

void user_input(){

}

void logger(){

}
