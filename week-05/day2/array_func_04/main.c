#include <stdio.h>
#include <stdlib.h>

/*
 * Create a representation of a chess board in the form of a two dimensional character array.
 * Each figure should have a character representing it. Empty places should be a single space: ' '.
 *
 * Create a function which sets up the board.
 *
 * Create a function for checking the moves for each of the figures. They should get coordinates for the figure and where to move it.
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

void setup_board(char arr[8][8])
{
    char queen = 'Q';
    char king = 'K';
    char rock = 'R';
    char bishop = 'B';
    char knight = 'N';
    char pawn = 'p';

    int i = 0;
    int j = 0;


    arr[0][0] = arr[0][7] = arr[7][0] = arr[7][7] = rock;
    arr[0][1] = arr[0][6] = arr[7][1] = arr[7][6] = knight;
    arr[0][2] = arr[0][5] = arr[7][2] = arr[7][5] = bishop;
    arr[0][3] = arr[7][3] = queen;
    arr[0][4] = arr[7][4] = king;

    for(j = 0; j < 8; j++) {
        arr[1][j] = pawn;
        arr[6][j] = pawn;
    }

        for(i = 0; i < 8; i++) {
          for(j = 0; j < 8; j++) {
              printf("%c", arr[i][j]);
           }
          printf("\n");
        }

}

void move(char arr[8][8])
{
     char queen = 'Q';
    char king = 'K';
    char rock = 'R';
    char bishop = 'B';
    char knight = 'N';
    char pawn = 'p';


    arr[2][0]= knight;
    arr[0][1] = ' ';

    int i = 0;
    int j = 0;
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    char arr[8][8];

    int i = 0;
    int j = 0;

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if((i%2 == 0) || (i == 0)) {
                if(j%2==0 || j==0){
                     arr[i][j] = 'X';
                }else{
                    arr[i][j] = ' ';

                }
            }
            if(i%2 != 0) {
                if(j%2 == 0){
                     arr[i][j] = ' ';
                }else{
                    arr[i][j] = 'X';

                }
            }
            //printf("%c", arr[i][j]);
        }
        //printf("\n");
    }


    setup_board(arr);

    printf("\n");

    move(arr);


    return 0;
}
