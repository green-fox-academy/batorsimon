#include <stdio.h>
#include <stdlib.h>

//TODO: write a function which filters out the odd elements of an integer array
//do it in the original array
//your return value should be the real size of the filtered array
//print out the filtered array's elements

int assort_odd_elements(int *array, int size);

int main(void)
{
	int num_array[] = {8, 7, 9, 20, 3, 81, 79, 66};

    int arr_size = sizeof(num_array) / sizeof(int);
    int pos_s = assort_odd_elements(num_array, arr_size);

    int i = 0;
    for(i = 0; i < pos_s; i++) {
       printf("%d\n", num_array[i]);
    }

    return 0;
}

int assort_odd_elements(int *array, int size)
{
    int pos = 0;
    int i = 0;
    for(i = 0; i < size; i++) {
        if(array[i] %2 ==0){
            array[pos] = array[i];
            pos++;
        }
    }
    return pos;
}
