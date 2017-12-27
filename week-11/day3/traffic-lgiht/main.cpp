#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std;

void Ampel1(string Farbe);
void Ampel2(string Farbe);
void stateMachine();

int state = 1;

int main()
{
    cout << "Hello world! This is a Traffic light!" << endl;

    while(1) {
        stateMachine();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}


void Ampel1(string Farbe){
    cout << "Ampel1: " << Farbe << endl;
};
void Ampel2(string Farbe){
    cout << "Ampel2: " << Farbe << endl << endl;
};

void stateMachine()
{
    switch(state) {
        case 1:
          Ampel1("ROT");
          Ampel2("GRUEN");
          state = 2;
          break;

        case 2:
          Ampel1("ROT");
          Ampel2("GELB");
          state = 3;
          break;

        case 3:
          Ampel1("ROT");
          Ampel2("ROT");
          state = 4;
          break;

        case 4:
          Ampel1("ROT-GELB");
          Ampel2("ROT");
          state = 5;
          break;

        case 5:
          Ampel1("GRUEN");
          Ampel2("ROT");
          state = 6;
          break;

        case 6:
          Ampel1("GELB");
          Ampel2("ROT");
          state = 7;
          break;

        case 7:
          Ampel1("ROT");
          Ampel2("ROT");
          state = 8;
          break;

        case 8:
          Ampel1("ROT");
          Ampel2("ROT-GELB");
          state = 1;
          break;
    }
}
