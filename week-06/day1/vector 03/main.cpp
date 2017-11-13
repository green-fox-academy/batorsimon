#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int main() {
	//create a vector of integers with the size of 20
	//fill this vector with random numbers from 0 to 10
	//print the items of the vector
    //remove the even numbers, then print the items again

    vector<int> vectors(20);
    srand(time(0));

    for (int i = 0; i < vectors.size(); i++) {
        vectors[i] = rand() % 11;
    }

    for (int i = 0; i < vectors.size(); i++) {
        cout << vectors[i] << " ";
    }

    cout << endl << "----------" << endl;

    for (int i = 0; i < vectors.size(); i++) {
        if(vectors[i] % 2 == 0){
            cout << vectors[i] << " ";
        }
    }
    return 0;
}
