#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sum(float number1, float number2);
float subt(float number1, float number2);
float multiply(float number1, float number2);
float divi(float number1, float number2);
int divi_w_remainder(int number1, int number2);
float sqr(float number1);
float sqr_root(float number1);
float logx(int number1, int number2);
int binto(char* number_arr1, int number2);
int octto(char* number_arr1, int number2);
int decto(char* number_arr1, int number2);
int hexto(char* number_arr1, int number2);
void set_cursor_posnumberstring1(int x, int y);
void input(char* number_arr1, char* command, char* number_arr2, int y);
int zero_operand(float number1, float number2);
int conversion_range(int number2);
void menu(char* number_arr1);
