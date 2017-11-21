#include <iostream>
#include <stdio.h>
#define PI 3.14

using namespace std;

int GetArea(int h, int l){
    return h * l;
}

int GetArea(int r){
    return r * r * PI;
}

int GetArea(int b, float h){
    return (b * h) / 2;
}

int main()
{
    cout << "The area of the square is: " << GetArea(10,20) << endl;
    cout << "The area of the circle is: " << GetArea(10) << endl;
    cout << "The area of the triangle is: " << GetArea(20,30.30f) << endl;

    return 0;
}
