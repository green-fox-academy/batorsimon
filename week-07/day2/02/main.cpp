#include <iostream>
using namespace std;

// Create 3 functions: each should take respectively 2, 3 and 4 strings.
// Each should return a string that contains all the input string concatenated.
// (Combined into one in a linear order.)
// Write code that showcases how this works and prints out the result of the function.

string print(string x, string y){
    return x +y;
}

string print(string x, string y, string z){
    return x +y +z;
}

string print(string x, string y, string z, string w){
    return x + y + z + w;
}

int main() {

    cout << print("Green ", "fox! ") << print("udv ", "a ", "rokak ") << print("kozott ", "remelem ", "nem ", "unatkozol ")<< endl;
	return 0;
}
