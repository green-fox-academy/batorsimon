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

    int i = 0;
    printf("\nSwitch loop\n");
    while(i < 4) {
        status = i;
        switch(status){
            case OPEN:
                printf("OPEN: %d\n", OPEN);
                i++;
                break;
            case OPENING:
                printf("OPENING: %d\n", OPENING);
                i++;
                break;
            case SECURING:
                printf("SECURING: %d\n", SECURING);
                i++;
                break;
            case SECURED:
                printf("SECURED: %d\n", SECURED);
                i++;
                break;
            default:
                printf("End of switch!\n");
                break;
        }
    }

    return 0;
}
