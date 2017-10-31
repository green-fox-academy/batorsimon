#include <stdio.h>
#include <stdlib.h>

int main()
{
    while(1) {
        printf("from: \n");
        char user_input1[4];
        scanf("%s", user_input1);
        char user_input2[4];
        scanf("%s", user_input2);

        if (strcmp(user_input1, "q") == 0) {
            printf("The program is exiting now. Goodbye!");
            exit(0);
        } else{
            printf("Check the usage again!\n");
        }

        printf("To: \n");
        char user_input3[4];
        scanf("%s", user_input1);
        char user_input4[4];
        scanf("%s", user_input2);

    }
    return 0;
}
