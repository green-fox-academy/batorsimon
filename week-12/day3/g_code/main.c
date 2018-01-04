#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void g_code(float temporary);
void m_code(float temporary);
void x_code(float temporary);
void y_code(float temporary);
void z_code(float temporary);
void feed_rate(float temporary);
void x_offset(float temporary); // i
void y_offset(float temporary); // j

void tokenizing(char func_array[]);
void search_codes(char func_array[]);

int main()
{
    char probe[500] = "G03 X29.297604 Y20.946643 Z-1.000000 I-1.029490 J-1.472092 F200.000000";
    tokenizing(probe);

    return 0;
}

void tokenizing(char func_array[]) {
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
        //printf("codes[%d]: %s\n", i, codes[i]);
        search_codes(codes[i]);
    }

};

void search_codes(char func_array[]){

    float temp = 0;
    char temp_arr[50];
    int i = 0;
    int j = 0;

    for(i = 0; func_array[i] != '\0'; i++){
        //printf("func_array[%d]: %c\n", i, func_array[i]);

        if(func_array[i] == 'F'){
            printf("found letter F\n");
            for(i++; func_array[i] != '\0';){
                //printf("func[%d]: %c\n", i, func_array[i]);
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
            feed_rate(temp);

        } else if(func_array[i] == 'G'){
            printf("found letter G\n");
            for(i++; func_array[i] != '\0';){
                //printf("func[%d]: %c\n", i, func_array[i]);
                j = 0;
                temp_arr[0] = func_array[i];
                j++;
                i++;
                temp = (float)atof(temp_arr);
                printf("temp: %f\n",temp);
                if(i == 0){
                    break;
                }
            }
            g_code(temp);

        } else if(func_array[i] == 'I'){
            printf("found letter I\n");
            for(i++; func_array[i] != '\0';){
                //printf("func[%d]: %c\n", i, func_array[i]);
                j = 0;
                temp_arr[0] = func_array[i];
                j++;
                i++;
                temp = (float)atof(temp_arr);
                printf("temp: %f\n",temp);
                i++;
                if(i == 0){
                    break;
                }
            }
            x_offset(temp);

        } else if(func_array[i] == 'J'){
            printf("found letter J\n");
             for(i++; func_array[i] != '\0';){
                //printf("func[%d]: %c\n", i, func_array[i]);
                j = 0;
                temp_arr[0] = func_array[i];
                j++;
                i++;
                temp = (float)atof(temp_arr);
                printf("temp: %f\n",temp);
                i++;
                if(i == 0){
                    break;
                }
            }
            y_offset(temp);

        } else if(func_array[i] == 'M'){
            printf("found letter M\n");
            for(i++; func_array[i] != '\0';){
                //printf("func[%d]: %c\n", i, func_array[i]);
                j = 0;
                temp_arr[0] = func_array[i];
                j++;
                i++;
                temp = (float)atof(temp_arr);
                printf("temp: %f\n",temp);
                i++;
                if(i == 0){
                    break;
                }
            }
            m_code(temp);

        } else if(func_array[i] == 'X'){
            printf("found letter X\n");
            for(i++; func_array[i] != '\0';){
                //printf("func[%d]: %c\n", i, func_array[i]);
                j = 0;
                temp_arr[0] = func_array[i];
                j++;
                i++;
                temp = (float)atof(temp_arr);
                printf("temp: %f\n",temp);
                i++;
                if(i == 0){
                    break;
                }
            }
            x_code(temp);

        } else if(func_array[i] == 'Y'){
            printf("found letter Y\n");
            for(i++; func_array[i] != '\0';){
                //printf("func[%d]: %c\n", i, func_array[i]);
                j = 0;
                temp_arr[0] = func_array[i];
                j++;
                i++;
                temp = (float)atof(temp_arr);
                printf("temp: %f\n",temp);
                i++;
                if(i == 0){
                    break;
                }
            }
            y_code(temp);

        } else if(func_array[i] == 'Z'){
            printf("found letter Z\n");
            //for(i = 0; func_array[i] != '\0'; i++){  not working
            for(i++; func_array[i] != '\0';){
                //printf("func[%d]: %c\n", i, func_array[i]);
                j = 0;
                temp_arr[0] = func_array[i];
                j++;
                i++;
                temp = (float)atof(temp_arr);
                printf("temp: %f\n",temp);
                i++;
                if(i == 0){
                    break;
                }
            }
            z_code(temp);

        } else {
            continue;
        }


    }

};

void g_code(float temporary){
    float temp = temporary;
    printf("in function g_code: temp = %f\n", temp);
    printf("it should be: 03\n");

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
    printf("in function g_code: temp = %f\n", temp);
    printf("it should be: - \n");

    // M02	 End of program
    //    M30    end of program
};

void x_code(float temporary) {
    float temp = temporary;
    printf("in function x_code: temp = %f\n", temp);
     printf("it should be: 29.297604\n");
};

void y_code(float temporary) {
    float temp = temporary;
    printf("in function y_code: temp = %f\n", temp);
     printf("it should be: 20.946643\n");
};

void z_code(float temporary) {
    float temp = temporary;
    printf("in function z_code: temp = %f\n", temp);
     printf("it should be: -1.000000\n");
};

void feed_rate(float temporary) {
    float temp = temporary;
    printf("in function feed_rate: temp = %f\n", temp);
     printf("it should be: 200.000000\n");
};

void x_offset(float temporary) {
    float temp = temporary;
    printf("in function x_offset: temp = %f\n", temp);
    printf("it should be: -1.472092\n");
};

void y_offset(float temporary) {
 float temp = temporary;
    printf("in function y_offset: temp = %f\n", temp);
    printf("it should be: -1.029490\n");
};
