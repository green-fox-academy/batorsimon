#include <iostream>
#include <vector>

using namespace std;

class Todo{
    public:
        Todo(string x, int prio, bool done){
            x = x;

        };

    private:

        int counter;
        bool done;
        int prio;

};

class Storage{
    public:

    private:
         vector<Todo> storage;

};


int main()
{
    //Todo t;
    //t.Todo();
    cout << "Hello world!" << endl;
    return 0;
}
