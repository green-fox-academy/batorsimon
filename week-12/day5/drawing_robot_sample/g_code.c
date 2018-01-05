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
    codes[codes_length] = token;
    printf("token %d: %s\n", codes_length, token);

    while (token != NULL) {
        codes[codes_length] = token;
        token = strtok(NULL, delimiter);
        codes_length++;
        //printf("codes[%d]: '%c'\n", codes_length, codes[codes_length]);
        //printf("token %d: %s\n", codes_length, token);
    }

    int i = 0;
    for(i = 0; i < codes_length; ++i){
        printf("codes[%d]: '%s'\n", i, codes[i]);
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
    float g_code = temporary;
    printf("in function g_code: temp = %f\n", g_code);
    //printf("it should be: 03\n");

    if(g_code == 0){
         printf("rapid positioning\n");

    } else if(g_code == 1){
        printf("linear interpolation\n");

    }  else if(g_code == 2){
        printf("circular inerpolation(clockwise)\n");

    }  else if(g_code == 3){
        printf("circular inerpolation(counterclockwise)\n");

    }  else if(g_code == 10){
        printf("programmable data input\n");

    }  else if(g_code == 21){
        printf("Programming in millimeters (mm)\n");

    }  else if(g_code == 28){
        printf("home(machine zero aka reference point)\n");

    }  else if(g_code == 1){
        printf("linear interpolation\n");

    } else{
        printf("Not valid G code!!\n");
        exit(0);
    }

};

void m_code(float temporary) {
     float temp = temporary;
    printf("in function m_code: temp = %f\n", temp);
    //printf("it should be: - \n");

    if(temp == 2){
        printf("End of program\n");

    } else if(temp == 30) {
        printf("End of program\n");

    } else {
        printf("Not valid M code!!\n");

    }
    // M02	 End of program
    //    M30    end of program
};

void x_code(float temporary) {
    float temp = temporary;
    printf("in function x_code: temp = %f\n", temp);
    // printf("it should be: 29.297604\n");

     if(temp < -120){
        printf("X coordinate cant be lower than -120!\n");

    } else if(temp > 300) {
        printf("X coordinate cant be higher than 300!\n");

    } else {
        printf("i will go in X: %f mm\n", temp);

    }

};

void y_code(float temporary) {
    float temp = temporary;
    printf("in function y_code: temp = %f\n", temp);
    // printf("it should be: 20.946643\n");

    if(temp < -120){
        printf("Y coordinate cant be lower than -120!\n");

    } else if(temp > 300) {
        printf("Y coordinate cant be higher than 300!\n");

    } else {
        printf("i will go in Y: %f mm\n", temp);

    }
};

void z_code(float temporary) {
    float temp = temporary;
    printf("in function z_code: temp = %f\n", temp);
    // printf("it should be: -1.000000\n");

    if(temp < -120){
        printf("Z coordinate cant be lower than -120!\n");

    } else if(temp > 300) {
        printf("Z coordinate cant be higher than 300!\n");

    } else {
        printf("i will go in Z: %f mm\n", temp);

    }

};

void feed_rate(float temporary) {
    float temp = temporary;
    printf("in function feed_rate: temp = %f\n", temp);
    // printf("it should be: 200.000000\n");

    if(temp < -120){
        printf("Feed rate cant be lower than -120!\n");

    } else if(temp > 300) {
        printf("Feed rate cant be higher than 300!\n");

    } else {
        printf("i will go with: %f mm/s\n", temp);

    }
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
