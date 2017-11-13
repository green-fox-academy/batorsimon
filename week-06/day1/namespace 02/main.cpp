#include <iostream>

// Create your own namespace, called Person
// store your name as a string
// your age as an integer
// and your favorite number as an integer
// write them out in main()

using namespace std;

namespace Person {
    string name = "Simon Bator";
    int age = 24;
    int favorite_number = 7;

    void func() {
        cout << "My name: " << name << endl;
        cout << "My age: " << age << endl;
        cout << "My favorite number: " << favorite_number << endl;
   }
}

int main()
{
    Person::func();

    return 0;
}
