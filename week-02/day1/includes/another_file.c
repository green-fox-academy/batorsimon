// TODO: Include needed header files
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "another_file.h"


void StringManipulator(char* str){
    uint32_t str_len = strlen(str);
    uint32_t i = 0;

    for(i = 0; i < str_len; i++) {
        str[i] -= 1;
    }
}

void IntegerManipulator(int* num){
    *num = num - an_example_number;
}
