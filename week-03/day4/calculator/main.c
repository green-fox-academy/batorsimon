#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "func.h"

void help()
{
        system("cls");
        printf("           CLI Calculator\n");
        printf("====================================\n");
        printf("usage: [number][operation][number]\nCommands:\n\n");
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
int main()
{
    char number_arr1[20];
    char command[6];
    char number_arr2[20];
    char user_input[80];
    int y = 0;

   help();
   Sleep(5000);
   system("cls");

    do {
        input(number_arr1, command, number_arr2, y);

        float number1 = strtof(number_arr1, NULL);
        float number2 = strtof(number_arr2, NULL);
        int x = strlen(number_arr1) + strlen(command) + strlen(number_arr2) + 2;

        if (strcmp(command, "+") == 0) {
            set_cursor_pos(x, y);
            printf(" = %.2f\n", sum(number1, number2));
        } else if (strcmp(command, "-") == 0) {
            set_cursor_pos(x, y);
            printf(" = %.2f\n", subt(number1, number2));
        } else if (strcmp(command, "*") == 0) {
            set_cursor_pos(x, y);
            printf(" = %.2f\n", multiply(number1, number2));
        } else if (strcmp(command, "/") == 0) {
            set_cursor_pos(x, y);
            if (zero_operand(number1, number2) == 0) {
                printf(" = %.2f\n", divi(number1, number2));
            }
        } else if (strcmp(command, "%") == 0) {
            set_cursor_pos(x, y);
            if (zero_operand(number1, number2) == 0) {
                printf(" = %d\n", divi_w_remainder(number1, number2));
            }
        } else if (strcmp(command, "sqr") == 0) {
            set_cursor_pos(x, y);
            printf(" = %.2f\n", sqr(number1));
        } else if (strcmp(command, "sqr_root") == 0) {
            set_cursor_pos(x, y);
            if (zero_operand(number1, number2) == 0) {
                printf(" = %.2f\n", sqr_root(number1));
            }
        } else if (strcmp(command, "log") == 0) {
            set_cursor_pos(x, y);
            if (zero_operand(number1, number2) == 0) {
                printf(" = %f\n", logx(number2, number1));
            }
        } else if (strcmp(command, "binto") == 0) {
            set_cursor_pos(x, y);
            if (conversion_range(number2) == 0) {
                printf(" = %s\n", binto(number_arr1, number2));
            }
        } else if (strcmp(command, "octto") == 0) {
            set_cursor_pos(x, y);
            if (conversion_range(number2) == 0) {
                printf(" = %s\n", octto(number_arr1, number2));
            }
        } else if (strcmp(command, "decto") == 0) {
            set_cursor_pos(x, y);
            if (conversion_range(number2) == 0) {
                printf(" = %s\n", decto(number_arr1, number2));
            }
        } else if (strcmp(command, "hexto") == 0) {
            set_cursor_pos(x, y);
            if (conversion_range(number2) == 0) {
                printf(" = %s\n", hexto(number_arr1, number2));
            }
        }  else if (strcmp(command, "menu") == 0) {
            set_cursor_pos(x, y);
            //printf("%s", menu(number_arr1));
            //menu(char* number_arr1);
            }
        y++;
    }
    while (strcmp(number_arr1, "exit") != 0);
}
