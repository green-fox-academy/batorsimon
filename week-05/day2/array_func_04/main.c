#include <stdio.h>
#include <stdlib.h>
#include "rlutil.h"

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
    char rook = 'R';
    char bishop = 'B';
    char knight = 'N';
    char pawn = 'p';

    int i = 0;
    int j = 0;

    arr[0][0] = arr[0][7] = arr[7][0] = arr[7][7] = rook;
    arr[0][1] = arr[0][6] = arr[7][1] = arr[7][6] = knight;
    arr[0][2] = arr[0][5] = arr[7][2] = arr[7][5] = bishop;
    arr[0][3] = arr[7][3] = queen;
    arr[0][4] = arr[7][4] = king;

    for(j = 0; j < 8; j++) {
        arr[1][j] = pawn;
        arr[6][j] = pawn;
    }

    printf("  12345678\n");
    for(i = 0; i < 8; i++) {
        printf("%d ", i+1);
        for(j = 0; j < 8; j++) {
            printf("%c", arr[i][j]);

        }
        printf("\n");
    }

}

void queen_move(char arr[8][8])
{
    /*
    kell még egy kezdeti hely és egy vég hely
    mengézni a vég helyen saját bábú van e
    ha ellenséges akkor elvégezni a "leütést"

    arr[i+x][j+x] = queen; vagy!
    arr[i+x][j-x]
    arr[i-x][j-x]
    arr[i-x][j+x]
    arr[i][j+x]
    arr[i][j-x]
    arr[i+x][j]
    arr[i-x][j]
    */
}

void king_move(char arr[8][8])
{
    /*
    arr[i+1][j+1] = king;  vagy!!
    arr[i+1][j-1]
    arr[i-1][j+1]
    arr[i-1][j+1]
    arr[i+1][j]
    arr[i][j+1]
    */
}

void rook_move(char arr[8][8])
{
    /*
    arr[i][j+x]= rook;  vagy!
    arr[i][j-x]= rook;
    arr[i+x][j]= rook;
    arr[i-x][j]= rook;
    */
}

void bishop_move(char arr[8][8])
{
    /*
    arr[i+x][j+x] = bishop; vagy!
    arr[i+x][j-x]
    arr[i-x][j+x]
    arr[i-x][j+x]
    */
}

void knight_move(char arr[8][8])
{
    /*
    arr[i+2][j+1] = knight; vagy!
    arr[i+2][j-1]
    arr[i-2][j+1]
    arr[i-2][j-1]

    arr[i+1][j+2]
    arr[i+1][j-2]
    arr[i-1][j-2]
    arr[i-1][j+2]
    */
}

void pawn_move(char arr[8][8])
{
    /*
     arr[i+1][j]= pawn;  if(i == 8) change to queen;
    */
}

void move(char arr[8][8])  //just one move with the knight
{
    char queen = 'Q';
    char king = 'K';
    char rook = 'R';
    char bishop = 'B';
    char knight = 'N';
    char pawn = 'p';

    arr[2][0]= knight;
    arr[0][1] = ' ';

    int i = 0;
    int j = 0;

    printf("  12345678\n");
    for(i = 0; i < 8; i++) {
        printf("%d ", i+1);
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
                    arr[i][j] = '0';
                }
            }
            if(i%2 != 0) {
                if(j%2 == 0){
                     arr[i][j] = '0';
                }else{
                    arr[i][j] = 'X';
                    setBackgroundColor(WHITE);
                    setColor(BLACK);

                }
            }
            //printf("%c", arr[i][j]);
        }
        //printf("\n");
    }

    setup_board(arr);

    printf("\n");

    //move(arr);

    /*
    printf("Usage: start position, space, end position. Like this: 11 21\nType q to quit.\n");
    while(1) {
        char user_input1[4];
        scanf("%s", user_input1);
        char user_input2[4];
        scanf("%s", user_input2);

        if (strcmp(user_input1, "q") == 0) {
            printf("The program is exiting now. Goodbye!");
            exit(0);
        } else{
            printf("Check the usage again!\n");
            continue;
        }


    }

    */

    return 0;
}
