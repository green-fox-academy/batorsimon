#include <stdio.h>
#include <stdlib.h>

//The program chooses a number between 1 and 100. The player is then asked to enter a guess.
//If the player guesses wrong, then the program gives feedback
// then ask to enter an other guess until the guess is correct.

int main()
{
    srand(time(NULL));
    int random = rand() % 100;
    printf("%d\n", random);
    int guess = 0;
    int lives = 5;
    int i = 0;

    printf("I choosed a number between 1 and 100. \nGuess a number: \n");
    printf("You have %d lives.\n", lives);

    for(i; i < 10; i++){
        scanf("%d", &guess);
        if(random == guess){
        printf("Winning!");
        exit(0);
        } else {
        lives--;
        printf("Guess another! You have %d lives remaining\n", lives);
        }
        if(lives == 0){
            printf("Loser!");
            exit(0);
        }
    }
    return 0;
}
