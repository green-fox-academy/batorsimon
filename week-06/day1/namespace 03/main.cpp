#include <iostream>

// Use your costume namespace from the last exercise
// Create a function, which takes the age as a parameter
// and returns the year when you were born

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

using namespace Person;

int returning(int age)
{
    int year = (2017 - age);
    return year;
}

int main()
{
    func();

    int year_main = returning(age);
    cout << "The year i was born in: " << year_main <<endl;
    return 0;
}
