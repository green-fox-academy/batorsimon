#include <iostream>

using namespace std;

// Create a class called ParentClass. It should have two public functions. Both return a string. One virtual, the other not.
// Each should return a unique string.
// Create a ChildClass which inherits from the ParentClass publicly.
// This should override both functions. The virtual and the non virtual one both.
// These should return unique string again.
//
// Create a main() function. In this function, create a ParentClass* pointer and instanciate a ChildClass member for that pointer.
// Hint: This should look something like this: ParentClass* a = new ChildClass();
// Print out the result of both functions on this a pointer.
// Print out the result of both functions if You first cast pointer a to be interpreted as of type ChildClass*

class ParentClass{
public:
    char* const func1(){
        return "string111";
    };

    virtual char* const func2(){
        return "string222";
    };

};

class ChildClass: public ParentClass{
    public:
        char* const func1(){
            return "string111new";
        };

        char* const func2(){
            return "string222new";
        };

};
int main()
{
    ParentClass pc;
    ChildClass cc;

    ParentClass* a = new ChildClass();
    cout << "ParentClass* a = new ChildClass()" << endl;
    cout << "The first pointer first : " << a->func1() << endl;
    cout << "The first pointer second : " << a->func2() << endl;

    /*
    cout << endl;
    char* result = a->func1();
    char* result2 = a->func2();
    cout << "ParentClass* a = new ChildClass()" << endl;
    cout << "The first pointer first : " << result << endl;
    cout << "The first pointer second : " << result2 << endl;
    */

    cout << endl;

    cout << "ChildClass* a = new ChildClass() " << endl;
    cout << "The first pointer first : " << ((ChildClass*)a)->func1() << endl;
    cout << "The first pointer second : " <<  ((ChildClass*)a)->func2() << endl;
    delete a;

    return 0;
}
