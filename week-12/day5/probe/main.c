#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int couting_lines();
char line_length[1000];
char *givingbackanarray();

int main()
{
    couting_lines();
    //printf("%d\n", couting_lines());
    //printf("%s\n", line_length);

    printf("\n--------------\n");
    printf(givingbackanarray());


    /*
    char file_name[40] = "test.txt";
    char temp_arr[1000];
    FILE *fptr;
    int i = 0;
    int j = 0;

    if ((fptr = fopen(file_name, "r")) == NULL)
    {
        printf("Error! opening file");
        exit(0);
    } else{
        for(i = 0; i < couting_lines(); i++) {
           // for(j = 0; line_length[j] != '\0'; j++){
                fscanf(fptr,"%[^\n]", temp_arr);
                fptr++;
                //printf("%s\n", temp_arr);
           // }
        }

    }

    fclose(fptr);

    for(i = 0; line_length[i] != '\0'; i++){
        //printf("%d: %d\n", i, line_length[i]);
    }
*/
    return 0;
}

int couting_lines(){
    int c;
    int lines_count = 0;
    int i = 0;
    char temp[1000];

    FILE *fptr = fopen("test.txt", "r");
    while ((c = getc(fptr)) != EOF){
            temp[i] = c;
            i++;

        if(c == '\n'){
            //printf("%s\n", temp);
            line_length[lines_count] = i;
            lines_count++;
            strcpy(line_length, temp);
            printf("%s\n", line_length);
            //temp[0] = "\0";
            //memset(temp, '\0', sizeof(temp));
        }
    }
    lines_count++;
    fclose(fptr);

    return lines_count;
}

char *givingbackanarray(){
    char temp[1000];
    int c;
    int i = 0;
    int lines_count = 0;
    char line_length[1000];
    FILE *fptr = fopen("test.txt", "r");
    while ((c = getc(fptr)) != EOF){
            temp[i] = c;
            i++;

        if(c == '\n'){
            line_length[lines_count] = i;
            lines_count++;
            strcpy(line_length, temp);
            return line_length;
        }
    }
    lines_count++;
    fclose(fptr);

};
