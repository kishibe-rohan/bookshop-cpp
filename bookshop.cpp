#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;

class bookshop
{

public:
    void adminPanel();
    void addBook();
    void showBooks();
    void checkBook();
    void updateBook();
    void deleteBook();
};

//function to display admin dashboard
void bookshop::adminPanel()
{

    system("cls");
    cout<<"\n\n\t\t\t\tAdmin Panel";
    cout<<"\n\n 1. Add New Book";
    cout<<"\n 2. Display Books";
    cout<<"\n 3. Check Specific Book";
    cout<<"\n 4. Update Book";
    cout<<"\n 5. Delete Book";
    cout<<"\n 6. Exit";

}


//function to add new book to the store
void bookshop::addBook()
{

    system("cls");
    fstream file;
    int copies;
    string bookName,author,bookId;

    cout<<"\n\n\t\t\t\t Add New Book";
    cout<<"\n\n Book ID : ";
    cin>>bookId;

    cout<<"\n\n\t\t\t Enter Book Name : ";
    cin>>bookName;

    cout<<"\n\n Enter Author Name : ";
    cin>>author;

    cout<<"\n\n\t\t\t No. of Copies : ";
    cin>>copies;

    //save it in local file
    file.open("D://book.txt",ios::out,ios::app);
    file<<" "<<bookId<<" "<<bookName<<" "<<author<<" "<<copies<<"\n";
    file.close();



}
