#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void menu()
{
        printf("           CLI Calculator\n");
        printf("====================================\n");
        printf("nusage: [number][operation][number]\nCommands:\n\n");
        printf("+	summation\n");
        printf("-	subtraction\n");
        printf("*	multiplication\n");
        printf("/	division\n");
        printf("%	division with remainder\n");
        printf("^	squaring\n<	square root\n");
        printf("log	logarithm\n");
        printf("into	binary to hex or dec\n");
        printf("hexto	hexadecimal to bin or dec\n");
        printf("decto	decimal to bin or hex\n");
        printf("====================================\n");
        printf("exit	exiting from the program\nclear	clear the screen\n");
        printf("help	print usage\n");
        printf("====================================\n");

}

void summation()
{
   int n = 0;
   int k = 0;
   float total = 0;
   float number =0;

   printf("Enter the number of elements you want to add together: \n");
   scanf("%d", &n);
   printf("Please add the numbers one by one: %d\n", n);

   while(k<n){
    scanf("%f", &number);
    total = total + number;
    k = k+1;

   }
   printf("The numbers %d added together: %f\n",n,total);

}

void subtraction()
{
    float number1 = 0;
    float number2 = 0;
    float sum = 0;

    printf("Write down the first number: ");
    scanf("%f", number1);
    printf("Write down the second number: ");
    scanf("%f", number2);
    sum = number1 - number2;
    printf("\n%f - %f = %f", number1, number2, sum);
}

void multiplication()
{
    float number1 = 0;
    float number2 = 0;
    float sum = 0;

    printf("Write down the first number: ");
    scanf("%f", number1);
    printf("Write down the second number: ");
    scanf("%f", number2);
    sum = number1 * number2;
    printf("\n%f - %f = %f", number1, number2, sum);

}

void division()
{
    float number1 = 0;
    float number2 = 0;
    float sum = 0;

    printf("Write down the first number: ");
    scanf("%f", number1);
    printf("Write down the second number: ");
    scanf("%f", number2);
    sum = number1 / number2;
    printf("\n%f - %f = %f", number1, number2, sum);

}

void division_with_remainder()
{
    int number1 = 0;
    int number2 = 0;
    int sum = 0;
    int remainder = 0;
    printf("Write down the first number: ");
    scanf("%d", number1);
    printf("Write down the second number: ");
    scanf("%d", number2);
    sum = number1 / number2;
    remainder = number1 % number2;
    printf("\n%d - %d = %d \nthe remainder is: %d\n", number1, number2, sum, remainder);
}

void squaring()
{
    float number = 0;
    float result = 0;
	printf("Please enter a number: ");
	fflush(stdin);
	scanf("%f", &number);
	result = pow(number, 2);
	printf("%f", result);
}

void square_root()
{

}

void logarithm()
{

}

void binto()
{/*
    char buffer[20];
    int a = atoi(str);

    if(new_base == 2) {
        itoa(a, buffer, new_base);
        printf("The binary value of %s is %s.\n", str, buffer);
    } */
}

void hexto()
{/*
    char buffer[20];
    int a = atoi(str);

    if(new_base == 2) {
        itoa(a, buffer, new_base);
        printf("The binary value of %s is %s.\n", str, buffer);
    } */
}

void decto()
{/*
    char buffer[20];
    int a = atoi(str);

    if(new_base == 2) {
        itoa(a, buffer, new_base);
        printf("The binary value of %s is %s.\n", str, buffer);
    }*/
}

void factorial()
{
    int number = 0;
    scanf("%d", number);

    if(number <= 1) {
      printf("1\n");
    } else {
        printf("\n");
    }
    //return number * factorial(number-1);

}


int main()
{
    menu();

    char calc_operator[10];
    char s[2] = " ";
    char *point;

    char *point2;
    char s2[2] = "+";

    int i = 0;

    gets(calc_operator);
    point = strtok(calc_operator, s);
    point2 = strtok(calc_operator, s2);
    while(1){
        if(point == NULL) {
        puts("Please use space between the operands!");
        break;
        }
        while(point != NULL ) {
        point = strtok(NULL, s);

        }

    }


/*
    while(1) {
        scanf("%s", calc_operator);

        int i = 0;
        for(i = 0; i<10; i++) {
            if(calc_operator[i] == "+") {
            printf("ossze");
            summation();
            }
            if(calc_operator[i] == "-") {
            printf("minusz");
            subtraction();
            }
            if(calc_operator[i] == "*") {
            printf("minusz");
            subtraction();
            }
            if(calc_operator[i] == "/") {
            printf("minusz");
            subtraction();
            }
            if(calc_operator[i] == "%") {
            printf("minusz");
            subtraction();
            }
            if(calc_operator[i] == "^") {
            printf("minusz");
            subtraction();
            }
            if(calc_operator[i] == "<") {
            printf("minusz");
            subtraction();
            }
            if(calc_operator[i] == "log") {
            printf("minusz");
            subtraction();
            if(calc_operator[i] == "l" && calc_operator[i] = "o" && calc_operator[i] = "g") {  // ????????
            printf("minusz");
            subtraction();
            }
            if(calc_operator[i] == "binto") {
            printf("minusz");
            subtraction();
            }
            if(calc_operator[i] == "hexto") {
            printf("minusz");
            subtraction();
            }
            if(calc_operator[i] == "decto") {
            printf("minusz");
            subtraction();
            }
        }
    }
    */


  /*
    while(1) {

//        scanf("%f", &number1);
        scanf("%c", calc_operator);
//        scanf("%f", &number2);

        switch(calc_operator) {
        case '+':   summation();
                    break;
        case '-':
                    continue;
        case '*':
                    continue;
        case '/':
                    continue;
        case '%':
                    continue;
        case '^':
                    continue;
        case '<':
                    continue;
        case 'l':
                    continue;
        case 'b':
                    continue;
        case 'x':
                    continue;
        case 'd':
                    continue;
         case '!':
                    continue;
        case 'q':
                    continue;
        case 'h':
                    continue;
        case 'c':
                    continue;
        default:    printf("wrong user input!\n");
                    continue;
        }
    } */


    return 0;
}
