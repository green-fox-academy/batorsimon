#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*
Create a program which converts days to years, months, weeks and days
to keep it simple we say every year is 365 days long, every month is 30 days
*/

    int days = 3243;  //ennyi napunk van összesen

    int daysinyear = 365;
    int monthinyear = 12;
    int daysinmonth=30;
    int daysinweeks = 7;
    int evek=0;
    int maradek=0;
    int honapok=0;
    //int honap maradek=0;
    int napok=0;

    printf("%d napbol megnezzuk mennyi ev, honap es nap jon ki:\n", days);

    // hány év jön ki a 3243 napból  ->8 és marad 323 nap
    evek= days/daysinyear;
    printf("Evek szama: %d\n", evek);

    maradek= days%daysinyear;
    printf("Ezutan maradt napok szama: %d\n", maradek);

    //hány hónap jön ki az évek után maradt napokból  ->26 és marad 11 nap
    honapok=maradek/12;
    printf("Honapok szama: %d\n", honapok);

    napok = maradek%12;
    printf("Maradek napok szama: %d\n", napok);


    return 0;
}
