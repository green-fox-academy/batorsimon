#include <iostream>

using namespace std;

// Write a try - catch block.
// Throw an integer in the try block
// Catch it in the catch block and write it out.

int main() {
    int a;

    try{
       throw a = 8;
    }
    catch(int a){
        cout << a << endl;
    }

	return 0;
}
