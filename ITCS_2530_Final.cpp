// ITCS_2530_Final.cpp 
// Maureen Renaud
// Joshua Quintano

#include <iostream>
#include <string>

using namespace std;

//Structures
struct bookRecord
{
    int ID;
    string Title;
    string authorLast;
};

struct patronRecord
{
    int ID;
    string firstName;
    string lastName;
};

//Stubs
void addBook(bookRecord list[]);
void deleteBook(bookRecord list[]);
void addPatron(patronRecord list[]);
void deletePatron(patronRecord list[]);
void borrowBook(bookRecord list[]);
void returnBook(bookRecord list[]);
void checkAccount(bookRecord list[]);

//Constants
const int BOOK_ARRAY_SIZE = 100;
const int PATRON_ARRAY_SIZE = 100;

//Main
int main()
{
    //Variables

    //Arrays
    bookRecord bookList[BOOK_ARRAY_SIZE];
    patronRecord patronList[PATRON_ARRAY_SIZE];
    bookRecord patronAccount[BOOK_ARRAY_SIZE];
    

    return 0;
}

void addBook(bookRecord list[])
{
    cout << "Title of Book: ";
    

};

void deleteBook(bookRecord list[]) 
{

};

void addPatron(patronRecord list[]) 
{

};

void deletePatron(patronRecord list[]) 
{

};

void borrowBook(bookRecord list[]) 
{

};

void returnBook(bookRecord list[])
{

};

void checkAccount(bookRecord list[])
{

};
