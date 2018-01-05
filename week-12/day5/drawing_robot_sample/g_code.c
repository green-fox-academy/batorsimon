#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "g_code.h"

void tokenizing(char func_array[]) {
    printf("\nin func tokenizing: %s\n", func_array);
    char *codes[50]; //  tokenizing into 7 pieces
    int codes_length = 0;
    const char delimiter[4] = " ";
    char *token = strtok(func_array, delimiter); // get the first token

    while (token != NULL) {
        codes[codes_length++] = token;
        token = strtok(NULL, delimiter);
        //printf("codes[%d]: '%s'\n", codes_length, codes[codes_length]);
    }

    for(int i = 0; i < codes_length; ++i){
        printf("codes[%d]: '%s'\n", i, codes[4]);
        search_codes(codes[i]);
    }

};

void search_codes(char func_array[]){
    printf(" in func search codes: %s\n", func_array);
    float temp = 0;
    char temp_arr[50];
    int i = 0;
    int j = 0;

    //for(i = 0; func_array[i] != '\0'; i++){
    for(i = 0; i < 1; i++){
        //printf("func_array[%d]: %c\n", i, func_array[i]);

        if(func_array[i] == 'F'){
            printf("found letter F\n");
            j = 0;
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }
            temp = (float)atof(temp_arr);
            feed_rate(temp);

        } else if(func_array[i] == 'G'){
            printf("found letter G\n");
            j = 0;
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            g_code(temp);

        } else if(func_array[i] == 'I'){
            printf("found letter I\n");
            j = 0;
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            x_offset(temp);

        } else if(func_array[i] == 'J'){
            printf("found letter J\n");
            j = 0;
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            y_offset(temp);

        } else if(func_array[i] == 'M'){
            printf("found letter M\n");
            j = 0;
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            m_code(temp);

        } else if(func_array[i] == 'X'){
            printf("found letter X\n");
            j = 0;
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            x_code(temp);

        } else if(func_array[i] == 'Y'){
            printf("found letter Y\n");
            j = 0;
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            y_code(temp);

        } else if(func_array[i] == 'Z'){
            printf("found letter Z\n");
            j = 0;
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            z_code(temp);

        } else {
            continue;

        }


    }

};

void g_code(float temporary){
    float temp = temporary;
    printf("in function g_code: temp = %f\n", temp);
    //printf("it should be: 03\n");

    /*
  G00   rapid positioning
  G01   linear interpolation
  G02   circular inerpolation(clockwise)
  G03   circular inerpolation(counterclockwise)
  G010  programmable data input
  G21	Programming in millimeters (mm)
  G028  home(machine zero aka reference point)
    */
};

void m_code(float temporary) {
     float temp = temporary;
    printf("in function m_code: temp = %f\n", temp);
    //printf("it should be: - \n");

    // M02	 End of program
    //    M30    end of program
};

void x_code(float temporary) {
    float temp = temporary;
    printf("in function x_code: temp = %f\n", temp);
    // printf("it should be: 29.297604\n");

};

void y_code(float temporary) {
    float temp = temporary;
    printf("in function y_code: temp = %f\n", temp);
    // printf("it should be: 20.946643\n");
};

void z_code(float temporary) {
    float temp = temporary;
    printf("in function z_code: temp = %f\n", temp);
    // printf("it should be: -1.000000\n");
};

void feed_rate(float temporary) {
    float temp = temporary;
    printf("in function feed_rate: temp = %f\n", temp);
    // printf("it should be: 200.000000\n");
};

void x_offset(float temporary) {
    float temp = temporary;
    printf("in function x_offset: temp = %f\n", temp);
    // printf("it should be: -1.029490\n");
};

void y_offset(float temporary) {
 float temp = temporary;
    printf("in function y_offset: temp = %f\n", temp);
    // printf("it should be: -1.472092\n");
};
