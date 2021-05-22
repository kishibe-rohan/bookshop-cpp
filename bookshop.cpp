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
    file.open("D://book.txt",ios::out|ios::app);
    file<<" "<<bookId<<" "<<bookName<<" "<<author<<" "<<copies<<"\n";
    file.close();
}

//function to display all books
void bookshop::showBooks()
{
    system("cls");
    fstream file;
    int copies;
    string bookName,bookId,author;
    cout<<"\n\n\t\t\t\tDisplaying All Books";
    file.open("D://book.txt",ios::in);
    if(!file)
        cout<<"\n\n File Not Found!!";
    else
    {
        cout<<"\n\n Book ID    Book    Author    No. of Copies\n\n";
        file>>bookId>>bookName>>author>>copies;
    while(!file.eof())
    {
        cout<<"   "<<bookId<<"     "<<bookName<<"     "<<author<<"\t\t"<<copies<<"\n\n";
        file>>bookId>>bookName>>author>>copies;
    }

    file.close();
    }


}

//function to check if a book exists in the store
void bookshop::checkBook()
{

    system("cls");
    fstream file;
    int copies;
    string bookId,bookName,author,findId;
    bool found = false;
    cout<<"\n\n\t\t\t\tCheck Specific Book";
    file.open("D://book.txt",ios::in);
    if(!file)
        cout<<"\n\n File Not Found!! ";
    else{
        cout<<"Enter Book Id:";
        cin>>findId;
        file>>bookId>>bookName>>author>>copies;
        while(!file.eof())
        {
            if(bookId == findId)
            {
                system("cls");
					cout<<"\n\n\t\t\t\t Book Found!";
					cout<<"\n\n Book ID : "<<bookId;
					cout<<"\n\n\t\t\tName : "<<bookName;
					cout<<"\n\n Author : "<<author;
					cout<<"\n\n\t\t\tNo. of Copies : "<<copies;
					found = true;
					break;
            }
            file>>bookId>>bookName>>author>>copies;

        }
        file.close();
        if(found==false)
            cout<<"\n\n Book not found..";

    }


}

//function to find and update book record
void bookshop::updateBook()
{

    system("cls");
		fstream file,file1;
		int copies,no_co,count = 0;
		string bookName,b_na,author,a_na,bookIdd,bookId;
		bool found = false;
		cout<<"\n\n\t\t\t\tUpdate Book Record";
		file1.open("D://book1.txt",ios::app|ios::out);
		file.open("D://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Not Found...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>bookId;
			file>>bookIdd>>bookName>>author>>copies;
			while(!file.eof())
			{
				if(bookId == bookIdd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tUpdate Book Record";
					cout<<"\n\n New Book Name : ";
					cin>>b_na;
					cout<<"\n\n\t\t\tAuthor Name : ";
					cin>>a_na;
					cout<<"\n\n No. of Copies : ";
					cin>>no_co;
					file1<<" "<<bookId<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n";
					count++;
				}
				else
				file1<<" "<<bookIdd<<" "<<bookName<<" "<<author<<" "<<copies<<"\n";
				file>>bookIdd>>bookName>>author>>copies;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("D://book.txt");
		rename("D://book1.txt","D://book.txt");
}

void bookshop::deleteBook()
{

    system("cls");
    fstream file,file1;
		int copies,count=0;
		string bookId,bookIdd,bookName,author;
		cout<<"\n\n\t\t\t\tDelete Book Record";
		file1.open("D://book1.txt",ios::app|ios::out);
		file.open("D://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Not Found...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>bookId;
			file>>bookIdd>>bookName>>author>>copies;
			while(!file.eof())
			{
				if(bookId == bookIdd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tDelete Book Record";
					cout<<"\n\n One Book is Deleted Successfully...";
					count++;
				}
				else
				file1<<" "<<bookIdd<<" "<<bookName<<" "<<author<<" "<<copies<<"\n";
				file>>bookIdd>>bookName>>author>>copies;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("D://book.txt");
		rename("D://book1.txt","D://book.txt");
}

main()
{

    int choice;
    char c;
    bookshop b;
    p:
    b.adminPanel();
    cout<<"\n\nEnter your choice:";
    cin>>choice;

    switch(choice)
    {

    case 1:
        do{
            b.addBook();
            cout<<"\n\n Do You Want to Add another Book (y,n) : ";
			cin>>c;

        }while(c == 'y');
        break;

    case 2:
        b.showBooks();
        break;
    case 3:
        b.checkBook();
        break;
    case 4:
        b.updateBook();
        break;
    case 5:
        b.deleteBook();
        break;
    case 6:
        exit(0);
    default:
        cout<<"\n\nPlease enter a valid option..";
    }
    getch();
    goto p;
}
