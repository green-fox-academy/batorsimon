/*
 * read_from_file.c
 *
 *  Created on: 2018. jan. 8.
 *      Author: Bátor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_from_file.h"
#include "GCODE.h"

void read_complete_file() {

   // printf("Type in the file you want to read with it's extension: ");
    char file_name[40] = "test.txt";
    //fgets(file_name, 40, stdin);
    printf("\nThe requested file name: %s\n", file_name);

    char arr[60] = {0};
    int i = 0;
    FILE *file;
    int c;
    file = fopen(file_name, "r");

    if (file) {
        printf("The file contains the following: \n\n");
        while ((c = getc(file)) != EOF){
                arr[i] = c;
                i++;

                if(c == '\n'){
                	 tokenizing(arr);
                	memset(arr, '\0', 60);
                	 i = 0;
                }
        }

        tokenizing(arr);
        fclose(file);
        printf("\n\nEnd of file\n\n");

    } else {
        printf("Wrong file name or extension!\n");
        exit(0);
    }

}

