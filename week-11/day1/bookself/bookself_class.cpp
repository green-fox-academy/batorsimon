#include <iostream>
#include <string>
#include <vector>

#include "bookself_class.h"

using namespace std;

Bookself::Bookself() {};

Bookself::Bookself(int counter){
    this->counter = counter;
};

void Bookself::add(Book *bk){
    book.push_back(*bk);
    counter++;
};

int Bookself::get_longest(Book *bk){
    int result = 0;

    for(unsigned int i = 0; i < book.size(); ++i){
        if(book.at(i).get_number_of_pages() > result) {
            result = book.at(i).get_number_of_pages();
        }
    }

    return result;
};

int Bookself::get_oldest(Book *bk){
    int result = 0;

    for(unsigned int i = 0; i < book.size(); ++i){
        if(book.at(i).get_year_of_publication() > result){
            result = book.at(i).get_year_of_publication();
        }
    }

    return result;
};

void Bookself::set_counter(int counter){
    this->counter = counter;
};

int Bookself::get_counter() {
    return counter;
};

void Bookself::list_books(Book *bk){
    for(unsigned int i = 0; i < book.size(); ++i){
        cout << i+1 << ". book. Name: " << book.at(i).get_name();
        cout << ". Year of publication: " << book.at(i).get_year_of_publication();
        cout << ". It is: " << book.at(i).get_number_of_pages() << " pages long." << endl;
    }

};

Mystruct Bookself::myfun(Book *bk, int i)
{
    string a;
    int b;
    int c;
    Mystruct ms;

    a = book.at(i).get_name();
    b = book.at(i).get_year_of_publication();
    c = book.at(i).get_number_of_pages();

    ms.a = a;
    ms.b = b;
    ms.c = c;

    return(ms);
}
