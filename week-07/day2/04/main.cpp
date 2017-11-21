#include <iostream>
using namespace std;

// Create a Class named Integer. It should have one int member variable.
// Create add() methods to it. They should take Integer& parameters.
// Make variations of add() method 1, 2, 3, 4 and 5 arguments respectively.
// All methods should add the value of the parameters to the member variable of this.
//
// Try them out. Write code that demonstrates how they work.

class Intreger{
    private:
        int member;
    public:
        Intreger(int member) : member(member){ }

        Intreger& add(Intreger& obj1){
             this->member += obj1.member;
             return *this;
        }
        Intreger& add(Intreger& obj1, Intreger& obj2){
             this->member += obj1.member + obj2.member;
             return *this;
        }
        Intreger& add(Intreger& obj1, Intreger& obj2, Intreger& obj3){
             this->member += obj1.member + obj2.member + obj3.member;
             return *this;
        }
        Intreger& add(Intreger& obj1, Intreger& obj2, Intreger& obj3, Intreger& obj4){
             this->member += obj1.member + obj2.member + obj3.member + obj4.member;
             return *this;
        }
        Intreger& add(Intreger& obj1, Intreger& obj2, Intreger& obj3, Intreger& obj4, Intreger& obj5){
             this->member += obj1.member + obj2.member + obj3.member + obj4.member + obj5.member;
             return *this;
        }

        int get(){
            return member;
        }
};

int main() {
    Intreger a(11);
    Intreger b(22);
    Intreger c(33);
    Intreger d(44);

    cout << "The variables are: a:" << a.get() << " b: " << b.get() << " c: " << c.get() << " d: " << d.get() << endl;

    cout << a.get() << " + " << b.get() << " = ";
    a.add(b);
    cout << a.get() << endl;

    cout << a.get() << " + " << c.get() << " = ";
    a.add(c);
    cout << a.get() << endl;

    cout << a.get() << " + " << d.get() << " = ";
    a.add(d);
    cout << a.get() << endl;

	return 0;
}
