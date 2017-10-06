#include <stdio.h>
#include <stdlib.h>


/*
Create a program which can tell how to pay an exact amount of money
for example 45670 Ft, is the amount (store this as an integer)
and the output should be:
2-20000Ft
1-5000Ft
1-500Ft
1-100Ft
1-50Ft
1-20Ft
*/

/*
Take care of the rounding (when giving back 5 coins):
1, 2 - 0 down
3, 4 - 5 up
6, 7 - 5 down
8, 9 - 0 up
*/


int main()
{
    int amount_of_money = 57549;

    int huszezresek_szama=0;
    int tizezresek_szama=0;
    int otezresek_szama=0;
    int ketezresek_szama=0;
    int ezresek_szama=0;
    int otszazasok_szama=0;
    int szazasok_szama=0;
    int otvenesek_szama=0;
    int huszasok_szama=0;
    int tizesek_szama=0;
    int otosok_szama=0;
    int maradek=0;


    printf("A szamunk: %d\n", amount_of_money);

    huszezresek_szama = amount_of_money / 20000;
    maradek = amount_of_money % 20000;
    printf("Szukseges 20,000-ek szama: %d \n", huszezresek_szama );
    printf("Maradek: %d \n", maradek );


    tizezresek_szama = maradek / 10000;
    maradek = amount_of_money % 10000;
    printf("Szukseges 10,000-ek szama: %d \n", tizezresek_szama );
    printf("Maradek: %d \n", maradek );


    otezresek_szama = maradek / 5000;
    maradek = amount_of_money % 5000;
    printf("Szukseges 5,000-ek szama: %d \n", otezresek_szama );
    printf("Maradek: %d \n", maradek );


    ketezresek_szama = maradek / 2000;
    maradek = amount_of_money % 2000;
    printf("Szukseges 2,000-ek szama: %d \n", ketezresek_szama );
    printf("Maradek: %d \n", maradek );


    ezresek_szama = maradek / 1000;
    maradek = amount_of_money % 1000;
    printf("Szukseges 1,000-ek szama: %d \n", ezresek_szama );
    printf("Maradek: %d \n", maradek );


    otszazasok_szama = maradek / 500;
    maradek = amount_of_money % 500;
    printf("Szukseges 500-ok szama: %d \n", otszazasok_szama );
    printf("Maradek: %d \n", maradek );


    szazasok_szama = maradek / 100;
    maradek = amount_of_money % 100;
    printf("Szukseges 100-ok szama: %d \n", szazasok_szama );
    printf("Maradek: %d \n", maradek );


    otvenesek_szama = maradek / 50;
    maradek = amount_of_money % 50;
    printf("Szukseges 50-ek szama: %d \n", otvenesek_szama );
    printf("Maradek: %d \n", maradek );


    tizesek_szama = maradek / 10;
    maradek = amount_of_money % 10;
    printf("Szukseges 10-ek szama: %d \n", tizesek_szama );
    printf("Maradek: %d \n", maradek );


    otosok_szama = maradek / 5;
    maradek = amount_of_money % 5;

    switch(maradek){
    case 1 : maradek<=2;
             maradek=0;
    case 2 : maradek == 3 && maradek == 4;
             maradek = 5;
    case 3 : maradek == 6 && maradek == 7;
             maradek = 5;
    case 4 : maradek > 7;
             maradek=0;
             otosok_szama++;
             //printf("5 Ft-al többet kell adnod!");
    }
    printf("Szukseges 5-ek szama: %d \n", otosok_szama );
    printf("maradek %d \n", maradek );

    return 0;
}
