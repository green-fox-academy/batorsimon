#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> int_vector;

    int_vector.push_back(21);
    int_vector.push_back(44);
    int_vector.push_back(5);
    int_vector.push_back(18);
    int_vector.push_back(9);

    //a vektor ugy viselkedik mint egy verem tehát nem lehet negatív értéke

    for(unsigned int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector[i] << endl;
    }

    int_vector.pop_back();
    cout << "-----" << endl;


    for(unsigned int i = 0; i < int_vector.size() +1; ++i) { //size+1 miatt írja ki az utolsó elemet is
        cout << int_vector[i] << endl;
    }

    int_vector.insert(int_vector.begin() + 1, 111); //begin+1: második helyre beteszi az adott szamot
    // dinamikusan noveli keretet tehát plusz elemet berakva minden további elem eggyel tobább ugrik
    cout << "--------------" << endl;


    for(unsigned int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector[i] << endl;
    }

    return 0;
}
