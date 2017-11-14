#include "Pirate.h"

Pirate::Pirate(int counter)
{
  this->counter = counter;
}

Pirate::~Pirate()
{
    cout << endl << "Drink anouther one!!" << endl;
}

void Pirate::drink_rum()
{
    counter++;
}

void Pirate::run()
{
    for(int i = 0; i < counter; i++){
        drink_rum();
    }
}

const char* Pirate::hows_goin_mate()
{
    if(counter >= 5){
        return "Arrrr!";
    } else{
        return "Nothin'  ";
    }
}
