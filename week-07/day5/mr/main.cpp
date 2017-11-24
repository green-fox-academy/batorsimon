#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string date, time;
    int temperature;

    string example = "2017.12.01 12:33:24 40";
    string badExample = "sadsd assdds sdsdsd";
    istringstream exampleStream(example);

    exampleStream >> date >> time >> temperature;
    if(exampleStream.fail()) {
        cout << "Invalid string!" << endl;
        return -1;
    }

    cout << "date: " << date << ", time: " << time << ", temp: " << temperature << endl;

    return 0;
}
