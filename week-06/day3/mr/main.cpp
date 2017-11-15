#include <iostream>

using namespace std;

class vehicle{
    public:
        void move() {
            cout << " Vehicle is moving!" << endl;
        }

    protected:
        int protectedint;

    private:
        int privateint;

};

class ElectricVehicle: public vehicle{
    public:
        int consumtion;
        void move() {
            cout << "Silently going away...." << endl;
        }

};

class EAuto: public ElectricVehicle{
    public:
        int range;
};

class Tesla: public ElectricVehicle{
public:
    void sautopilot();
};


int main()
{
    vehicle v;
    v.move();

    EAuto ea;
    ea.consumtion = 12;
    ea.range = 200;

    cout << "EA properities" << endl;
    ea.move();
    cout << " - has consumation: " << ea.consumtion << endl;
    cout << " - has range: " << ea.range << endl;

    return 0;
}
