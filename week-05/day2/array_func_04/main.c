#include <stdio.h>
#include <stdlib.h>

/*
 * Create a representation of a chess board in the form of a two dimensional character array.
 * Each figure should have a character representing it. Empty places should be a single space: ' '.
 *
 * Create a function which sets up the board.
 *
 * Create a function for checking the moves for each of the figurs. They should get coordinates for the figure and where to move it.
 * They should return 0 if the move is acceptable in chess and -1 if not.
 *
 * Create a function which moves figures by getting the initial coordinate and the target coordinate.
 * This should return -1 if the move was not successful and 0 if all is right and if all is right then also move the figure.
 *
 * Determine what kind of arguments You need for the functions. Write them accordingly.
 *
 * For the sake of this exercise it's enough if You write the specific functions for peasants and horse.
 *
 * In the main functions set up the board and try them. Check if they work as intended.
 */

void chess_board()
{

}

int main()
{
    char arr[8][8] = {
        /*
        {'X',' ','X',' ','X',' ','X',' '}, 0
        {' ','X',' ','X',' ','X',' ','X'}, 1
        {'X',' ','X',' ','X',' ','X',' '}, 2
        {' ','X',' ','X',' ','X',' ','X'}, 3
        {'X',' ','X',' ','X',' ','X',' '}, 4
        {' ','X',' ','X',' ','X',' ','X'}, 5
        {'X',' ','X',' ','X',' ','X',' '}, 6
        {' ','X',' ','X',' ','X',' ','X'}  7   */
    };

    int i = 0;
    int j = 0;

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if((i%2 == 0) | (i == 0)) {
                    arr[j] = 'X';
                    arr[j+1] = ' ';
            }
            if(i%2 != 0) {
                arr[j] = ' ';
                arr[j+1] = 'X';
            }
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    void chess_board();

    /*
    printf("\n-----------------------------\n\n");

    char queen = 'Q';
    char king = 'K';
    char rock = 'R';
    char bishop = 'B';
    char knight = 'N';
    char pawn = 'p';

    int i = 0;
    int j = 0;

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
    */

    return 0;
}
