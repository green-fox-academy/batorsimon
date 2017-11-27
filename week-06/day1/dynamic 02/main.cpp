#include <iostream>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it shoud print the average of the nubmers.
 * It should delete any dynamically allocated resource before the program exits.
 */

int main() {
    int *counter = NULL;
    int *number = NULL;
    counter = new int;
    number = new int;

    cout << "Give a number to count: ";
    cin >> *counter;
    cout << endl;

    int* v  = NULL;
    v  = new int[*counter];

    for (int i = 0; i <= *counter - 1; i++) {
        cout << "Enter #" << i + 1 << ": ";
        cin >> *num;
        *(v + i) = *num;
    }

    float *sum = NULL;
    sum = new float;
    for(int i = 0; i <= *counter - 1; i++) {
        *sum += *(v + i);
    }

    cout << endl << "The average is: " << *sum / *counter;

    delete [] v;
    delete counter;
    delete num;
    delete sum;

    return 0;
}
