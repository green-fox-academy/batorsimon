#ifndef CAR_H
#define CAR_H
#include <iostream>

using namespace std;

class Car
{
    public:
        Car(string type, int km);
        virtual ~Car();
        int run();
        void print();

    protected:

    private:
        string type;
        int km;
        int run_plus;
};

#endif // CAR_H
