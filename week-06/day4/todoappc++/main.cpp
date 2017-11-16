#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

void menu() {
    system("cls");
    cout << "------------------------------------------" << endl;
    cout << "|        Todo application                |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| Commands:                              |" << endl;
    cout << "| -a    Adds a new task                  |" << endl;
    cout << "| -wr   Write current todos to file      |" << endl;
    cout << "| -rd   Read todos from a file           |" << endl;
    cout << "| -l    Lists all the tasks              |" << endl;
    cout << "| -e    Empty the list                   |" << endl;
    cout << "| -rm   Removes a task                   |" << endl;
    cout << "| -c    Completes a task                 |" << endl;
    cout << "| -p    Add priority to a task           |" << endl;
    cout << "| -lp   Lists all the tasks by priority  |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| menu  Opens the main menu              |" << endl;
    cout << "| clr   Clear command line               |" << endl;
    cout << "| exit  Exiting from the program         |" << endl;
    cout << "------------------------------------------" << endl;
    system("pause");
    system("cls");
}

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

class storage{
    public:
        void new_task();
        int write_to_file();
        int read_from_file();
        void list_tasks();
        void remove_task();
        void completes_task();
        void priority_to_task();
        void list_tasks_priority();


    private:
         vector<Todo> asd;

};
void new_task()
{
    string user_input;
    getline(cin, user_input);
    //strcpy(todo_arr[counter].task_name, user_input);
    //todo_arr[counter].task_name = user_input;
}

int write_to_file()
{
    ofstream outfile;
    outfile.open("probe.txt");

    string user_input;
    getline(cin, user_input);
    outfile << user_input << endl;

    outfile.close();
    //cin.getline(user_input, 100);
}

int read_from_file()
{
    string user_input;

    ifstream infile;
    infile.open("probe.txt");
    /*
    for(int i = 0; i < counter; i++){
         cout << user_input << endl;
    }
    */
    infile >> user_input;

    cout << user_input << endl;

    infile >> user_input;
    cout << user_input << endl;
    infile.close();
}

void list_tasks()
{
   // No. | Done? | Task priority | Task name \n
   // %d - [ ]   Priority: 1 %s", i+1, todo_arr[i].task_name

}

void remove_task()
{
    /*
    int pos = 0;
    int i = 0;
    counter--;

    for(i = 0; i < counter; i++) {
        if(strcmp(todo_arr[i].task_name, user_input) == 0){
            pos = i;
            for(i = pos; i< counter; i++){
                strcpy(todo_arr[i].task_name, todo_arr[i+1].task_name);
            }
        }

    }
    */
}

void completes_task()
{
    /*
    int i = 0;
    int input_number = strtol(user_input, NULL, 10);
    printf("No. | Done? | Task priority | Task name \n");
    for(i = 0; i < counter; i++){
        if(i == input_number-1){
             //printf("%d. [x]   Priority: 1 %s", i+1, todo_arr[i].task_name);
        } else {
             //printf("%d. [ ]   Priority: 1 %s", i+1, todo_arr[i].task_name);
        }

    }
    */
}

void priority_to_task()
{
    /*
    int i = 0;
    int input_number = strtol(user_input, NULL, 10);
    for(i = 0; i < counter; i++){
        if(i == input_number-1){
             printf("%d. [x] prio:  %d %s", i+1, input_number, todo_arr[i].task_name);
        } else {
             printf("%d. [ ] prio:  %s", i+1, todo_arr[i].task_name);
        }
    }
    */

      /*
            cout << "Write two numbers: a task number and give priority to it!" << endl;
            i = 0;
            for(i = 0; i < counter; i++){
                scanf"(%d", tasknum);
                scanf("%d", prio);
                printf("%d. [x] prio:  %d %s", i+1, input_number, todo_arr[i].task_name);
            }

            priority_to_task(todo_arr, user_input);
            */
}

void list_tasks_priority(){
    /*
    int i = 0;
    int input_number = strtol(user_input, NULL, 10);
    for(i = 0; i < counter; i++){
        if(i == input_number-1){
             printf("%d. [x] %s", i+1, todo_arr[i].task_name);
        } else {
             printf("%d. [ ] %s", i+1, todo_arr[i].task_name);
        }
    }
    */

}


void command(){
  string command;

    do {
        cin >> command;
        if (command == "exit") {
            cout << "The program is exiting now. Goodbye!" << endl;
            exit(0);
        } else if (command == "clr") {
            system("cls");
            continue;
        } else if (command == "menu") {
            menu();
            continue;
        } else if(command == "-a"){
            new_task();

        } else if (command == "-wr") {
            write_to_file();

        } else if (command == "-rd") {
           read_from_file();

        } else if (command == "-l") {
            list_tasks();

        } else if (command == "-e") {
            write_to_file();

        } else if (command == "-rm") {
            remove_task();

        } else if (command == "-c") {
           completes_task();

        } else if (command == "-p") {
            priority_to_task();

        } else if (command == "-lp") {
            list_tasks_priority();

        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (command != "exit");

}

int main()
{
    menu();
    command();



    return 0;
}
