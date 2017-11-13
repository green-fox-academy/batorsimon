#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    bool married = true;
    string name = "Levente";

    cout << "My name is: \n" << name << endl;

    if(married) {
        cout << "Not this time" << endl;
    } else {
        cout << "NEED coffee" << endl;
    }

    return 0;
}

