#include <stdio.h>
#include <stdlib.h>

void g_code();
void m_code();
void x_code();
void y_code();
void z_code();
void feed_rate();
void x_offset(); // i
void y_offset(); // j

char search_codes(char func_array[]);

int main()
{
    char probe[50] = "G03 X29.297604 Y20.946643 Z-1.000000 I-1.029490 J-1.472092 F200.000000";

    /*    tokenizing into 7 char arrays
            int error = 0;
        char delimiter[5] = ".";
        size_t pos = 0;
        string token;

        pos = user_input_date.find(delimiter);

            while (pos != npos) {
                token = user_input_date.substr(0, pos);
                year = atoi(token));
            }
            */

    search_codes(probe);

    return 0;
}

char search_codes(char func_array[]){
    char letter;
    int i = 0;
    for(i = 0; func_array[i] != '\0'; i++){
        printf("probe_func[%d]: %c\n", i, func_array[i]);
        if(func_array[i] == 'F'){
            letter = 'F';
            feed_rate();

        } else if(func_array[i] == 'G'){
            letter = 'G';
            g_code();

        } else if(func_array[i] == 'I'){
            letter = 'I';
            x_offset();

        } else if(func_array[i] == 'J'){
            letter = 'G';
            y_offset();

        } else if(func_array[i] == 'M'){
            letter = 'M';
            m_code();

        } else if(func_array[i] == 'X'){
            letter = 'X';
            x_code();

        } else if(func_array[i] == 'Y'){
            letter = 'Y';
            y_code();

        } else if(func_array[i] == 'Z'){
            letter = 'Z';
            z_code();

        } else {
            continue;
        }
    }

};

void g_code(){

};

void m_code() {
   /* int i = 0;
    for(i = 65; i < 91; i++){
        if(i == 71){
            printf("%d: %c\n", i, i);

        } else if(i == 77) {
            printf("%d: %c\n", i, i);

        }

    } */
};

void x_code() {

};

void y_code() {

};

void z_code() {

};
