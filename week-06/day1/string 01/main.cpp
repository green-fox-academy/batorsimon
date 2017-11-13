#include <iostream>

using namespace std;

// An average Green Fox attendee codes 6 hours daily
// The semester is 17 weeks long
//
// Print how many hours is spent with coding in a semester by an attendee,
// if the attendee only codes on workdays.
//
// Print the percentage of the coding hours in the semester if the average
// work hours weekly is 52

int main()
{
    int daily_code = 6;
    int semester_length = 17;
    int days_in_week = 5;

    float result = daily_code * days_in_week * semester_length;

    cout << result << " hours is spent with coding in a semester by an attendee." <<endl;

    int hours_weekly = 52;
    float work_hours_semester = hours_weekly * semester_length;
    cout << work_hours_semester << " work hours in a semester." <<endl;

    float result2 = result / work_hours_semester * 100;

    cout << result2 << " the percentage of the coding hours to full work hours in a semester." <<endl;
    return 0;
}
