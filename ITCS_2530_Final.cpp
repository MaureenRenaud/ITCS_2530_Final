// ITCS_2530_Final.cpp 
// Maureen Renaud
// Joshua Quintano

#include <iostream>
#include <string>
#include <iomanip>

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

//functions
void PrintMenu()
{
    cout << setw(28) << setfill('*') << '*' << endl;
    cout << setw(5) << setfill('*') << '*' << " Library Services " << setw(5) << setfill('*') << '*' << endl;
    cout << setw(28) << setfill('*') << '*' << endl << endl;

    string input;
    cout << "Add book to book list(AB)." << endl;
    cout << "Delete book from booklist(DB)." << endl;
    cout << "Add patron to patron list(AP)." << endl;
    cout << "Delete patron from patron list(DP)." << endl;
    cout << "Borrow book(BB)." << endl;
    cout << "Return book(RB)." << endl;
    cout << "Check account(CA)." << endl << endl;

    while (input != "q") 
    {  
        cout << "Please make a selection: ";
        cin >> input;
        if (input == "AB")
        {         
            cout << "check";
        }
        else if (input == "DB")
        {
            cout << "check";
        }
        else if (input == "AP")
        {
            cout << "check";
        }
        else if (input == "DP")
        {
            cout << "check";
        }
        else if (input == "BB")
        {
            cout << "check";
        }
        else if (input == "RB") 
        {
            cout << "check";
        }
        else if (input == "CA")
        {
            cout << "check";
        }
        else {
            cout << "Thank you!";
            exit(0);
        }
        
    }   
    
}
//Main
int main()
{
    //Variables

    //Arrays
    bookRecord bookList[BOOK_ARRAY_SIZE];
    patronRecord patronList[PATRON_ARRAY_SIZE];
    bookRecord patronAccount[BOOK_ARRAY_SIZE];
    
    //function calls
    PrintMenu();
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
