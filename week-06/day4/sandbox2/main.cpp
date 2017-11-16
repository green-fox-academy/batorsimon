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

class Storage{
    public:
        void menu();
        void command();
        void new_task();
        void write_to_file();
        void read_from_file();
        void list_tasks();
        void remove_task();
        void completes_task();
        void priority_to_task();
        void list_tasks_priority();

    private:
         vector<Todo> storage;
         Todo t;

};

int main()
{
    Storage s;
    string yes = yes;
    int user_input;
    cin >> user_input;
    cout << endl;

    int size1 = storage.size();
    if(!cin || size1 < user_input || 1 > user_input){
        cout << "Give in a valid number!" << endl;
        cin.clear();
    } else{
        storage.at(user_input-1).set_done(yes);
    }
    return 0;
}
