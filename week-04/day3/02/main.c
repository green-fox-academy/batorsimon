#include <stdio.h>
#include <stdlib.h>

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  enum CarType type;
  double km;
  double gas;
} carr;

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {

    struct Car VOLVO = ("Volvo", "100", "12");
    struct Car TOYOTA = (Toyota,"100", "8");
    struct Car LAND_ROVER = (Land Rover, "100", "15", );
    struct Car TESLA = (Tesla, "100", "0");

    printf(" %d\n %d\n", carr.km, carr.gas);

    return 0;
}
