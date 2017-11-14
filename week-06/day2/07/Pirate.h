#ifndef PIRATE_H
#define PIRATE_H
#include <iostream>

using namespace std;

class Pirate
{
    public:
        Pirate(int counter);
        virtual ~Pirate();
        void drink_rum();
        const char* hows_goin_mate();
        void run();

    protected:

    private:
        int counter;
};

#endif // PIRATE_H
