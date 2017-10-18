#include <stdio.h>
#include <stdlib.h>

int summation(int a, int b){

    return a + b;
}

int subtraction(int a, int b){

    return a - b;
}

int multiplication(int a, int b){

    return a * b;
}

int division(int a, int b){

    return a / b;
}


int main()
{
    printf("           CLI Calculator\n====================================\nusage: [number] [operation] [number]\nCommands:\n\n+	summation\n-	subtraction\n*	multiplication\n/	division\n%	division with remainder\n^	squaring\n<	square root\nlog	logarithm\nbinto	binary to hex or dec\nhexto	hexadecimal to bin or dec\ndecto	decimal to bin or hex\n====================================\nexit	exiting from the program\nclear	clear the screen\nhelp	print usage\n====================================\nHit enter to start!\n====================================\n");


    int choice = 0;
    int num_1 = 0;
    int num_2 = 0;

    int num_1_watcher = 0;
    int num_2_watcher = 0;

    printf("Please add two number (hit enter between them):\n");
    scanf("%d %d", &num_1, &num_2);

    num_1_watcher = &num_1;
    num_2_watcher = &num_2;

	printf("Please choose from the following options:\n\n");
	printf("\tpress 1 for summation\n");
	printf("\tpress 2 for subtraction\n");
	printf("\tpress 3 for multiplication\n");
	printf("\tpress 4 for division\n");
	printf("\tpress 9 to exit the program\n");

    while(choice != 9){
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("%d + %d = %d\n",num_1, num_2, summation(num_1, num_2));
            continue;
        case 2:
            printf("%d - %d = %d\n",num_1, num_2, subtraction(num_1, num_2));
            continue;
        case 3:
            printf("%d * %d = %d\n",num_1, num_2, multiplication(num_1, num_2));
            continue;
        case 4:
            printf("%d / %d = %d\n",num_1, num_2, division(num_1, num_2));
            continue;
        case 9:
            printf("program is over\n");
            continue;
        default:
            printf("wrong user input, you have played your only one chance you son of a bit*h!\n");
            continue;
        }
    }

    return 0;
}
