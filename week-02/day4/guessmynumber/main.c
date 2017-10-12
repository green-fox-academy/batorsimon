#include <stdio.h>
#include <stdlib.h>

//The program chooses a number between 1 and 100. The player is then asked to enter a guess.
//If the player guesses wrong, then the program gives feedback
// then ask to enter an other guess until the guess is correct.

int main()
{
    srand(time(NULL));
    int range1 = 0;
    int range2 = 0;

    int guess = 0;
    int lives = 5;
    int i = 0;

    printf("Chose a starting point: ");
    scanf("%d", &range1);
    printf("Chose an end point: ");
    scanf("%d", &range2);
    int range = range2 - range1;
    if(range1 > range2 | range < 10){
        printf("False range!");
        exit(0);
    }
    int random = rand() % range;
    printf("%d\n", random);
    printf("I choosed a number between %d and %d. \nGuess the number: \n", range1, range2);
    printf("You have %d lives.\n", lives);

    for(i; i < 10; i++){
        scanf("%d", &guess);
        if(guess < range1 | guess > range2){
            printf("Guess out of the given range!");
            //lives--;
        }
        if(random == guess){
        printf("Winning!");
        exit(0);
        } else {
        lives--;
        printf("Guess another! You have %d lives remaining\n", lives);
        }
        if(lives == 0 | lives < 0){
            lives = 0;
            printf("Loser!");
            exit(0);
        }
    }
    return 0;
}
