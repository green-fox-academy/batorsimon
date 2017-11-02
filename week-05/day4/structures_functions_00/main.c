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

void create_new_book(struct Book books)
{
    struct Book books1;
    struct Book books2;
    struct Book books3;
    struct Book books4;
}

void change_title(struct Book books)
{
    strcpy( books1.title, "one title");
    strcpy( books2.title, "two title");
    strcpy( books3.title, "three title");
    strcpy( books4.title, "four title");
}

void change_author(struct Book books)
{
    strcpy( books1.author, "Ali Baba");
    strcpy( books2.author, "Dave Mirra");
    strcpy( books3.author, "Chester Bennington");
    strcpy( books4.author, "Matt Hoffman");
}

void change_publishing_year(struct Book books)
{
    books1.publishing_year = 20160812;
    books2.publishing_year = 20160731;
    books3.publishing_year = 20170218;
    books4.publishing_year = 20070421;
}

int main()
{
    struct Book {
    char  title[50];
    char  author[50];
    int   publishing_year;
    };

    struct Book books1;
    struct Book books2;
    struct Book books3;
    struct Book books4;


    void create_new_book();
    void change_title();
    void change_author();
    void change_publishing_year();


    printf("Book 1 title : %s\n", books1.title);
    printf("Book 1 author : %s\n", books1.author);
    printf("Book 1 publishing year : %d\n", books1.publishing_year);

    printf("Book 2 title : %s\n", books2.title);
    printf("Book 2 author : %s\n", books2.author);
    printf("Book 2 publishing year : %d\n", books2.publishing_year);

    printf("Book 3 title : %s\n", books3.title);
    printf("Book 3 author : %s\n", books3.author);
    printf("Book 3 publishing year : %d\n", books3.publishing_year);

    printf("Book 4 title : %s\n", books4.title);
    printf("Book 4 author : %s\n", books4.author);
    printf("Book 4 publishing year : %d\n", books4.publishing_year);

    return 0;
}
