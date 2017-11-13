#include <stdio.h>
#include <string.h>

/* Create a personal ID registers
 * You should store the following data in a structure, called "person":
 * - the name of the person (which is shorter than 256 characters)
 * - the year of the birth (1990)
 * - the type of the highest qualification (as a custom type, see below)
 *
 * You should store the qualification type in an enumeration ("qualification"),
 * the valid types are:
 *  - elementary-school
 *  - high-school
 *  - bsc-degree
 *  - master-degree
 *  - phd
 *
 * The "person" -s are stored in an array.
 *
 * Implement the following functions:
 * - get_oldest_alive()
 *    - it should return the age of the oldest person
 * - get_qualification_count()
 *    - it returns the count of persons which has "quali" qualification
 * For both functions you have to add the needed parameters!
 * You don't need to implement a function, which initializes the persons, just do it manually from main().
E.g.initialize your persons in main() with 4 elements in order to be able to test your 2 implemented functions if it works correctly.
 */

 typedef struct{
    char person[255];
    int birth_date;
    char qualification[30];
 } ID;

 void filling_structure(ID *arr)
 {
     strcpy(arr[0].person, "John Smith");
     strcpy(arr[1].person, "John Wick");
     strcpy(arr[2].person, "Matt Damon");
     strcpy(arr[3].person, "Dave Mirra");
     strcpy(arr[4].person, "Kiss Balazs");

     arr[0].birth_date = 1993;
     arr[1].birth_date = 1981;
     arr[2].birth_date = 1968;
     arr[3].birth_date = 1972;
     arr[4].birth_date = 1984;

     strcpy(arr[0].qualification, "Elementary School");
     strcpy(arr[1].qualification, "High School");
     strcpy(arr[2].qualification, "BSC degree");
     strcpy(arr[3].qualification, "Master degree");
     strcpy(arr[4].qualification, "PHD");

 }
int get_oldest_alive(ID *arr)
{
    int i = 0;
    int age = 0;
    for(i = 0; i < sizeof arr; i++){
        if(age > arr[i].birth_date){
            age = arr[i].birth_date;
        }
    }
    age = (2017 - age);
    return age;

}

int get_qualificaton_count(ID *arr, char *pointer)
{
    int i = 0;
    int counter = 0;
    for(i = 0; i < sizeof arr; i++){
        if(strcmp(arr[i].qualification, pointer) == 0){
            counter++;
        }
    }
    return counter;
}
 int main()
 {
    ID arr[10];
    filling_structure(arr);

    int returned_age = get_oldest_alive(arr);
    printf("The age of the oldest person: %d\n", returned_age);

    char comparison[20] = "PHD";
    int returned_count = get_qualificaton_count(arr, comparison);
    printf("How many people have the given qualification: %d\n", returned_count);

    return 0;
 }
