#include <stdio.h>
#include <stdlib.h>

typedef enum {NOVEL, BOOK, PAPER, POEM} types;

typedef struct {
    char title[30];
    char author[50];
    int year_of_publication;
    types type;
} books;

void print_year_of_publication(books *book, int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        printf("%d\n", book[i].year_of_publication);
    }
}

int get_oldest_of_a_type(books *book, int len, types type)
{
    int age = 0;
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (type == book[i].type)
        {
            if (age < book[i].year_of_publication)
            {
                age = book[i].year_of_publication;
            }
        }
    }
    return age;
}

void change_year_of_publication(books *book, int index, int new_age)
{
    book[index].year_of_publication = new_age;
}

int main()
{
    books b1 = {"Stuff", "Gibsz Jakab", 1999, BOOK};
    books b2 = {"other stuff", "John Doe", 2002, PAPER};
    books b3 = {"get things done", "Poe", 1919, PAPER};
    books b4 = {"this is fun", "You did this", 1979, POEM};

    books book[] = {b1, b2, b3, b4};

    int len = sizeof(book)/sizeof(book[0]);

    printf("%d\n", book[1].year_of_publication);
    change_year_of_publication(book, 1, 2023);
    printf("%d\n", book[1].year_of_publication);

    //print_year_of_publication(book, len);
    //printf("6the oldest PAPER is %d years old", get_oldest_of_a_type(book, len, PAPER));

    return 0;
}
