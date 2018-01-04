#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tokenizing(char func_array[]);
char search_codes(char func_array[]);

int main()
{
    //char probe[500] = "G03 X29.297604 Y20.946643 Z-1.000000 I-1.029490 J-1.472092 F200.000000";

    int i = 0;
    int j = 0;
    float temp = 0;
    char func_array[40] = {2, 9, 2, 9, 7, 6, 0, 4};
    char temp_arr[40];
    for(i = 0; func_array[i] != '\0';){
        printf("func[%d]: %d\n", i, func_array[i]);
        j = 0;
        temp_arr[j] = func_array[i];
        i++;
        j++;
        if(i == 0){
            temp = (float)atof(temp_arr);
            printf("temp: %f\n",temp);
            break;
        }
    }


    //tokenizing(probe);

    return 0;
}

char tokenizing(char func_array[]) {
    char *codes[50]; //  tokenizing into 7 pieces
    int codes_length = 0;
    const char delimiter[3] = " ";
    char *token = strtok(func_array, delimiter); // get the first token

    while (token != NULL) {
        codes[codes_length++] = token;
        token = strtok(NULL, delimiter);
    }

    int i = 0;
    for(i = 0; i < codes_length; i++){
        printf("%s\n", codes[i]);
        //search_codes(codes[i]);
    }

    /*
    codes[0] G03
    codes[1] X29.297604
    codes[2] Y20.946643
    codes[3] Z-1.000000
    codes[4] I-1.029490
    codes[5] J-1.472092
    codes[6] F200.00000
    */

};

char search_codes(char func_array[]){

    char *codes[50];
    int codes_length = 0;
    char letter;
    const char delimiter[3] = " ";
    char *token = strtok(func_array, delimiter);

    while (token != NULL) {
        codes[codes_length++] = token;
        token = strtok(NULL, delimiter);
    }

    int i = 0;
    for(i = 0; i < codes_length; i++){
        //printf("%s\n", codes[i]);
    }

};
