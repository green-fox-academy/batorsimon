#include <iostream>
#include <string>
#include <vector>

using namespace std;

//create an integer vector with the size of 5 and print the 3rd element of it

int main() {

    vector <int> int_vector;

    int_vector.push_back(21);
    int_vector.push_back(44);
    int_vector.push_back(5);
    int_vector.push_back(18);
    int_vector.push_back(9);

    for(unsigned int i = 0; i < int_vector.size(); ++i) {
        if(i==2) {
            cout << int_vector[i] << endl;
        }
    }
    int_vector.pop_back();

    return 0;
}
