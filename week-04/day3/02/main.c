#include <stdio.h>
#include <stdlib.h>

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  enum CarType type;
  double km;
  double gas;
};

void print(struct Car carr) {
    printf("Type: %d\n", carr.type);
    printf("km: %.2f\n", carr.km);

    if(carr.type != TESLA) {
        printf("gas: %f\n", carr.gas);
    }
}

int main() {

    struct Car a1 = {VOLVO, 100, 12};
    struct Car a2 = {TOYOTA, 100, 8};
    struct Car a3 = {LAND_ROVER, 100, 15};
    struct Car a4 = {TESLA, 100, 10};

    print(a1);
    print(a2);
    print(a3);
    print(a4);

    return 0;
}
