// ITCS_2530_Final.cpp 
// Maureen Renaud
// Joshua Quintano

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Structures
struct bookRecord
{
    int ID;
    string title;
    string authorLast;
};

struct patronRecord
{
    int ID;
    string firstName;
    string lastName;
    
};

//Stubs
bool StoreData(string file_name, bookRecord list[], int arraySize);
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
string book_file_name = "Books.txt";
string patron_file_name = "Patrons.txt";


//Main
int main()
{
    //Variables

    //Arrays
    bookRecord bookList[BOOK_ARRAY_SIZE];
    patronRecord patronList[PATRON_ARRAY_SIZE];
    bookRecord patronAccount[BOOK_ARRAY_SIZE];
    bookRecord borrowedBooks[BOOK_ARRAY_SIZE];
    
    //function calls
    PrintMenu();
    return 0;
}

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


bool StoreData(string file_name, bookRecord list[], int arraySize)
{
    int i = 0;

    //Opening File
    ifstream fs;
    fs.open(file_name);
    if (!fs.is_open())
    {
        cout << "Could not open file.  Program is exiting." << endl;
        return false;
    }
    else
        cout << endl;
  
        //Read data
    while (!fs.eof())
    {
        for (i = 0; i < arraySize; i++)
        {
            fs >> list[i].ID;
            getline(fs, list[i].title, '"');
            fs >> list[i].authorLast;
            
        }
    }
    //Closing file
    fs.close();
    return true;
}

void addBook(bookRecord list[])
{
    int len;
    int i;

    len = sizeof(list) / sizeof(list[0]);
    i = len + 1;
  
    cout << "Please enter the title of the book: ";
    cin >> list[i].title;

    cout << "Please enter the author's last name: ";
    cin >> list[i].authorLast;

};

void deleteBook(bookRecord list[]) 
{

};

void addPatron(patronRecord list[]) 
{
    int len;
    int i;

    len = sizeof(list) / sizeof(list[0]);
    i = len + 1;

    cout << "Please enter the patron's ID number: ";
    cin >> list[i].ID;

    cout << "Please enter the patron's first name: ";
    cin >> list[i].firstName;

    cout << "Please enter the patron's last name: ";
    cin >> list[i].lastName;

};

void deletePatron(patronRecord list[]) 
{

};

void borrowBook(bookRecord list[])
{
    int len;
    int i;

    len = sizeof(list) / sizeof(list[0]);
    i = len + 1;

    cout << "Please enter the title of the book: ";
    cin >> list[i].title;

    cout << "Please enter the author's last name: ";
    cin >> list[i].authorLast;
};

void returnBook(bookRecord list[])
{

};

void checkAccount(bookRecord list[])
{

};
