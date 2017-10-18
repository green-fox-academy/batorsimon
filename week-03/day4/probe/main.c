#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
    float number1 = 0;
    float number2 = 0;
    float result = 0;
    result = number1 + number2;
    printf("%.2f + %.2f = %.2f\n",number1,number2,result);

}

void subtraction()
{


}

void multiplication()
{

}

void division()
{

}

void division_with_remainder()
{

}

void squaring()
{

}

void square_root()
{

}

void logarithm()
{

}

void binto()
{
    char buffer[20];
    int a = atoi(str);

    if(new_base == 2) {
        itoa(a, buffer, new_base);
        printf("The binary value of %s is %s.\n", str, buffer);
    }
}

void hexto()
{
    char buffer[20];
    int a = atoi(str);

    if(new_base == 2) {
        itoa(a, buffer, new_base);
        printf("The binary value of %s is %s.\n", str, buffer);
    }
}

void decto()
{
    char buffer[20];
    int a = atoi(str);

    if(new_base == 2) {
        itoa(a, buffer, new_base);
        printf("The binary value of %s is %s.\n", str, buffer);
    }
}

void binary_adder()
{
    int a;
    a = strtol(bin_op_1, NULL, 2);
    int b;
    b = strtol(bin_op_2, NULL, 2);

    char buffer[20];
    int sum = a + b;
    itoa(sum, buffer, 2);

    printf("The binary numbers added together: %s\n", buffer);
}

void binary_adder()
{
    int a;
    a = strtol(bin_op_1, NULL, 2);
    int b;
    b = strtol(bin_op_2, NULL, 2);

    char buffer[20];
    int sum = a + b;
    itoa(sum, buffer, 2);

    printf("The binary numbers added together: %s\n", buffer);
}


int main()
{
    menu();

    float number1 = 0;
    float number2 = 0;
    float result = 0;
    char operator1;

    scanf("%f", &number1);
    scanf(" %c ", &operator1);
    scanf("%f", &number2);

    while(1) {
         switch(operator1) {
        case '+':
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
        default:
            printf("wrong user input!\n");
            continue;
        }
    }

    return 0;
}
