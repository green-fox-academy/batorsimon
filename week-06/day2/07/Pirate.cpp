#include "Pirate.h"

Pirate::Pirate()
{
    //ctor
}

Pirate::~Pirate()
{
    cout << "Drink anouther one!!" << endl;
}


void Pirate::drink_rum()
{
    i++;

}

const char* Pirate::hows_goin_mate()
{
    if(i >= 5){
        return "Arrrr!";
    } else{
        return "Nothin'  ";
    }
}
