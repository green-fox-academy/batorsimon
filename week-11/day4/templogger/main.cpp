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
