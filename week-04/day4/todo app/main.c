#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void menu()
{
    system("cls");
    printf("        Todo application\n");
    printf("========================================\n");
    printf("Commands:\n");
    printf(" -a    Adds a new task\n");
    printf(" -wr   Write current todos to file\n");
    printf(" -rd   Read todos from a file\n");
    printf(" -l    Lists all the tasks\n");
    printf(" -e    Empty the list\n");
    printf("-rm    Removes a task\n");
    printf(" -c    Completes a task\n");
    printf(" -p    Add priority to a task\n");
    printf(" -lp   Lists all the tasks by priority\n");
    printf(" menu  Opens the main menu\n");
    printf(" clr  Clear command line\n");
    printf(" exit  Exiting from the program\n");
    printf("=========================================\n");
    Sleep(5000);
    system("cls");
}

struct task {
	char name[50];
	int done;
	int prio;
};

void input(char* user_input)
{
    scanf("%s", user_input);
    if (strcmp(user_input, "exit") == 0) {
        printf("The program is exiting now. Goodbye!");
        exit(0);
    } else if (strcmp(user_input, "clr") == 0) {
        system("cls");
        scanf("%s", user_input);
    } else if (strcmp(user_input, "menu") == 0) {
        menu();
        scanf("%s", user_input);
    }
    scanf("%s", user_input);
}

void new_task(char* command)
{
    printf("Adds a new task!\n");

}

void write_to_file(char* command)
{
   printf("Write current todos to file!\n");

}

void read_from_file(char* command)
{
    printf("Read todos from a file!\n");

}

void list_tasks(char* command)
{
    printf("Lists all the tasks!\n");

}

void empty_task_list(char* command)
{
    printf("Empty the list!\n");

}

void remove_task(char* command)
{
    printf("Removes a task!\n");

}

void completes_task(char* command)
{
    printf("Completes a task!\n");

}

void priority_to_task(char* command)
{
    printf("Add priority to a task!\n");

}

void list_tasks_priority(char* command)
{
    printf("Lists all the tasks by priority!\n");

}


int main()
{
    char user_input[80];
    char command[30];

    menu();

    do {
        input(user_input);

        if (strcmp(user_input, "-a") == 0) {
            new_task(command);

        } else if (strcmp(user_input, "-wr") == 0) {
             write_to_file(command);

        } else if (strcmp(user_input, "-rd") == 0) {
            read_from_file(command);

        } else if (strcmp(user_input, "-l") == 0) {
             list_tasks(command);

        } else if (strcmp(user_input, "-e") == 0) {
             empty_task_list(command);

        } else if (strcmp(user_input, "-rm") == 0) {
             remove_task(command);

        } else if (strcmp(user_input, "-c") == 0) {
            completes_task(command);

        } else if (strcmp(user_input, "-p") == 0) {
            priority_to_task(command);

        } else if (strcmp(user_input, "-lp") == 0) {
            list_tasks_priority(command);

        } else {
            printf("Wrong task name. Look at the possible tasks again.");
            menu();
        }


    }
    while (strcmp(user_input, "exit") != 0);

    return 0;
}
