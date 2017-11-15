#include <iostream>

using namespace std;

// Create a Car class.
// Create the following private variables : age, kms_runed, manufacturer, number_of_seats
// use proper variable types.
// Implement a method which has one parameter, and increases the kms_runed variable by its parameter value.
// Implement a method which can add a person to a car, if the number of persons in the car reached
// the value of number of seats in the car it should tell you that 'The car is full!' or something like that.
// Inherite at least two car models and try out the methods you have created.

class Car{
public:
    void set_age(int age){
        this->age = age;
    };
    void set_km_runed(int km_runed){
        this->km_runed = km_runed;
    };
    void set_manufacturer(string manufacturer){
        this->manufacturer = manufacturer;
    };
    void set_number_of_seats(int number_of_seats){
        this->number_of_seats = number_of_seats;
    };

    void get_age(){
        cout << "The age of the car is: " << age <<endl;
    };
    void get_km_runed(){
        cout << "The age of the car is: " << km_runed <<endl;
        }
    void get_manufacturer(){
        cout << "The age of the car is: " << manufacturer <<endl;
    }
    void get_number_of_seats(){
        cout << "The age of the car is: " << number_of_seats <<endl;
    }

private:
    int age;
    int km_runed;
    string manufacturer;
    int number_of_seats;
};

int main()
{
    Car c;
    c.set_age(11);
    /*
    c.age = 11;
    c.km_runed = 192500;
    c.manufacturer = "Peugeut";
    c.number_of_seats = 5;
    */
    return 0;
}
