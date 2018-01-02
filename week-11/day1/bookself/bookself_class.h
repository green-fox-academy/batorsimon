#ifndef BOOKSELF_CLASS_H_INCLUDED
#define BOOKSELF_CLASS_H_INCLUDED

#include <string>
#include <vector>
#include "book.h"

using namespace std;

typedef struct
{
    string a;
    int b;
    int c;

}Mystruct;


class Bookself{
    private:
        int counter;
        vector<Book> book;

    public:
        Bookself();
        Bookself(int counter);
        ~Bookself();
        void add(Book *bk);
        int get_oldest(Book *bk);
        int get_longest(Book *bk);
        void set_counter(int counter);
        int get_counter();
        void list_books(Book *bk);
        Mystruct myfun(Book *bk, int i);
};

#endif // BOOKSELF_CLASS_H_INCLUDED
