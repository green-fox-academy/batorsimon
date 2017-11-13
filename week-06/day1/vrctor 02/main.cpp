#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int main() {
	//Create a vector of integers
	//reserve place for 10 element, then fill those place with random numbers between 0 and 10

    vector<int> vectors(10);
    srand(time(0));

    for(int i = 0; i < 10; i++) {
        vectors[i] = rand() % 11;
    }

    for (int i = 0; i < 10; i++) {
        cout << vectors[i] << " ";
    }

    return 0;
}
