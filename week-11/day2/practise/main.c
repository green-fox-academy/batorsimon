#include <stdio.h>
#include <stdlib.h>

enum stat{OPEN, OPENING, SECURING, SECURED} status;

typedef enum{
nulla,
egy,
ketto,
harom,
negy
} status2;

int main()
{
    printf("enum stat\n");
    printf("open: %d\n", OPEN);
    printf("opening: %d\n", OPENING);
    printf("securing: %d\n", SECURING);
    printf("secured: %d\n", SECURED);


    printf("\ntypdef enum stat2\n");
    printf("0: %d\n", nulla);
    printf("1: %d\n", egy);
    printf("2: %d\n", ketto);
    printf("3: %d\n", harom);
    printf("4: %d\n", negy);


    printf("Switch loop\n");
    switch(status){
        case OPEN:
            printf("open: %d\n", OPEN);
            break;
        case OPENING:
            printf("opening: %d\n", OPENING);
            break;
        case SECURING:
            printf("SECURING: %d\n", SECURING);
            break;
        case SECURED:
            printf("SECURED: %d\n", SECURED);
            break;
        default:
            printf("End of switch!\n");
    }
    return 0;
}
