#include <iostream>

using namespace std;

int main()
{
    int arr[12] = {2,4,122,54,21212,127,34};

    cout << *arr <<endl; // tomb elso eleme
    cout << *(arr+1) <<endl; // tomb masodik eleme eleme
    cout << arr <<endl; // tomb cimet adja vissza

    return 0;
}
