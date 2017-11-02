#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Create a structure representing the data of a book:
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
 *
 * Create a main where You demonstrate that each of these works and print out the necessary info.
 * IMPORTANT: You should only print from the main function. All other functions should return the info needed.
 */

void create_new_book(struct Book book)
{
    struct Book book1;
    struct Book book2;
    struct Book book3;
    struct Book book4;
}

void change_title(struct Book book)
{
    strcpy( book1.title, "one title");
    strcpy( book2.title, "two title");
    strcpy( book3.title, "three title");
    strcpy( book4.title, "four title");
}

void change_author(struct Book book)
{
    strcpy( book1.author, "Ali Baba");
    strcpy( book1.author, "Dave Mirra");
    strcpy( book1.author, "Chester Bennington");
    strcpy( book1.author, "Matt Hoffman");
}

void change_publishing_year(struct Book book)
{
    book1.publishing_year = 20160812;
    book2.publishing_year = 20160731;
    book3.publishing_year = 20170218;
    book4.publishing_year = 20070421;
}

int main()
{
    struct Book {
    char  title[50];
    char  author[50];
    int   publishing_year;
    };

    void create_new_book();
    void change_title();
    void change_author();
    void change_publishing_year();


    printf( "Book 1 title : %s\n", book1.title);
    printf( "Book 1 author : %s\n", book1.author);
    printf( "Book 1 subject : %s\n", book1.publishing_year);

    printf( "Book 2 title : %s\n", book2.title);
    printf( "Book 2 author : %s\n", book2.author);
    printf( "Book 2 subject : %s\n", book2.publishing_year);

    printf( "Book 3 title : %s\n", book3.title);
    printf( "Book 3 author : %s\n", book3.author);
    printf( "Book 3 subject : %s\n", book3.publishing_year);

    printf( "Book 4 title : %s\n", book4.title);
    printf( "Book 4 author : %s\n", book4.author);
    printf( "Book 4 subject : %s\n", book4.publishing_year);

    return 0;
}
