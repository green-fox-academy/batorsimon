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

Book::Book() {};

Book::Book(string name, int year_of_publication, int number_of_pages){
    this->name = name;
    this->year_of_publication = year_of_publication;
    this->number_of_pages = number_of_pages;
};

string Book::get_name(){
    return name;
};

void Book::set_name(string name){
    this->name = name;
};

int Book::get_year_of_publication() {
    return year_of_publication;
};

void Book::set_year_of_publication(int year_of_publication) {
     this->year_of_publication = year_of_publication;
};

int Book::get_number_of_pages(){
    return number_of_pages;
};

void Book::set_number_of_pages(int number_of_pages){
    this->number_of_pages = number_of_pages;
};


class Bookself{
private:
    int counter;
    vector<Book> book;

public:
    Bookself();
    Bookself(int counter);
    void add(Book *bk);
    int get_oldest(Book *bk);
    int get_longest(Book *bk);
    void set_counter(int counter);
    int get_counter();
    void list_books(Book *bk);
};

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
    int result = 3000;

    for(unsigned int i = 0; i < book.size(); ++i){
        if(book.at(i).get_year_of_publication() < result){
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
    cout << endl << "The books in the self are: " << endl;
    for(unsigned int i = 0; i < book.size(); ++i){
        cout << i+1 << ". book. Name: " << book.at(i).get_name() << ". Year of publication: " << book.at(i).get_year_of_publication() << ". It is: " << book.at(i).get_number_of_pages() << " pages long." << endl;
    }

};


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
    bs.list_books(&bk);

    return 0;
}
