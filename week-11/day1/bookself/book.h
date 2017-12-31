#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <string>

using namespace std;

class Book{
    private:
        string name;
        int year_of_publication;
        int number_of_pages;
    public:
        Book();
        Book(string name, int year_of_publication, int number_of_pages);

        string get_name();
        void set_name(string name);

        int get_year_of_publication();
        void set_year_of_publication(int year_of_publication);

        int get_number_of_pages();
        void set_number_of_pages(int number_of_pages);
};


#endif // BOOK_H_INCLUDED
