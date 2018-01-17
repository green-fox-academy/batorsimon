#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GCODE.h"
#include "STEPPER.h"


extern float x;
extern float y;
extern float z;


void tokenizing(char func_array[]) {

    printf("\nin func tokenizing: %s\n", func_array);
    char temp[300];
    strcpy(temp, func_array);
    char *codes[10]; //  tokenizing into pieces
    int codes_length = 0;
    const char delimiter[4] = " ";
    char *token = strtok(temp, delimiter); // get the first token

    while (token != NULL) {
        codes[codes_length] = token;
        token = strtok(NULL, delimiter);
        codes_length++;
    }

    int i = 0;
    for(i = 0; i < codes_length; ++i){
        search_codes(codes[i]);
    }

};

void search_codes(char func_array[]){
    printf(" in func search codes: %s\n", func_array);
    float temp = 0;
    char temp_arr[50];
    int i = 0;
    int j = 0;

    for(i = 0; i < 1; i++){
        if(func_array[i] == 'F'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }
            temp = (float)atof(temp_arr);
            feed_rate(temp);

        } else if(func_array[i] == 'G'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            g_code(temp);

        } else if(func_array[i] == 'I'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            x_offset(temp);

        } else if(func_array[i] == 'J'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            y_offset(temp);

        } else if(func_array[i] == 'M'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            m_code(temp);

        } else if(func_array[i] == 'X'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            x_code(temp);

        } else if(func_array[i] == 'Y'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            y_code(temp);

        } else if(func_array[i] == 'Z'){
            j = 0;
            memset(temp_arr, '\0', 50);
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

    if(g_code == 0){
         printf("rapid positioning\n");

    } else if(g_code == 1){
        printf("linear interpolation\n");
        // nincs R

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
        home();

    } else{
        printf("Not valid G code!!\n");
        exit(0);
    }

};

void m_code(float temporary) {
     float temp = temporary;

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
    movexy(temp, 0);

    /*
     if(temp < -420){
      //  printf("X coordinate cant be lower than -420!\n");

    } else if(temp > 420) {
      //  printf("X coordinate cant be higher than 420!\n");

    } else {
       // printf("i will go in X: %d mm\n", temp);
        x = temp;
    }
    */

};

void y_code(float temporary) {
    float temp = temporary;
    movexy(0, temp);

    /*
    if(temp < -330){
      //  printf("Y coordinate cant be lower than -330!\n");

    } else if(temp > 330) {
      //  printf("Y coordinate cant be higher than 330!\n");

    } else {
    //    printf("i will go in Y:  %d mm\n", temp);
        y = temp;
    }
    */

};

void z_code(float temporary) {
    float temp = temporary;

    if(temp < 1){
    	printf("i will upper the pen!\n");

    	z = temp;
    } else if(temp >= 1) {
    	printf("i will lower the pen!\n");
    	z = temp;
    }

};

void feed_rate(float temporary) {
    float temp = temporary;

    if(temp < -120){
        //printf("Feed rate cant be lower than -120!\n");

    } else if(temp > 300) {
      //  printf("Feed rate cant be higher than 300!\n");

    } else {
      //  printf("i will go with: %d mm/s\n", temp);

    }
};

void x_offset(float temporary) {
 //   float temp = temporary;

};

void y_offset(float temporary) {
   // float temp = temporary;


};
