#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float summation(float a, float b){
    return a + b;
}

float subtraction(float a, float b){
    return a - b;
}

float multiplication(float a, float b){
    return a * b;
}

float division(float a, float b){
    return a / b;
}

float division_with_reminder(float a, float b){
    int c = 0;
    c = a % b;
     printf("%f % %f = %f\n",c);
}

float squaring(float a, float b){
    return a / b;
}

float square_root(float a, float b){
    return a / b;
}

float logarithm(float a, float b){
    return a / b;
}
float binto(float a, float b){
    return a / b;
}
int decto(float a, float b){
    return a / b;
}
int hexto(float a, float b){
    return a / b;
}



int main()
{
    printf("           CLI Calculator\n====================================\nusage: [number] [operation] [number]\nCommands:\n\n+	summation\n-	subtraction\n*	multiplication\n/	division\n%	division with remainder\n^	squaring\n<	square root\nlog	logarithm\nbinto	binary to hex or dec\nhexto	hexadecimal to bin or dec\ndecto	decimal to bin or hex\n====================================\nexit	exiting from the program\nclear	clear the screen\nhelp	print usage\n====================================\nHit enter to start!\n====================================\n");

    int choice = 0;
    float num_1 = 0;
    float num_2 = 0;

    printf("Please add two number (hit enter between them):\n");
    scanf("%f %f", &num_1, &num_2);

	printf("Please choose from the following options:\n\n");
	printf("\tpress 1 for summation\n");
	printf("\tpress 2 for subtraction\n");
	printf("\tpress 3 for multiplication\n");
	printf("\tpress 4 for division\n");
	printf("\tpress 5 for division with reminder\n");
	printf("\tpress 6 for squaring\n");
	printf("\tpress 7 for square root\n");
	printf("\tpress 8 for logarithm\n");
	printf("\tpress 9 for binary to decimal or hexadecimal\n");
	printf("\tpress 10 for decimal to binary or hexadecimal\n");
	printf("\tpress 11 for hexadecimal to binary or decimal\n");
	printf("\tpress 12 to exit the program\n");

    while(choice != 12){
        scanf("%d", &choice);
        if(isalpha(choice)){
            printf("wrong user input!");
            choice = 12;
            exit(0);
        }

        switch(choice){
        case 1:
            printf("%f + %f = %f\n",num_1, num_2, summation(num_1, num_2));
            continue;
        case 2:
            printf("%f - %f = %f\n",num_1, num_2, subtraction(num_1, num_2));
            continue;
        case 3:
            printf("%f * %f = %f\n",num_1, num_2, multiplication(num_1, num_2));
            continue;
        case 4:
            printf("%f / %f = %f\n",num_1, num_2, division(num_1, num_2));
            continue;
         case 5:
            printf("%f % %f = %f\n",num_1, num_2, division_with_reminder(num_1, num_2));
            continue;
         case 6:
            printf("%f ^ %f = %f\n",num_1, num_2, square_root(num_1, num_2));
            continue;
         case 7:
            printf("%f < %f = %f\n",num_1, num_2, square_root(num_1, num_2));
            continue;
         case 8:
            printf("%f log %f = %f\n",num_1, num_2, logarithm(num_1, num_2));
            continue;
        case 9:
            printf("%f binto %f = %f\n",num_1, num_2, binto(num_1, num_2));
            continue;
        case 10:
            printf("%f decto %f = %f\n",num_1, num_2, decto(num_1, num_2));
            continue;
        case 11:
            printf("%f hexto %f = %f\n",num_1, num_2, hexto(num_1, num_2));
            continue;
        case 12:
            printf("program is over\n");
            continue;
        default:
            printf("wrong user input!\n");
            continue;
        }
    }

    return 0;
}
