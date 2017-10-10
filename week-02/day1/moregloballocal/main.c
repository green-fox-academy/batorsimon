#include <stdio.h>
#include <stdlib.h>

//Tom, Mark and Jerry went to the supermarket
//help them decide what can they buy out of their money

int tom_money = 2000;
int mark_money = 3500;
int jerry_money = 1200;

int can_they_buy_a_new_tv();
int can_they_make_a_cake();
int can_they_make_ham_and_eggs();

int can_they_buy_a_new_tv()
{
    int tv_price = 6950;
    int together_money = 0;
    int remain_money = 0;
    int remain_money2 = 0;
    int money_needed = 0;

    together_money = tom_money + mark_money + jerry_money;

    if(together_money >= tv_price)
    {
        remain_money = together_money - tv_price;
        return remain_money;

    } else{
        money_needed = tv_price - together_money;
        return money_needed;

    }

    /*

    if(together_money >= tv_price)
    {
        remain_money = together_money - tv_price;
        return remain_money;

    } else{
        remain_money2 = tv_price - together_money;
        return remain_money2;

    }
    if(together_money < tv_price)
    {
        money_needed = tv_price - together_money;
        return money_needed;
    } else{
        return 0;

    }
    */

    //if they can, the program should write out that how much money they have after they bought the tv
    //if they can't tell, how much money they need to buy it
}

int can_they_make_a_cake()
{
    int milk = 200;
    int chocolate = 340;
    int flour = 75;
    int egg = 345;
    int sugar = 160;
    int salt = 90;
    int oven_shape = 330;
    int cream = 220;

    int all_the_staff_cake = milk + chocolate + flour + egg + sugar + salt + oven_shape + cream;
    int how_much_pay_cake = all_the_staff_cake / 3;
    return how_much_pay_cake;

    //if they can buy all these stuff calculate how much
    //each of them should pay to share the bill equally
}

int can_they_make_ham_and_eggs()
{
    int milk = 200;
    int egg = 345;
    int salt = 90;
    int ham = 450;
    int onion = 60;
    int spice = 25;

    int all_the_stuff_hamm = milk + egg + salt + ham + onion + spice;
    int how_much_pay_hammandeggs = all_the_stuff_hamm / 3;
    return how_much_pay_hammandeggs;

    //if they can buy all these stuff calculate how much
    //each of them should pay to share the bill equally
}

//is there any local or global variables we did not use well?
//are we using functions correctly?

int main()
{
    int a = can_they_buy_a_new_tv();
    if(a<0){
        printf("\nThey can buy the tv and they will have %d dollars.\n", a);

    } else{
        printf("\nThey cant buy the TV. They wil need to save %d dollars.\n", a);
    }

    int b = can_they_make_a_cake();
    printf("\nIf they want to make a cake:\nEach of them should pay: %d\n", b);

    int c = can_they_make_ham_and_eggs();
    printf("\nIf they want to make hamm and eggs:\nEach of them should pay: %d\n", c);

    return 0;
}
