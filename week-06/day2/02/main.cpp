#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    string name;
    unsigned int age;
    Student(string name, unsigned int age) {
      this->age = age;
      this->name = name;
    }

    void print_data(){
        cout << "Name: " << name << ". Age: " << age << "." << endl;
    }
};

int main() {
  // Create a new instace of the Student class and set it's name to "John" and
  // it's age to 21 with it's constructor

  Student st("John", 21);
  st.print_data();

  return 0;
}
