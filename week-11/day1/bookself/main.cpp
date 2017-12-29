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
};

Book::Book(string name, int year_of_publication, int number_of_pages){
    this->name = name;
    this->year_of_publication = year_of_publication;
    this->number_of_pages = number_of_pages;
};

class Bookself{
private:
    int counter;
    vector<Book> book;
private:
    Bookself();
    Bookself(int counter);
    void add(Book *bok);
    void get_oldest();
    void get_longest();
};

void Bookself::add(Book *bok){
    book.push_back(*bok);
};

void Bookself::get_longest(){

};

void Bookself::get_oldest(){

};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
