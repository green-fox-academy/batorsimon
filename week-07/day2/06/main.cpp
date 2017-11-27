#include <iostream>

using namespace std;

// Take the Integer class from the previous exercise and add two methods:
// One which takes an Integer& parameter and adds the value of it to the member variable of this.
// One which takes an int and adds the value of it to the member variable of this.
//
// Write code which uses them both and Prints out the results respectively.

class Intreger{
    private:
        int member;
    public:
        Intreger() { member = 0; }
        Intreger(Intreger& obj) : member(obj.member) { }
        Intreger(int member) : member(member){ }

        Intreger& add(Intreger& obj1){
             this->member += obj1.member;
             return *this;
        }
        int adds(int a){
            return a+member;
        }
        int get(){
            return member;
        }
};

int main() {
    Intreger a;
    cout << a.get() << endl;
    cout << a.adds(2) << endl;
//    cout << a.add(21) << endl;

    Intreger b(4);
    cout << b.get() << endl;
    cout << b.adds(12) << endl;
//    cout << b.add(21) << endl << endl;

    Intreger c(11);
    cout << c.get() << endl;
    cout << c.adds(88) << endl;
//    cout << c.add(21) << endl;

	return 0;
}
