#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int i = 0;
int counter = 0;

void menu()
{
    system("cls");
    printf("------------------------------------------\n");
    printf("|        Todo application                |\n");
    printf("------------------------------------------\n");
    printf("| Commands:                               |\n");
    printf("| -a    Adds a new task                  |\n");
    printf("| -wr   Write current todos to file      |\n");
    printf("| -rd   Read todos from a file           |\n");
    printf("| -l    Lists all the tasks              |\n");
    printf("| -e    Empty the list                   |\n");
    printf("| -rm   Removes a task                   |\n");
    printf("| -c    Completes a task                 |\n");
    printf("| -p    Add priority to a task           |\n");
    printf("| -lp   Lists all the tasks by priority  |\n");
    printf("------------------------------------------\n");
    printf("| menu  Opens the main menu              |\n");
    printf("| clr   Clear command line               |\n");
    printf("| exit  Exiting from the program         |\n");
    printf("------------------------------------------\n");
    Sleep(5000);
    system("cls");
}

typedef struct{
	char task_name[50];
	int done;
	int prio;
} task;

void new_task(task *todo_arr, char *user_input)
{
    printf("%s", user_input);
    strcpy(todo_arr[i].task_name, user_input);
    i++;

}

void write_to_file(task *todo_arr, char *user_input)
{
    printf("%s", user_input);
    printf("Write current todos to file!\n");
    /*
    FILE *cd = fopen(command, "w+");
    if (cd == NULL) {
        printf("Could not create file: %s", command);
        return;
    }

    fprintf(cd, "10\tthis is the multi-word string");
    fclose(cd);
    */
}

void read_from_file(task *todo_arr)
{
    /*
    printf("Read todos from a file!\n");
    FILE *cd = fopen(command, "r");
    if (cd == NULL) {
        printf("The file %s does not exist!", command);
        return;
    }

    int num = 0;
    char str[255];

    fscanf(cd, "%d\t%s", &num, str);
    printf("read_file_fscanf() - number: %d, string: %s\n", num, str);
    fclose(cd);
    */
}

void list_tasks(task *todo_arr, char *user_input)
{
    printf("Lists all the tasks!\n");
     printf("%s", user_input);
}

void empty_task_list(task *todo_arr, char *user_input)
{
    printf("Empty the list!\n");
     printf("%s", user_input);
}

void remove_task(task *todo_arr, char *user_input)
{
    printf("Removes a task!\n");
     printf("%s", user_input);
}

void completes_task(task *todo_arr, char *user_input)
{
    printf("Completes a task!\n");
    printf("Num | Tasks | Prio\n");
    printf("1 - [ ] Walk the dog\n");
    printf("2 - [ ] Buy milk\n");
    printf("3 - [x] Do homework\n");
    printf("4 - [ ] Do something\n");
    printf("5 - [ ] Feed the Monkey\n");

}

void priority_to_task(task *todo_arr, char *user_input)
{
    printf("Add priority to a task!\n");

}

void list_tasks_priority(task *todo_arr, char *user_input)
{
    printf("Lists all the tasks by priority!\n");

}


int main(int argc, char** argv)
{
    char user_input[80];
    char command[4];
    FILE *fp;
    //menu();
    task todo_arr[10];

    do {
        scanf("%s", command);
        gets(user_input);

        if (strcmp(command, "exit") == 0) {
            printf("The program is exiting now. Goodbye!");
            exit(0);
        } else if (strcmp(command, "clr") == 0) {
            system("cls");
            continue;
        } else if (strcmp(command, "menu") == 0) {
            menu();
            continue;
        } else if(strcmp(command, "-a") == 0){
            new_task(todo_arr, user_input);
        } else if (strcmp(command, "-wr") == 0) {
             write_to_file(todo_arr, user_input);

        } else if (strcmp(command, "-rd") == 0) {
            read_from_file(todo_arr);

        } else if (strcmp(command, "-l") == 0) {
             list_tasks(todo_arr, user_input);

        } else if (strcmp(command, "-e") == 0) {
             empty_task_list(todo_arr, user_input);

        } else if (strcmp(command, "-rm") == 0) {
             remove_task(todo_arr, user_input);

        } else if (strcmp(command, "-c") == 0) {
            completes_task(todo_arr, user_input);

        } else if (strcmp(command, "-p") == 0) {
            priority_to_task(todo_arr, user_input);

        } else if (strcmp(command, "-lp") == 0) {
            list_tasks_priority(todo_arr, user_input);

        } else {
            printf("Wrong task name. Look at the possible tasks again.\n");
        }


    }
    while (strcmp(user_input, "exit") != 0);

    return 0;
}
