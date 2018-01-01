// Create a book class.
// This class should have the following variables:
//  - name
//  - year of publication
//  - number of pages
// Create a constructor where you set the variables.
// Create get-set method for each variable.
//
// Create a bookshelf class.
// This class should store all the books we have.
// You should implement the following methods for this class:
//  - get the oldest book
//  - get the longest book

#include <iostream>
#include <string>
#include <vector>

#include "book.h"
#include "bookself_class.h"

using namespace std;


int main()
{
    Book bk;
    Bookself bs;
    bs.set_counter(0);
    bs.add(new Book("RoncsSzelarnyekban", 2017, 88));
    bs.add(new Book("Mesz", 2015, 72));
    bs.add(new Book("AholMegszakad", 2012, 68));

    cout << "There is: " << bs.get_counter() << " books in the self." << endl << endl;
    cout << "The oldest book was published in: " << bs.get_oldest(&bk) << endl;
    cout << "The longest book is: " << bs.get_longest(&bk) << " pages long." << endl;

    cout << endl << "The books on the self are: " << endl;
    bs.list_books(&bk);


    cout << endl << "The books on the self are: " << endl;
    Mystruct ms2;
    for(int i = 0; i < bs.get_counter(); i++){
        ms2 = bs.myfun(&bk, i);
        cout << i+1 << ". book. Name: " << ms2.a << ". Year of publication: " << ms2.b << ". It is: " << ms2.c << " pages long." << endl;
    }

    return 0;
}
