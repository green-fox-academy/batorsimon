#include <iostream>
#include <string>
#include <vector>

using namespace std;

class student{
public:
    student() {}
    student(int grade){
        this->grade=grade;
    }

    ~student(){
        cout << "End of the program!" << endl;
    }

    void add_grade(int grade){
        this->grade = grade;
    }

    int get_grade(){
        return grade;
    }

    void add_grade_vector(int grade){
        grades.push_back(grade);
    }

    vector<int> grades;

private:
    int grade;

};

int main() {
    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades

    student st;
   // st.add_grade(4);

    st.add_grade_vector(5);
    st.add_grade_vector(4);
    st.add_grade_vector(3);
    st.add_grade_vector(2);

    for(int i = 0; i < st.grades.size(); i++){
        cout << st.grades.at(i) << endl;
    }


  return 0;

}
