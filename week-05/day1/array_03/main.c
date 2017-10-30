#include <stdio.h>
#include <stdlib.h>


/*
 * Create a 2 dimensonal array of characters. 8x8
 * Fill the array with X and space alternating.
 * Print it out row by row. (It should resemble a chess board)
 * Designate a character for each chess peace. (Queen could be Q, King could be K, etc.)
 * Set up the start of a game.
 * Print it out again.
 * Make one move with a horse.
 * Print it again.
 */

int main()
{
    char arr[8][8] = {
        {'X',' ','X',' ','X',' ','X',' '},
        {' ','X',' ','X',' ','X',' ','X'},
        {'X',' ','X',' ','X',' ','X',' '},
        {' ','X',' ','X',' ','X',' ','X'},
        {'X',' ','X',' ','X',' ','X',' '},
        {' ','X',' ','X',' ','X',' ','X'},
        {'X',' ','X',' ','X',' ','X',' '},
        {' ','X',' ','X',' ','X',' ','X'}
    };

    int i = 0;
    int j = 0;

    for(i = 0; i < 8; i++) {
          for(j = 0; j < 8; j++) {
              printf("%c", arr[i][j]);
           }
          printf("\n");
    }


    printf("\n-----------------------------\n\n");

    char queen = 'Q';
    char king = 'K';
    char rock = 'R';
    char bishop = 'B';
    char knight = 'N';
    char pawn = 'p';


    char arr2[8][8] = {
        {rock,knight,bishop,queen,king,bishop,knight,rock},
        {pawn,pawn,pawn,pawn,pawn,pawn,pawn,pawn},
        {'X',' ','X',' ','X',' ','X',' '},
        {' ','X',' ','X',' ','X',' ','X'},
        {'X',' ','X',' ','X',' ','X',' '},
        {' ','X',' ','X',' ','X',' ','X'},
        {pawn,pawn,pawn,pawn,pawn,pawn,pawn,pawn},
        {rock,knight,bishop,queen,king,bishop,knight,rock}
    };

    for(i = 0; i < 8; i++) {
          for(j = 0; j < 8; j++) {
              printf("%c", arr2[i][j]);
           }
          printf("\n");
    }

    printf("\n-----------------------------\n\n");

    arr2[2][0]= knight;
    arr2[0][1] = ' ';
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            printf("%c", arr2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
