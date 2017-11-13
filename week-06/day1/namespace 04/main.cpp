#include <iostream>

// Create your own namespace, called Mark
// store your name as a string
// your age as an integer
// and your favorite number as an integer
//
// Create your own namespace, called Maria
// store your name as a string
// your age as an integer
// and your favorite number as an integer
//
// create a function that can add the two age, and returns it

using namespace std;

namespace Mark {
    string name = "Simon Bator";
    int age = 24;
    int favorite_number = 7;

    void func() {
        cout << "My name: " << name << endl;
        cout << "My age: " << age << endl;
        cout << "My favorite number: " << favorite_number << endl;
    }
}

namespace Maria {
    string name = "Simon Bator";
    int age2 = 24;
    int favorite_number = 7;

    void func() {
        cout << "My name: " << name << endl;
        cout << "My age: " << age2 << endl;
        cout << "My favorite number: " << favorite_number << endl;
    }
}

using namespace Mark;
using namespace Maria;

int returning(int age, int age2)
{
    int add = age + age2;
    return add;
}

int main()
{
    int add_main = returning(age, age2);
    cout << "The years added together: " << add_main<<endl;

    return 0;
}
