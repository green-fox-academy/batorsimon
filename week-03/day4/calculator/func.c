#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "func.h"

float sum(float number1, float number2)
{
    return (number1 + number2);
}

float  subt(float number1, float number2)
{
    return (number1 - number2);
}

float  multiply(float number1, float number2)
{
    return (number1 * number2);
}

float divi(float number1, float number2)
{
    return number1 / number2;
}

int divi_w_remainder(int number1, int number2)
{
    return (number1 % number2);
}

float  sqr(float number1)
{
    return (number1 * number1);
}

float sqr_root(float number1)
{
    return (sqrt(number1));
}

float logx(int number2, int number1)
{
    float logxofbasey = log(number2) / log(number1);
    return logxofbasey;
}


int binto(char* number_arr1, int number2)
{
    char buffer[20];
    long number;
    number = strtol(number_arr1, NULL, 2);
    itoa(number, buffer, number2);
    return buffer;
}

int octto(char* number_arr1, int number2)
{
    char buffer[20];
    long number;
    number = strtol(number_arr1, NULL, 8);
    itoa(number, buffer, number2);
    return buffer;
}

int decto(char* number_arr1, int number2)
{
    char buffer[20];
    long number;
    number = strtol(number_arr1, NULL, 10);
    itoa(number, buffer, number2);
    return buffer;
}

int hexto(char* number_arr1, int number2)
{
    char buffer[20];
    long number;
    number = strtol(number_arr1, NULL, 16);
    itoa(number, buffer, number2);
    return buffer;
}

void set_cursor_pos(int x, int y)
{
    COORD coord = {0,0};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void input(char* number_arr1, char* command, char* number_arr2, int y)
{
    scanf("%s", number_arr1);
    if (strcmp(number_arr1, "exit") == 0) {
        printf("The program is exiting now. Goodbye!");
        exit(0);
    } else if (strcmp(number_arr1, "clear") == 0) {
        system("cls");
        y = 0;
        scanf("%s", number_arr1);
    } else if (strcmp(number_arr1, "help") == 0) {
        system("cls");
        menu(number_arr1);
        system("cls");
        y = 0;
        scanf("%s", number_arr1);
    }
    scanf("%s", command);
    scanf("%s", number_arr2);
}

int zero_operand(float number1, float number2)
{
    if (number1 == 0 || number2 == 0) {
        printf("\tNot allowed to use 0 as operand\n");
        return 1;
    }
    return 0;
}

int conversion_range(int number2)
{
    if (number2 < 2 || number2 > 32) {
        printf("\tUse a number between 2 and 32\n");
        return 1;
    }
    return 0;
}

void menu(char* number_arr1)
{
        system("cls");
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
