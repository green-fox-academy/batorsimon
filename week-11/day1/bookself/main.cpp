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

typedef struct
{
    string a;
    string b;
    string c;
}Mystruct;

Mystruct myfun();


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
    ms2 = myfun();
     cout << ms2.a << ms2.b << ms2.c << endl;

/*
     for(unsigned int i = 0; i < bs.get_counter()-1; ++i){
            cout << bs.list_books(&bk, i) << endl;
        //cout << i+1 << ". book. Name: " << book.at(i).get_name() << ". Year of publication: " << book.at(i).get_year_of_publication() << ". It is: " << book.at(i).get_number_of_pages() << " pages long." << endl;
    }

*/
    return 0;
}

Mystruct myfun()
{
    string a;
    string b;
    string c;
    Mystruct ms;

    a = "name";
    b = "year";
    c = "length";
    ms.a = a;
    ms.b = b;
    ms.c = c;

    return(ms);
}
