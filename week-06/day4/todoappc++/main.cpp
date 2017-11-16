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

class todo{
public:

private:

};


void new_task()
{
    //strcpy(todo_arr[counter].task_name, user_input);
    //todo_arr[counter].task_name = user_input;
    counter++;
}

int write_to_file()
{
    /*
    FILE *cd = fopen("file.txt", "w+");
    if (cd == NULL) {
        printf("Could not create file: %s", todo_arr);
        return -1;
    }

    int i;
    for(i = 0; i < counter; i++){
         fprintf(cd, "%s", todo_arr[i].task_name);
         //fprintf(cd, "%s %d %d\n", todo_arr[i].task_name, todo_arr[i].done, todo_arr[i].prio);
         //csak akkor fog kelleni ha már lesz prio meg done, függvénybe is megkell hívni!!
    }
    fclose(cd);
    */
}

int read_from_file()
{
    /*
    FILE *cd = fopen("file.txt", "r");
    if (cd == NULL) {
        printf("The file %s does not exist!", todo_arr);
        return -1;
    }

    int i;
    for(i = 0; i < counter; i++){
         printf(cd, "%s", todo_arr[i].task_name);
    }

    /*
    int num = 0;
    char str[255];
    fscanf(cd, "%d\t%s", &num, str);
    printf("read_file_fscanf() - number: %d, string: %s\n", num, str);

    fclose(cd);
    */
}

void list_tasks()
{
    int i = 0;
    //printf("No. | Done? | Task priority | Task name \n");
    for(i = 0; i < counter; i++){
        //printf("%d - [ ]   Priority: 1 %s", i+1, todo_arr[i].task_name);
    }

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


int main()
{
    menu();
    //task todo_arr[10];

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
            getline(cin, user_input);
            new_task();

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
