#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "g_code.h"


void tokenizing(char func_array[]) {

    printf("\nIn func tokenizing: %s\n", func_array);
    char temp[300];
    strcpy(temp, func_array);
    char *codes[10]; //  tokenizing intO pieces
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
    //printf(" in func search codes: %s\n", func_array);
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
            code.F = temp;
            //feed_rate(temp);

        } else if(func_array[i] == 'G'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            code.G = temp;
            //g_code(temp);

        } else if(func_array[i] == 'I'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            code.I = temp;
            //x_offset(temp);

        } else if(func_array[i] == 'J'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            code.J = temp;
            //y_offset(temp);

        } else if(func_array[i] == 'R'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            code.R = temp;
            //m_code(temp);

        } else if(func_array[i] == 'X'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            code.x = temp;
            //x_code(temp);

        } else if(func_array[i] == 'Y'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            code.y = temp;
            //y_code(temp);

        } else if(func_array[i] == 'Z'){
            j = 0;
            memset(temp_arr, '\0', 50);
            for(i++; func_array[i] != '\0'; i++){
                temp_arr[j] = func_array[i];
                j++;
            }

            temp = (float)atof(temp_arr);
            code.Z = temp;
            //z_code(temp);

        } else {
            continue;

        }

    }

};

void printel(){
   printf("G: %d, x: %g, y: %g, Z: %g, I: %g, J: %g, R: %g, F: %d \n", code.G, code.x, code.y, code.Z, code.I, code.J, code.R, code.F);

/*
    if(code.G == 1){
        move(code.x, code.y);
        Z_Axis(code.Z);
    }

    if(code.G == 2 ||code.G == 3){
            if(code.R == 0){
                arc(code.G, code.I, code.J);
            } else {
                arc(code.G, code.R);
            }

    }

     if(code.G == 28){
       home();
    }

    */

}

//printf("%g", codes);


void g_code(float temporary){
    float g_code = temporary;
    //printf("in function g_code: temp = %f\n", g_code);
    //one_line.g_code = temp;ú

/*
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

    } else{
        printf("Not valid G code!!\n");
        exit(0);
    }
*/
};

void m_code(float temporary) {
     float temp = temporary;
    //printf("in function m_code: temp = %f\n", temp);

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
    //printf("in function x_code: temp = %f\n", temp);

     if(temp < -120){
       // printf("X coordinate cant be lower than -120!\n");

    } else if(temp > 340) {
        temp = 340;
       // printf("X coordinate cant be higher than 300!\n");

    } else {
       // printf("i will go in X: %f mm\n", temp);

    }

};

void y_code(float temporary) {
    float temp = temporary;
   // printf("in function y_code: temp = %f\n", temp);

    if(temp < -120){
      //  printf("Y coordinate cant be lower than -120!\n");

    } else if(temp > 300) {
       // printf("Y coordinate cant be higher than 300!\n");

    } else {
       // printf("i will go in Y: %f mm\n", temp);

    }
};

void z_code(float temporary) {
    float temp = temporary;
   // printf("in function z_code: temp = %f\n", temp);

    if(temp < -120){
      //  printf("Z coordinate cant be lower than -120!\n");

    } else if(temp > 300) {
      //  printf("Z coordinate cant be higher than 300!\n");

    } else {
     //   printf("i will go in Z: %f mm\n", temp);

    }

};

void feed_rate(float temporary) {
    float temp = temporary;
   // printf("in function feed_rate: temp = %f\n", temp);

    if(temp < -120){
      //  printf("Feed rate cant be lower than -120!\n");
        //struct.feed_rate = temp;

    } else if(temp > 300) {
      //  printf("Feed rate cant be higher than 300!\n");

    } else {
     //   printf("i will go with: %f mm/s\n", temp);

    }
};

void x_offset(float temporary) {
    float temp = temporary;
  //  printf("in function x_offset: temp = %f\n", temp);

};

void y_offset(float temporary) {
    float temp = temporary;
   // printf("in function y_offset: temp = %f\n", temp);

};
