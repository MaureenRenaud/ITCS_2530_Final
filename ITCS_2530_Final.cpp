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

struct borrowedRecord
{
    int bookID;
    string title;
    string authorLast;
    int patronID;
    string patronfirstName;
    string patronlastName;

};

//Stubs
bool StoreData(string file_name, bookRecord list[], int arraySize);
void addBook(bookRecord list[]);
void deleteBook(bookRecord list[]);
void addPatron(patronRecord list[]);
void deletePatron(patronRecord list[]);
void borrowBook(borrowedRecord list[]);
void returnBook(borrowedRecord list[]);
void checkAccount(bookRecord list[]);

//Constants
const int BOOK_ARRAY_SIZE = 25;
const int PATRON_ARRAY_SIZE = 25;
string book_file_name = "Books.txt";
string patron_file_name = "Patrons.txt";

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
    cout << "Check borrowed books (CBB)." << endl;
    cout << "Check account(CA)." << endl << endl;
}

bool StoreData(string file_name, bookRecord list[], int arraySize)
{
    int i = 0;
    //Opening File
    ifstream fs(file_name);
    
    if (!fs.is_open())
    {
        cout << "Could not open file.  Program is exiting." << endl;
        return false;
    }
    //read data
    else
        for (i = 0; i < arraySize; i++)
        {
            fs >> list[i].ID;
            getline(fs, list[i].title, '.');
            fs >> list[i].authorLast;
        }
  
    //Closing file
    fs.close();
    return true;
}
bool StoreDataPatron(string file_name, patronRecord patronlist[], int arraySize) {
    int i = 0;
    //Opening File
    ifstream fs(file_name);

    if (!fs.is_open())
    {
        cout << "Could not open file.  Program is exiting." << endl;
        return false;
    }
    //Read data
    else
        for (i = 0; i < arraySize; i++)
        {
            fs >> patronlist[i].ID;
            fs.ignore(1, ' ');
            getline(fs, patronlist[i].firstName, ' ');
            fs >> patronlist[i].lastName;

        }



    //Closing file
    fs.close();
    return true;
}

void addBook(bookRecord list[])
{
    int len;
    int i;

    len = sizeof(list);
    i = len + 2;

    cout << "Please enter the ID number of the book: ";
    cin >> list[i].ID;
    cin.ignore();
    cout << "Please enter the title of the book followed by an asterisk(*): ";
    getline(cin, list[i].title, '*');
    cin.ignore();
    cout << "Please enter the author's last name: ";
    cin >> list[i].authorLast;

    cout << endl;

}

void deleteBook(bookRecord list[])
{
    int len;
    int i;
    int ID_num;
    int index = 0;

    len = sizeof(list);

    cout << "Please enter the ID number of the book: ";
    cin >> ID_num;

    for (int i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        if (list[i].ID == ID_num)
        {
            //If current value is equal to our element then replace the index value and break the loop
            index = i;
        }
    }
    list[index].ID = 0;
    list[index].title = " ";
    list[index].authorLast = " ";
}

void addPatron(patronRecord list[])
{
    int len;
    int i;

    len = sizeof(list);
    i = len + 2;

    cout << "Please enter the patron's ID number: ";
    cin >> list[i].ID;

    cout << "Please enter the patron's first name: ";
    cin >> list[i].firstName;

    cout << "Please enter the patron's last name: ";
    cin >> list[i].lastName;

}

void deletePatron(patronRecord list[])
{

}

void borrowBook(borrowedRecord list[])
{
    int len;
    int i;

    len = sizeof(list);
    i = len + 1;

    cout << "Please enter the ID number of the book: ";
    cin >> list[i].bookID;
    cin.ignore();
    cout << "Please enter the title of the book followed by an asterisk(*): ";
    getline(cin, list[i].title, '*');
    cin.ignore();
    cout << "Please enter the author's last name: ";
    cin >> list[i].authorLast;
    cout << "Please enter the ID number of the patron: ";
    cin >> list[i].patronID;
    cin.ignore();
    cout << "Please enter patron's first name: ";
    cin >> list[i].patronfirstName;
    cin.ignore();
    cout << "Please enter the patron's last name: ";
    cin >> list[i].patronlastName;

    cout << endl;
}

void returnBook(borrowedRecord list[])
{
    //Property props[10];
    int prop_count = 0;
    int returned;
    int ID_num;
    int index = 0;
    int j = 0;

    // Fill props somehow, incrementing prop_count each time you add an item
    cout << "Please enter the ID for the returned book: ";
    cin >> returned;

  
    for (int i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        if (list[i].bookID == returned)
        {
            //If current value is equal to our element then replace the index value and break the loop
            index = i;
        }
    }
    for (int j = index + 1; j < BOOK_ARRAY_SIZE; j++) {
        list[j - 1] = list[j];
    }
    
}

void checkAccount(bookRecord list[])
{
    int i = 0;
    for (i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        cout << list[i].ID << ("..") << list[i].title << ("..") << list[i].authorLast << endl;
    }

}

void checkBorrowedBooks(borrowedRecord list[])
{
    int i = 0;
    for (i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        if (list[i].bookID != 0)
        {
            cout << list[i].bookID << ("..") << list[i].title << ("..") << list[i].authorLast << endl;
            cout << list[i].patronfirstName << ("..") << list[i].patronlastName << endl;
        }
    }

}

//Main
int main()
{
    //int argc, char* argv[]
    //Variables
    //string bookfile = argv[1];
    //string patronfile = argv[2];
    string input;

    //Arrays
    bookRecord bookList[BOOK_ARRAY_SIZE];
    patronRecord patronList[PATRON_ARRAY_SIZE];
    borrowedRecord borrowedBooks[BOOK_ARRAY_SIZE];
    
    //function calls
    StoreData(book_file_name, bookList, BOOK_ARRAY_SIZE);
    StoreDataPatron(patron_file_name, patronList, PATRON_ARRAY_SIZE);
    PrintMenu();

    while (input != "q")
    {
        cout << "Please make a selection: ";
        cin >> input;

        if (input == "AB")
        {
            cin.ignore();
            addBook(bookList);
        }
        else if (input == "DB")
        {
            cin.ignore();
            deleteBook(bookList);
        }
        else if (input == "AP")
        {
            cin.ignore();
            addPatron(patronList);
        }
        else if (input == "DP")
        {
            cin.ignore();
            cout << "check";
        }
        else if (input == "BB")
        {
            cin.ignore();
            borrowBook(borrowedBooks);
        }
        else if (input == "RB")
        {
            cin.ignore();
            returnBook(borrowedBooks);
        }
        else if (input == "CBB")
        {
            cin.ignore();
            checkBorrowedBooks(borrowedBooks);
        }
        else if (input == "CA")
        {
            checkAccount(bookList);
            
        }
        else {
            cout << "Thank you!";
            //exit(0);
        }
    }
    return 0;
}



