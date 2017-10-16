#include <stdio.h>
#include <stdlib.h>


//project-guessing-game
//Note: the program gets harder, when you set a lower range

int minandmaxvalues(int *rand_num);
int guessing(int rand_num);

int main()
{
    int rand_num;
	minandmaxvalues(&rand_num);
	guessing(rand_num);

    return 0;
}

int minandmaxvalues(int *rand_num)
{
	int rand_max = 0;
	int rand_min = 0;
	printf("please add the minimum number!\n");
	scanf("%d", &rand_min);
	printf("please add the maximum number!\n");
	scanf("%d", &rand_max);
	srand(time(NULL));
	rand_num = rand() % (rand_max - rand_min);

	printf("I have a number between %d and %d. You have 5 lives\n", rand_min, rand_max);
	printf("%d\n", rand_num); //generated number
	//int a = rand_num;
	//return rand_num;
}
int guessing(int rand_num)
{
    int x = 1;
	int count = 0;
	int guess = 0;

	for (count = 4; count >= 0; count--) {
		printf("\n");
		scanf("%d", &guess);

			if (guess == rand_num) {
				printf("Yeeeeey, you did well! It took you %d tires!", x);
				x++;
				break;
			}

			if (guess > rand_num){
                printf("Too big, You have %d  lives left\n", count);
			}
			else{
                printf("Too low, You have %d lives left\n", count);
			}

			if (count == 0)
            printf("You have used all your lives!");
	}


}
