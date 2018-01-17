#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_from_file.h"

char *read_file_line_by_line() {

    char file_name[40] = "test.txt";
    //fgets(file_name, 40, stdin);
    char temp_arr[1000];
    FILE *fptr;
    fptr = readed;
    //printf("fptr: %d. readed: %d   before reading!!\n", fptr, readed);

    if ((fptr = fopen(file_name, "r")) == NULL)
    {
        printf("Error! opening file"); // Program exits if file pointer returns NULL.
        exit(0);
    } else{
        //fptr = fopen(file_name, "r");
        fscanf(fptr,"%[^\n]", temp_arr); // reads text until newline
        fptr = fptr+1;
        readed = fptr;
        //printf("fptr: %d. readed: %d after reading\n", fptr, readed);
    }

    fclose(fptr);

    return temp_arr;
};

int couting_lines(){
    int c;
    int lines_count = 0;

    FILE *fptr;
    fptr = fopen("test.txt", "r");
    while ((c = getc(fptr)) != EOF){
        if(c == '\n'){
            lines_count++;
        }
    }
    lines_count++;
    fclose(fptr);
    return lines_count;
}

void read_complete_file() {

    printf("Type in the file you want to read with it's extension: ");
    char file_name[40] = "test.txt";
    //fgets(file_name, 40, stdin);
    printf("\nThe requested file name: %s\n", file_name);

    FILE *file;
    int c;
    int lines = 0;
    file = fopen(file_name, "r");

    if (file) {
        printf("The file contains the following: \n\n");
        while ((c = getc(file)) != EOF){
                putchar(c);
                if(c == '\n'){
                    lines++;
                }
        }

        fclose(file);
        lines++;
        printf("\nlines: %d\n", lines);
        printf("\n\nEnd of file\n\n");

    } else {
        printf("Wrong file name or extension!\n");
        exit(0);
    }

}