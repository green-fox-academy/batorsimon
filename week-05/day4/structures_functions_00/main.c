#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Create a structure representing the data of a book:
 *    * Title
 *    * Author
 *    * Year of publication
 *
 * Create functions for:
 *    * Creating a new book.
 *    * Changeing or setting the Title
 *    * Changeing or setting the Author
 *    * Changeing or setting the Year of publication
 *    * Getting each of these separately by a singel function each.
 *
 * IMPORTANT: The first parameter of each function should be a "Book", a variable of the type of this structure.
 * Create a main where You demonstrate that each of these works and print out the necessary info.
 * IMPORTANT: You should only print from the main function. All other functions should return the info needed.  */

typedef struct{
    char title[50];
    char author[50];
    int publishing_year;
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
    strcpy(library[0].author, "Ali Baba");
    strcpy(library[1].author, "Dave Mirra");
    strcpy(library[2].author, "Chester Bennington");
    strcpy(library[3].author, "Matt Hoffman");
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
        printf("Book %d author : %s\n", i+1, library[i].author);
        printf("Book %d publishing year : %d\n", i+1, library[i].publishing_year);
    }

    return 0;
}
