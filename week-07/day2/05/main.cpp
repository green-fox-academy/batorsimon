#include <iostream>

using namespace std;

// Take the Integer class from the previous exercise.
// Create 3 constructors for them:
// One empty which sets the member varibale to 0;
// A copy constructor, that takes an Integer& argument
// A third one which takes an int as argument and makes the member variable equal to the int it took.
//
// Write code that uses these and prints out the value of the member variable of the integers created.
// (You will have to create a get method to do this appropriately.)

class Intreger{
    private:
        int member;
    public:
        Intreger() { member = 0; }
        Intreger(Intreger& obj) : member(obj.member) { }
        Intreger(int member) : member(member){ }

        int get(){
            return member;
        }
};

int main() {
    Intreger a;
    cout << a.get() << endl;

    Intreger b(4);
    cout << b.get() << endl;

    Intreger c(11);
    cout << c.get() << endl;

	return 0;
}
