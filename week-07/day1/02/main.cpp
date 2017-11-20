#include <iostream>

using namespace std;

// Write a try - catch block.
// Throw an char in the try block
// Catch it in the catch block and write it out.

int main() {
    char a;

    try{
       throw a = 's';
    }
    catch(char a){
        cout << a << endl;
    }

	return 0;
}
