#include <iostream>
#include <vector>

using namespace std;

// Create a Shape class, inherit two derived class from it
// One should be Circle, and the other one is Triangle
// For each derived class, implement a calc_area() method
// which calculates the area of the shape and stores it inside
// the class (so it is a private field)

class Shape{
    public:
      virtual void calc_area(){
      };

};

class Circle: public Shape{
    public:
        virtual void calc_area(){
            int circle_area = (r*r*3.14);
            cout << "The area of the circle is: " << circle_area <<endl;
        }
        void set_variables(int r){
           this->r = r;
        }

    private:
        int circle_area;
        int r;
};

class Triangle: public Shape{
    public:
        virtual void calc_area(){
            int triangle_area = (a+b+c)/2;
            cout << "The area of the triangle is: " << triangle_area <<endl;
        }
        void set_variables(int a, int b, int c){
            this->a = a;
            this->b = b;
            this->c = c;
        }

    private:
        int triangle_area;
        int a;
        int b;
        int c;
};


int main()
{
    Shape se;

    Circle ce;
    ce.set_variables(4);
    ce.calc_area();

    Triangle te;
    te.set_variables(2,3,4);
    te.calc_area();

    return 0;
}
