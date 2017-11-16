#include <iostream>
#include <windows.h>

using namespace std;

int counter = 0;

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


int main()
{
    menu();

    string user_input;
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
            cin >> user_input;
           //new_task(todo_arr, user_input);

        } else if (command == "-wr") {
            cin >> user_input;
            // write_to_file(todo_arr, user_input);

        } else if (command == "-rd") {
            cin >> user_input;
           // read_from_file(todo_arr);

        } else if (command == "-l") {
            cin >> user_input;
            // list_tasks(todo_arr, user_input);

        } else if (command == "-e") {
            cin >> user_input;
          //   memset(&todo_arr, 0, sizeof(todo_arr));
          //   write_to_file(todo_arr, user_input);

        } else if (command == "-rm") {
            cin >> user_input;
           //  remove_task(todo_arr, user_input);

        } else if (command == "-c") {
            cin >> user_input;
           // completes_task(todo_arr, user_input);

        } else if (command == "-p") {
            cin >> user_input;
            /*
            printf("Write two numbers: a task number and give priority to it!\n");

            i = 0;
            for(i = 0; i < counter; i++){
                scanf"(%d", tasknum);
                scanf("%d", prio);
                printf("%d. [x] prio:  %d %s", i+1, input_number, todo_arr[i].task_name);
            }

            priority_to_task(todo_arr, user_input);
            */

        } else if (command == "-lp") {
            cin >> user_input;
           // list_tasks_priority(todo_arr, user_input);

        } else {
            cout << "Wrong task name. Look at the possible tasks again." << endl;
        }

    } while (user_input != "exit");


    return 0;
}
