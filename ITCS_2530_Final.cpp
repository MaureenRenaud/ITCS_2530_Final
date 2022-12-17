// ITCS_2530_Final.cpp 
// Maureen Renaud
// Joshua Quintano

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Structures

//This structure holds an ID number, title, and author for each book
struct bookRecord
{
    int ID;
    string title;
    string authorLast;
};

//This structure holds an ID number, first name, and last name for each author
struct patronRecord
{
    int ID;
    string firstName;
    string lastName;
    
};

//This structure holds an book ID, book title, book author, patron ID, patron first name, and patron last name
//for borrowed books
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
void PrintMenu();
bool StoreData(string file_name, bookRecord list[], int arraySize);
bool StoreDataPatron(string file_name, patronRecord patronlist[], int arraySize);
void addBook(bookRecord list[]);
void deleteBook(bookRecord list[]);
void addPatron(patronRecord list[]);
void deletePatron(patronRecord list[]);
void borrowBook(borrowedRecord list[]);
void returnBook(borrowedRecord list[]);
void checkAccount(borrowedRecord list[]);
void checkBookList(bookRecord list[]);
void checkBorrowedBooks(borrowedRecord list[]);

//Constants
const int BOOK_ARRAY_SIZE = 25;
const int PATRON_ARRAY_SIZE = 25;
string book_file_name = "Books.txt";
string patron_file_name = "Patrons.txt";

//This function prints Library Services at the top and lists the menu options
//Joshua Quintano

void PrintMenu()
{
    //prints menu
    cout << setw(28) << setfill('*') << '*' << endl;
    cout << setw(5) << setfill('*') << '*' << " Library Services " << setw(5) << setfill('*') << '*' << endl;
    cout << setw(28) << setfill('*') << '*' << endl << endl;

    string input;
   
    //prints menu options
    cout << "Add book to book list(AB)." << endl;
    cout << "Delete book from booklist(DB)." << endl;
    cout << "Add patron to patron list(AP)." << endl;
    cout << "Delete patron from patron list(DP)." << endl;
    cout << "Borrow book(BB)." << endl;
    cout << "Return book(RB)." << endl;
    cout << "Check borrowed books (CBB)." << endl;
    cout << "Check patron list(CP)." << endl;
    cout << "To check the record of all books (All). " << endl;
    cout << "Check account(CA)." << endl << endl;
}

//This function opens up the file of books and writes the data to an array of structures.
//Maureen Renaud and Joshua Quintano

bool StoreData(string file_name, bookRecord list[], int arraySize)
{
    int i = 0;
    //Opening File
    ifstream fs(file_name);
    
    if (!fs.is_open())
    {
        // Error Message is File is unable to be opened
        cout << "Could not open file.  Program is exiting." << endl;
        return false;
    }
    //This reads each line of data into an ID for the book, title for book, and author last name
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

//This function opens up the file of patrons and writes the data to an array of structures.
//Joshua Quintano

bool StoreDataPatron(string file_name, patronRecord patronlist[], int arraySize) 
{
    int i = 0;
    //Opening File
    ifstream fs(file_name);

    if (!fs.is_open())
    {
        //Error message if file can't be opened
        cout << "Could not open file.  Program is exiting." << endl;
        return false;
    }
    //Read each line of data into patron ID, patron first name, and patron last name
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

//This function adds a book to the master list of books
//Maureen Renaud

void addBook(bookRecord list[])
{
    int index;
    int i;

    //This looks for the index of the first line of blank rows (with zeroes instead of entries)
    for (int i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        if (list[i].ID == 0)
        {
            index = i;
        }
    }

    //This overwrites the blank row with data about the book

    cout << "Please enter the ID number of the book: ";
    cin >> list[index].ID;
    cin.ignore();
    cout << "Please enter the title of the book followed by an asterisk(*): ";
    getline(cin, list[index].title, '*');
     
    cout << "Please enter the author's last name: ";
    cin >> list[index].authorLast;
    
    //Print result
    cout << endl << "Book " << list[index].title << " added to the master list of books." << endl << endl;
}

//This function will delete an entry from the master list of books
//Maureen Renaud

void deleteBook(bookRecord list[])
{
    int i, j;
    int ID_num;
    int index = 0;

    cout << "Please enter the ID number of the book: ";
    cin >> ID_num;

    //This looks for the index of the book that is to be deleted
    for (int i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        if (list[i].ID == ID_num)
        {
            index = i;
        }
    }

    //Print result
    cout << endl << list[index].title << " successfully deleted." << endl << endl;

    //This moves everything above the line to be deleted down a spot in the array, so that the
    //deleted item is overwritten

    for (int j = index + 1; j < PATRON_ARRAY_SIZE; j++) 
    {
        list[j - 1] = list[j];
    }
 
}

//This function adds a patron to the master list of patrons
//Maureen Renaud

void addPatron(patronRecord list[])
{
    int index;
    int i;

    //This looks for the first row that does not have data (is full of zeroes) and finds the index of that row
    for (int i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        if (list[i].ID == 0)
        {
            index = i;
        }
    }

    //Add the patron information to that empty row
    cout << "Please enter the patron's ID number: ";
    cin >> list[index].ID;
    cin.ignore();
    cout << "Please enter the patron's first name: ";
    cin >> list[index].firstName;
    cin.ignore();
    cout << "Please enter the patron's last name: ";
    cin >> list[index].lastName;

    cout << endl << "Patron " << list[index].firstName << " " << list[index].lastName 
        << " added to the master list of patrons." << endl << endl;
}

//This function deletes a patron from the master list of patrons
//Maureen Renaud

void deletePatron(patronRecord list[])
{
    //Variables
    int deleted;
    int ID_num;
    int index = 0;
    int j = 0;

    // Describe
    cout << "Please enter the ID for the patron to be deleted: ";
    cin >> deleted;

    //This looks for the index of the patron to be deleted

    for (int i = 0; i < PATRON_ARRAY_SIZE; i++)
    {
        if (list[i].ID == deleted)
        {
            index = i;
        }
    }

    //Print result
    cout << endl << list[index].firstName << " " << list[index].lastName
        << " successfully deleted." << endl << endl;

   //This moves everything above the line to be deleted down a spot in the array, so that the
   //deleted item is overwritten

    for (int j = index + 1; j < PATRON_ARRAY_SIZE; j++) {
        list[j - 1] = list[j];
    }

}

//This function inputs information into an array of structures containing information on borrowed books
//Maureen Renaud

void borrowBook(borrowedRecord list[])
{
    //Variables
    int i, index;

    //This function looks for the index number of the first blank row in this array
    for (int i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        if (list[i].bookID == 0)
        {
            index = i;
        }
    }
    
    //This adds information to the blank strucutre in that array of borrowed books
    cout << "Please enter the ID number of the book: ";
    cin >> list[index].bookID;
    cin.ignore();
    cout << "Please enter the title of the book followed by an asterisk(*): ";
    getline(cin, list[index].title, '*');
    cin.ignore();
    cout << "Please enter the author's last name: ";
    cin >> list[index].authorLast;
    cout << "Please enter the ID number of the patron: ";
    cin >> list[index].patronID;
    cin.ignore();
    cout << "Please enter patron's first name: ";
    cin >> list[index].patronfirstName;
    cin.ignore();
    cout << "Please enter the patron's last name: ";
    cin >> list[index].patronlastName;

    cout << endl;

    //Print Result
    cout << list[index].title << " successfully check out to patron: " << list[index].patronfirstName
        << " " << list[index].patronlastName << endl << endl;
}

//This function removes a book from the array of borrowed books
//Maureen Renaud

void returnBook(borrowedRecord list[])
{
    //Variables
    int returned;
    int ID_num;
    int index = 0;
    int j = 0;

    // Get the ID for the book to be returned
    cout << "Please enter the ID for the returned book: ";
    cin >> returned;

   //Find the index number of the book to be returned
    for (int i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        if (list[i].bookID == returned)
        {
            index = i;
        }
    }

    //Print Result
    cout << list[index].title << " successfuly returned." << endl << endl;

    //Move everything in the rows above returend book down a line so that it overwrites the information 
    //for the returned book

    for (int j = index + 1; j < BOOK_ARRAY_SIZE; j++) {
        list[j - 1] = list[j];
    }
    
}

//Find information on the items checked out be a patron
//Joshua Quintano

void checkAccount(borrowedRecord list[])
{  
    int id; 
    int j = 0;
    int k = 0;
    string accountbooks[100];
    
    cout << "Please enter an ID number: ";
    cin >> id;

    //loop that searches for matching id and adds respective book to the array
    for (int i = 0; i< BOOK_ARRAY_SIZE; i++){
        if (id = list[i].patronID) {
            accountbooks[j] = list[i].title;
            j = j + 1;            
        }
        else
            continue;
       

    }
    //opens new file
    ofstream newfile("account.txt");
    for (int k = 0; k < j+1; k++) 
    {
        //prints output to new file and program output screen
        cout << accountbooks[k] << endl;
        newfile << accountbooks[k] << endl;
    }
    
}

//Find information by books on the master list of the library
//Maureen Renaud

void checkBookList(bookRecord list[])
{
    cout << "Books Owned By The Library" << endl;
    int i = 0;

    //If the row contains zeroes, skip over it
    for (i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        if (list[i].ID == 0)
        {
            continue;
        }

        //If it contains information, print it out
        else
        {
            cout << list[i].ID << (". ") << list[i].title << (" ") << list[i].authorLast << endl;
        }
    }
}

//Find the list of all books that have been borrowed
//Maureen Renaud

void checkBorrowedBooks(borrowedRecord list[])
{
    cout << "Borrowed Books: " << endl;

    int i = 0;
    for (i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        //If a row has no data, skip over it
        if (list[i].bookID == 0)
        {
            continue;
        }
        else
        {
            //Print out rows with data
            cout << list[i].bookID << (". ") << list[i].title << (" ") << list[i].authorLast << endl;
            cout << "Check out by: " << list[i].patronfirstName << ("..") << list[i].patronlastName << endl;
        }
        
       
    }

}

//Check master list of patrons
//Maureen Renaud

void checkPatrons(patronRecord list[])
{
    cout << "List of patrons: " << endl;
    int i = 0;
    for (i = 0; i < PATRON_ARRAY_SIZE; i++)
    {
        //If a row has no information, skip over it
        if (list[i].ID == 0)
        {

            continue;
        }
        else
        {
            //Print the rows with data
            cout << list[i].ID << (". ") << list[i].firstName << (" ") << list[i].lastName << endl;
        }
    }
}

//Main
//Joshua Quintano and Maureen Renaud
int main(int argc, char* argv[])
{
    //assigns command line arguments to variables
    string book_file_name = argv[1];
    string patron_file_name = argv[2];
    
    string input;
    int i;

    //Arrays
    bookRecord bookList[BOOK_ARRAY_SIZE];
    patronRecord patronList[PATRON_ARRAY_SIZE];
    borrowedRecord borrowedBooks[BOOK_ARRAY_SIZE];
    
    //Initialize all rows in the borrowed book array to zero
    for (i = 0; i < BOOK_ARRAY_SIZE; i++)
    {
        borrowedBooks[i].bookID = 0;
        borrowedBooks[i].title = " ";
        borrowedBooks[i].authorLast = " ";
        borrowedBooks[i].patronID = 0;
        borrowedBooks[i].patronfirstName = " ";
        borrowedBooks[i].patronlastName =  " ";

    }
    
    //function calls to pull data in from the files and print the menu
    StoreData(book_file_name, bookList, BOOK_ARRAY_SIZE);
    StoreDataPatron(patron_file_name, patronList, PATRON_ARRAY_SIZE);
    PrintMenu();

    //Menu to select desired action
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
            deletePatron(patronList);
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
            checkAccount(borrowedBooks);
            
        }
        else if (input == "CP")
        {
            cin.ignore();
            checkPatrons(patronList);
        }
        else if (input == "All")
        {
            cin.ignore();
            checkBookList(bookList);
        }

        else 
        {
            cout << "I don't understand. Please make a selection: ";
            cin >> input;
        }
    }
    return 0;
}


//Unused Code
    //int argc, char* argv[]
    //Variables
    //string bookfile = argv[1];
    //string patronfile = argv[2];
