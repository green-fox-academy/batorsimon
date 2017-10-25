#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Bitfield{
    uint8_t boolean_value_1:1;
    uint8_t boolean_value_2:1;
    uint8_t boolean_value_3:1;
    uint8_t boolean_value_4:1;
    uint8_t boolean_value_5:1;
    uint8_t boolean_value_6:1;
    uint8_t boolean_value_7:1;
    uint8_t boolean_value_8:1;
} size;

struct NotBitfield{
    uint8_t boolean_value_1;
    uint8_t boolean_value_2;
    uint8_t boolean_value_3;
    uint8_t boolean_value_4;
    uint8_t boolean_value_5;
    uint8_t boolean_value_6;
    uint8_t boolean_value_7;
    uint8_t boolean_value_8;
} size2;

int main() {
    // TODO:
    // Print out the size of both structs (use sizeof() function)

    struct Bitfield;
    struct NotBitfield;

    printf("Size of struct Bitfield: %d bite.\n", sizeof(size));
    printf("Size of struct NotBitfield: %d bite.\n", sizeof(size2));

    return 0;
}
