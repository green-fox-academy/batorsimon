#include <iostream>
#include <vector>

using namespace std;

// Countinue the Shape exercise!
// Create getter methods for each values
// (for example: in a Triangle class you should be able to
// get: Height, Base and Area)

class Shape{
    public:
      virtual void calc_area(){
      };

};

class Circle: public Shape{
    public:
        virtual void calc_area(){
            int circle_area = (r*r*3.14);
            cout << "The area of the circle is: " << circle_area <<endl << endl;
        }
        void set_variable(int r){
           this->r = r;
        }

    private:
        int circle_area;
        int r;
};

class Triangle: public Shape{
    public:
        void calc_area(){
            this->triangle_area = float(base+height)/2;
        }

        void set_base(int base){
            this->base = base;
            calc_area();
        }
        void set_height(int height){
            this->height = height;
            calc_area();
        }

        void get_base(){
            cout << "The base of the triangle is: " << base <<endl;
        }
        void get_height(){
            cout << "The height of the triangle is: " << height <<endl;
        }

        void get_area(){
             cout << "The area of the triangle is: " << triangle_area <<endl;
        }

    private:
        float triangle_area;
        float base;
        float height;
};


int main()
{
    Shape se;

    Circle ce;
    ce.set_variable(4);
    ce.calc_area();

    Triangle te;
    te.set_base(3);
    te.get_base();
    te.set_height(2);
    te.get_height();
    te.get_area();

    return 0;
}
