#include <iostream>
#include "bankacc.h"

using namespace std;

int main()
{
    bankacc ba(1234, 33.33);
    ba.print_data();

    ba.set_money(123, 1000);
    ba.print_data();

    return 0;
}
