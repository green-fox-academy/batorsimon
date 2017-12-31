#include <string>
#include "book.h"

using namespace std;


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

