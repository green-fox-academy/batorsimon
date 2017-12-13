#include <iostream>
#include <vector>

#include "administrator.h"
#include "costumer.h"
#include "atm.h"
#include "users.h"

using namespace std;

int main()
{
    Atm ATM;
    ATM.add(new Users("Kiss", 1234, 234256, 0));
    ATM.add(new Users("John", 1234, 235662, 0));
    ATM.add(new Users("Pamela Anderson", 1234, 2964542, 0));
    ATM.add(new Users("Brave", 12345678, 0, 1));
    ATM.add(new Users("Admin", 12345678, 0, 1));
    ATM.add(new Users("Elon", 1234, 2634543, 0));

    ATM.main_menu();

    return 0;
}
