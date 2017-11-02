#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Take exercise structures_functions_00.
 * Create an additional structure: Author. This should store Given name and Surname of the author.
 * Rewrite the previous exercise to work with this new structure.  */

typedef struct{
    char given_name[50];
    char surname[50];
} Author;

typedef struct{
    char title[50];
    int publishing_year;
    Author author_name;
} book;

void change_title(book *library)
{
    strcpy(library[0].title, "one title");
    strcpy(library[1].title, "two title");
    strcpy(library[2].title, "three title");
    strcpy(library[3].title, "four title");
}

void change_author(book *library)
{
    strcpy(library[0].author_name.given_name, "Ali");
    strcpy(library[0].author_name.surname, "Baba");
    strcpy(library[1].author_name.given_name, "Dave");
    strcpy(library[1].author_name.surname, "Mirra");
    strcpy(library[2].author_name.given_name, "Chester");
    strcpy(library[2].author_name.surname, "Bennington");
    strcpy(library[3].author_name.given_name, "Matt");
    strcpy(library[3].author_name.surname, "Hoffman");
}

void change_publishing_year(book *library)
{
    library[0].publishing_year = 20160812;
    library[1].publishing_year = 20160731;
    library[2].publishing_year = 20170218;
    library[3].publishing_year = 20070421;
}

int main()
{
    book library[10] = {0};

    change_title(library);
    change_author(library);
    change_publishing_year(library);

    int i = 0;
    for(i = 0; i< 4; i++){
        printf("Book %d title : %s\n", i+1, library[i].title);
        printf("Book %d author : %s %s\n", i+1, library[i].author_name.given_name, library[i].author_name.surname);
        printf("Book %d publishing year : %d\n", i+1, library[i].publishing_year);
    }

    return 0;
}
