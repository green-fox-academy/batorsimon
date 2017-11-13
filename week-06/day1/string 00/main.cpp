#include <iostream>

using namespace std;

// Write a program that prints a few details to the terminal window about you
// It should print each detail to a new line.
//  - Your name
//  - Your age
//  - Do you like coffee? (as a boolen variable)
//
//  Example output:
//  John Doe
//  31
//  Likes coffee: true

int main()
{
    string name = "Simon Bator";
    int age = 24;
    bool coffe = true;

    cout << "My name: " << name << endl;
    cout << "My age: " << age << endl;
    cout << "Do I like coffee? " << coffe << endl;

    return 0;
}
