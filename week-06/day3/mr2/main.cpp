#include <iostream>

using namespace std;

/**
 * A Vehicle can move
 */
class Vehicle {
    public:
        virtual void move() = 0;
};

/**
 * The petrolicious vehicle:
 *   - can move a loud
 */
class PetroliciousVehicle: public Vehicle {
    public:
        void move() {
            cout << "OK, starting V8, WWWRRRRRMMM!!!" << endl;
        }
};

/**
 * An ElectricVehicle:
 *  - can move silently
 *  - can tell the current consumption
 *  - has consumptionWatts
 */
class ElectricVehicle: public Vehicle {
    public:
        int consumptionWatts;

        void move() {
            cout << "Silently going away...sssshhhh..." << endl;
        }

        int getCurrentWattsConsumption() {
            return 12;
        }
};

/**
 * An EAuto:
 *  - can move
 *  - has consumption
 *  - has range
 */
class EAuto: public ElectricVehicle {
    public:
        int range;
};

/**
 * An Tesla:
 *  - can move
 *  - has consumption
 *  - has range
 *  - has autopilot
 */
class Tesla: public EAuto {
    public:
        void startAutopilot() {
            cout << "OK, lay back and trust me!" << endl;
        }

        int getCurrentWattsConsumption() {
            return 1;
        }
};

/**
 * My function doesn't care what kind of vehicle you have, it's can move everything
 * which is a Vehicle!
 */
void move_vehice(Vehicle *vehicle) {
    vehicle->move();
}

int main() {

    // Vehicle vehicle; <- does not work, as it's an abstract class, which is missing implementation (pure virtual function)

    cout << ">>>> Simply instantiate different objects and check their properties! <<<<" << endl << endl;

    // Check that this object has everything that Vehicle and ElectricVehicle have
    EAuto ea;
    ea.consumptionWatts = 100;
    ea.range = 230;


    cout << "The EAuto..." << endl;
    cout << "\t can move: ";
    ea.move();
    cout << "\t can tell the current consumption: " << ea.getCurrentWattsConsumption() << " watts" << endl;
    cout << "\t has consumption: " << ea.consumptionWatts << " watts" << endl;
    cout << "\t has range: " << ea.range << " km" << endl << endl;

    // Check that this object can only move on it's own way
    PetroliciousVehicle pv;
    cout << "The PetroliciousVehicle..." << endl;
    cout << "\t can move: ";
    pv.move();
    cout << endl << endl;


    cout << ">>>> Let's inspect the virtual keyword a bit! <<<<" << endl << endl;

    cout << "\tEAuto has consumption (watts): " << ea.getCurrentWattsConsumption() << " watts" << endl;
    ElectricVehicle *v = &ea;
    cout << "\tEAuto as ElectricVehicle* has consumption: " << v->getCurrentWattsConsumption() << " watts" << endl;
    cout << endl;

    Tesla t;
    cout << "\tTesla has consumption (watts): " << t.getCurrentWattsConsumption() << " watts" << endl;
    v = &t;

    /**
     * OOPS: this is unexpected! The following is not the tesla's implementation!
     *
     * Explanation: the method first defined in ElectricVehicle class, and doesn't have the
     * virtual keyword. In this case the method will be resolved by reference and not by the object.
     *
     * In the following example we're calling Tesla's getCurrentConsumption() method through an
     * ElectricVehicle* pointer, so the implementation on the ElectricVehicle will be invoked.
     *
     * If we would use the virtual keyword (like in the case of move() method), this would invoke the
     * Tesla's implementation.
     */
    cout << "\tTesla as ElectricVehicle* has consumption: " << v->getCurrentWattsConsumption() << " watts" << endl;
}
