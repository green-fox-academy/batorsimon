#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

class Todo{
    public:
        Todo() {}

        Todo(string x){
            this->x = x;
        }

        void set_x(string x){
            this->x = x;
        }
        string get_x(){
            return x;
        }

        void set_prio(int prio){
            this->prio = prio;
        }
        int get_prio(){
            return prio;
        }

        void set_done(string done){
            this->done = done;
        }
        string get_done(){
            return done;
        }

    private:
        string x;
        string done;
        int prio;

};



void Storage::new_task()
{
    string user_input;
    getline(cin, user_input);

    t = Todo(user_input);
    storage.push_back(t);

}

int main()
{
    Storage s;
    //s.menu();
    //s.command();
    return 0;
}
