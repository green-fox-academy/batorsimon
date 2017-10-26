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

int main()
{
    char user_input[80];

    menu();

    do {
        input(user_input);

        if (strcmp(user_input, "-a") == 0) {
            printf("Adds a new task!\n");

        } else if (strcmp(user_input, "-wr") == 0) {
             printf("Write current todos to file!\n");

        } else if (strcmp(user_input, "-rd") == 0) {
            printf("Read todos from a file!\n");

        } else if (strcmp(user_input, "-l") == 0) {
             printf("Lists all the tasks!\n");

        } else if (strcmp(user_input, "-e") == 0) {
             printf("Empty the list!\n");

        } else if (strcmp(user_input, "-rm") == 0) {
             printf("Removes a task!\n");

        } else if (strcmp(user_input, "-c") == 0) {
            printf("Completes a task!\n");

        } else if (strcmp(user_input, "-p") == 0) {
            printf("Add priority to a task!\n");

        } else if (strcmp(user_input, "-lp") == 0) {
            printf("Lists all the tasks by priority!\n");

        } else {
            printf("Wrong task name. Look at the possible tasks again.");
            menu();
        }


    }
    while (strcmp(user_input, "exit") != 0);

    return 0;
}
