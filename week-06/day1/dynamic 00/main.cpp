#include <iostream>
#include <string>

using namespace std;

// store your personal data in Variables
// string name, int age, int slice_of_pizza_you_can_eat
// allocate memory dynamically for these variables
// create a sentense using these variables
// free the allocated memory

int main() {

    string *name = NULL;
    int *age = NULL;
    int *slice_of_pizza_i_can_eat = NULL;

    name = new string;
    age = new int;
    slice_of_pizza_i_can_eat = new int;

    *name = "Simon";
    *age = 24;
    *slice_of_pizza_i_can_eat = 10;

    cout << "My name is: " << *name << ". My age is: " << *age << ". The slice_of_pizza_i_can_eat is: " << *slice_of_pizza_i_can_eat << endl;
    delete name;
    delete age;
    delete slice_of_pizza_i_can_eat;

    return 0;
}
