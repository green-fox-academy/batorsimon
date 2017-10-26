#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void menu()
{
    printf("        Todo application\n");
    printf("========================================\n");
    printf("Commands:\n");
    printf(" -a   Adds a new task\n");
    printf(" -wr  Write current todos to file\n");
    printf(" -rd  Read todos from a file\n");
    printf(" -l   Lists all the tasks\n");
    printf(" -e   Empty the list\n");
    printf("-rm   Removes a task\n");
    printf(" -c   Completes a task\n");
    printf(" -p   Add priority to a task\n");
    printf(" -lp  Lists all the tasks by priority\n");
    printf("=========================================\n");
}
int main()
{
    menu();
    Sleep(5000);
    system("cls");

    while(1) {


    }

    return 0;
}
