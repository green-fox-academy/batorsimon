#include <iostream>

using namespace std;

int main()
{
    int *p = NULL;
    p = new int(32);

    cout << *p;

    //ah�ny new parancost irsz annyi delete parancs kell

    delete p;

    return 0;
}
