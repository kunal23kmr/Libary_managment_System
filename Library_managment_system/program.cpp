#include <iostream>  //for reading and writing on console
#include <fstream>   //for reading and writing from file
#include <string>    //for getline
#include <string.h>  //to read and write string
#include <conio.h>   //for getch
#include <stdlib.h>  //for exit
#include <windows.h> //for sleep used in password function
#include <ctime>

using namespace std;

int student_rollNo = -1;
// class for book
class book
{
    int id;
    char book_name[50];
    char author[50], status[10];

public:
    book()
    {
        // to store contents of file in it
    }
    book(int i, char c[], char a[], char s[])
    {
        id = i;
        strcpy(book_name, c);
        strcpy(author, a);
        strcpy(status, s);
    }
    void display(book &b)
    {
        cout << "Book id is " << b.id << "\n";
        cout << "Book name is " << b.book_name << "\n";
        cout << "Book author is " << b.author << "\n";
        cout << "Book status is " << b.status << "\n";
    }
    friend int searchInfo(int);
    friend int modifyRecord(book b);
    friend int deleteRecord(int);
    friend int displayRecord(int);
};

// used to search through id
int searchInfo(int id)
{
    ifstream list("book_list.txt");
    int x = 3;
    string s; // buffer_string
    while (x--)
    {
        getline(list, s);
    }

    int check_id = 0;
    char name[24], auth[10], status[10];
    while (list)
    {
        list >> check_id >> name >> auth >> status;
        book b(check_id, name, auth, status);
        if (b.id == id)
        {
            cout << "\nInformation..\n";
            b.display(b);
            x = -1;
            list.close();
            return 1;
        }
    }
    if (x != -1)
    {
        list.close();
        return 0;
    }
    list.close();
    return 0;
}

// add books
void fileWriting()
{
    book b;

    int id;
    char book_name[50];
    char author[50];
    int n;
    cout << "Enter the number of books for which you want to print data\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nFor book " << i + 1 << "\n";
        cout << "\nEnter book id: ";
        cin >> id;
        cin.ignore(); // if we don't use this then while inputting book name and author only one thing will get printed.
        cout << "\nEnter book name: ";
        cin.getline(book_name, 50);
        cout << "\nEnter author of book: ";
        cin.getline(author, 50);
        book b(id, book_name, author, "Free");

        ofstream fout("books.dat", ios::binary | ios::app);
        fout.write((char *)&b, sizeof(b));
        fout.close();
    }
}

// display books
void fileReading()
{
    string s;
    ifstream list("book_list.txt");

    // read data from the file student
    getline(list, s);
    while (list)
    {
        cout << s;
        getline(list, s);
        cout << endl;
    }
    list.close();
}

// display specific book
int displayRecord(int id)
{
    cout << "Enter book id which you want to display: ";
    cin >> id;
    int state = searchInfo(id);
    if (state == 1)
    {
        cout << "\nContent displayed success\n";
    }
    else
    {
        cout << "\nId not found\n";
        exit(0);
    }
    return state;
}

// update or modify book data
int modifyRecord(book b)
{

    int state = searchInfo(b.id);
    if (state == 1)
    {
        ofstream fout("bookscopy.dat", ios::binary);
        ifstream fin("books.dat", ios::binary);
        book bcopy;
        while (fin.read((char *)&bcopy, sizeof(bcopy)))
        {
            if (b.id != bcopy.id)
            {
                fout.write((char *)&bcopy, sizeof(bcopy));
            }
            else
            {
                fout.write((char *)&b, sizeof(b));
            }
        }
        fout.close();
        fin.close();
        remove("books.dat");
        rename("bookscopy.dat", "books.dat");
        cout << "\nContent updated success\n";
    }
    else
    {
        cout << "\n Id not found";
    }
    return state;
}
// to delete any book
int deleteRecord(int id)
{
    cout << "Enter book id\n";
    cin >> id;
    int state = searchInfo(id);
    if (state == 1)
    {
        ofstream fout("bookscopy.dat", ios::binary);
        ifstream fin("books.dat", ios::binary);
        book b;

        while (fin.read((char *)&b, sizeof(b)))
        {
            if (b.id != id)
            {
                fout.write((char *)&b, sizeof(b));
            }
        }
        fout.close();
        fin.close();
        remove("books.dat");
        rename("bookscopy.dat", "books.dat");
        cout << "\nContent deleted success\n";
    }
    else
    {
        cout << "\nId not found\n";
    }
    return state;
}
// class to display student
class student
{
    int rollNo;
    char name[30];

public:
    student()
    {
        // to store contents of file in it
    }
    student(int r, char n[])
    {
        rollNo = r;
        strcpy(name, n);
    }
    void display(student s)
    {
        cout << "Student's roll number is " << s.rollNo << "\n";
        cout << "Student's name is " << s.name << "\n";
    }
    friend int studentInfo(int);
    friend int modifyStudent(student s);
    friend int deleteStudent(int);
    friend int displayStudent(int);
};
// used to display data through roll number
int studentInfo(int rollNo)
{
    ifstream student_list("student_list.txt");
    int x = 2;
    string s; // buffer_string
    while (x--)
    {
        getline(student_list, s);
    }

    int roll = 0;
    char name[10];
    while (student_list)
    {
        student_list >> roll >> name;
        student s(roll, name);
        if (s.rollNo == rollNo)
        {
            cout << "\nInformation..\n";
            s.display(s);
            x = -1;
            student_list.close();
            return 1;
        }
    }
    if (x != -1)
    {
        student_list.close();
        return 0;
    }
    student_list.close();
    return 0;
}

// add students
void writeToFile()
{
    student s;

    int rollNo;
    char name[30];
    int m;
    cout << "Enter the number of students for which you want to print data\n";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "\nFor student " << i + 1 << "\n";
        cout << "\nEnter student's roll number: ";
        cin >> rollNo;
        cin.ignore(); // if we don't use this then while inputting book name and author only one thing will get printed.
        cout << "\nEnter student's name: ";
        cin.getline(name, 30);
        student s(rollNo, name);

        ofstream fout("Students.dat", ios::binary | ios::app);
        fout.write((char *)&s, sizeof(s));
        fout.close();
    }
}
// display student
void readToFile()
{
    int rollNo;
    char name[30];
    student s(rollNo, name);

    ifstream fin("Students.dat", ios::binary);

    while (fin.read((char *)&s, sizeof(s)))
    {

        s.display(s);
    }
    fin.close();
}
// display specific student
int displayStudent(int rollNo)
{
    // cout << "Enter student roll number which you want to display: ";
    // cin >> rollNo;
    int state = studentInfo(rollNo);
    if (state == 1)
    {
        cout << "\nContent displayed success\n";
    }
    else
    {
        cout << "\nRoll Number not found\n";
        exit(0);
    }
    return state;
}
// update student data
int modifyStudent(student s)
{

    int state = studentInfo(s.rollNo);
    if (state == 1)
    {
        ofstream fout("Studentscopy.dat", ios::binary);
        ifstream fin("Students.dat", ios::binary);
        student scopy;
        while (fin.read((char *)&scopy, sizeof(scopy)))
        {
            if (s.rollNo != scopy.rollNo)
            {
                fout.write((char *)&scopy, sizeof(scopy));
            }
            else
            {
                fout.write((char *)&s, sizeof(s));
            }
        }
        fout.close();
        fin.close();
        remove("Students.dat");
        rename("Studentscopy.dat", "Students.dat");
        cout << "\nContent updated success\n";
    }
    else
    {
        cout << "\n Roll Number not found";
    }
    return state;
}
// delete any student data
int deleteStudent(int rollNo)
{
    cout << "Enter student's roll number\n";
    cin >> rollNo;
    int state = studentInfo(rollNo);
    if (state == 1)
    {
        ofstream fout("Studentscopy.dat", ios::binary);
        ifstream fin("Students.dat", ios::binary);
        student s;

        while (fin.read((char *)&s, sizeof(s)))
        {
            if (s.rollNo != rollNo)
            {
                fout.write((char *)&s, sizeof(s));
            }
        }
        fout.close();
        fin.close();
        remove("Students.dat");
        rename("Studentscopy.dat", "Students.dat");
        cout << "\nContent deleted success\n";
    }
    else
    {
        cout << "\nRoll Number not found\n";
    }
    return state;
}
class issuebook : public book, public student
{
    int roll; // they are inherited from the base class..
    int id;
    string date_of_issue;
    string return_date;
    int fine;
    friend void issueBook();
    friend void returnBook();
    friend void reIssueBook();
};
// to issue any book
void issueBook()
{
    issuebook i;
    int rollNo = student_rollNo;
    int id;
    displayStudent(rollNo);
    displayRecord(id);
    time_t t = time(0); // get time now
    tm *now = localtime(&t);
    cout << "Date:- " << now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900) << "\n";
}
// to return any book
void returnBook()
{
    issuebook i;
    cout << "Enter roll number and book id\n";
    cin >> i.roll >> i.id;
}
// to re-issue any book
void reIssueBook()
{
    issuebook i;
    cout << "Enter roll number and book id\n";
    cin >> i.roll >> i.id;
}
// it will display the options students have access to
void studentMenu()
{
    char c;
    cout << "--------------------------------------------------WELCOME TO STUDENT'S SECTION----------------------------------------------\n";
    do
    {
        int id = 0;
        int y;
        cout << "\nChoose any one option:\n";
        cout << "======================\n\n";
        cout << "1 = Display books \n2 = Display Specific Book \n3 = Issue books \n4 = Returning of books \n5 = Re-issue book \n6 = Exit\n"; /// re-issue nahi karna hai
        cin >> y;
        switch (y)
        {
        case 1:
            fileReading();
            break;
        case 2:
            displayRecord(id);
            break;
        case 3:
            issueBook();
            break;
        case 4:
            returnBook();
            break;
        case 5:
            reIssueBook();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "You enter wrong choice. Please select any other\n";
            break;
        }
        cout << "\nDo you want to continue? Press (y/Y) to continue\n";
        c = getche();
    } while (c == 'y' || c == 'Y');
}
// it will display the options librarian has access to
void librarianMenu()
{
    char c;
    cout << "----------------------------------------------WELCOME TO LIBRARIAN'S SECTION--------------------------------------------\n";
    do
    {
        int id = 0;
        char book_name[50];
        char author[50];
        int rollNo = 0;
        char name[30];
        cout << "\nChoose any one option\n";
        cout << "1 = Display all students  2 = Display specific student  3 = Modify student  4 = Delete student  ";
        cout << "5 = Modify Book  6 = Delete Book 7 = Add Book  8 = Add student 9 = exit\n";
        int z;
        cin >> z;
        switch (z)
        {
        case 1:
            readToFile();
            break;
        case 2:
            cout << "Enter student roll number which you want to display: ";
            cin>>rollNo;
            displayStudent(rollNo);
            break;
        case 3:
        {
            int rollNo;
            char name[30];
            cout << "\nEnter student's roll number: ";
            cin >> rollNo;
            cin.ignore();
            cout << "\nEnter student's name: ";
            cin.getline(name, 30);
            student s(rollNo, name);
            modifyStudent(s);
        }
        break;
        case 4:
            deleteStudent(rollNo);
            break;
        case 5:
        {
            int id;
            char book_name[50];
            char author[50], status[10];
            cout << "Enter book id: ";
            cin >> id;
            cin.ignore();
            cout << "\nEnter book name: ";
            cin.getline(book_name, 50);
            cout << "\nEnter author of book: \n";
            cin.getline(author, 50);
            cout << "\nEnetr the book status: \n";
            cin.getline(status, 10);
            book b(id, book_name, author, status);
            modifyRecord(b);
        }
        break;
        case 6:
            deleteRecord(id);
            break;
        case 7:
            fileWriting();
            break;
        case 8:
            writeToFile();
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "You entered wrong choice. Please select any other option\n";
            break;
        }
        cout << "Do you want to continue? Press (y/Y) to continue \n";
        c = getche();
    } while (c == 'y' || c == 'Y');
}
void password()
{
    int a = 0, i = 0, key = 0;
    char c = ' ';
    int rollNo, checkRoll;
    // char pwordIn[10];
    string name, pwordActuall, pwordIn;
    // char user[10] = "Riya";
    // char pass[10] = "pass";
    do
    {
        cout << "\n\n        ::::::::::::::::::::::::::  LOGIN FORM  ::::::::::::::::::::::::::  ";
        cout << " \n                              ENTER ROLL NUMBER:-";
        cin >> rollNo;
        cout << "                              ENTER PASSWORD:-";
        while (i < 10)
        {
            c = getch();

            if (c == 13)
                break;
            else
                cout << "*";
            i++;
            pwordIn += c;
        }
        i = 0;
        ifstream student_list("student_list_pass.txt");
        while (student_list)
        {
            student_list >> checkRoll >> name >> pwordActuall;
            if (checkRoll == rollNo && pwordIn == pwordActuall)
            {
                student_rollNo = rollNo;
                key++;
                for (i = 0; i < 85; i++)
                {
                    cout << "*";
                }
                cout << "\n\nLOGIN IS SUCCESSFUL!!!\n\n";
                for (i = 0; i < 85; i++)
                {
                    cout << "*";
                }
                cout << "\n\n LOADING PLEASE WAIT...";
                for (i = 0; i < 4; i++)
                {
                    cout << ".";
                    Sleep(450);
                }
                cout << "\n\n\n\t\t\t\tPress any key to continue...";
                getch();
                break;
            }
        }

        cout << "\n\n";
        // if (strcmp(uname, "Riya") == 0 && strcmp(pword, "pass") == 0)
        // {
        //     for (i = 0; i < 85; i++)
        //     {
        //         cout << "*";
        //     }
        //     cout << "\n\nLOGIN IS SUCCESSFUL!!!\n\n";
        //     for (i = 0; i < 85; i++)
        //     {
        //         cout << "*";
        //     }
        //     cout << "\n\n LOADING PLEASE WAIT... \n";
        //     for (i = 0; i < 7; i++)
        //     {
        //         cout << ".";
        //         Sleep(500);
        //     }
        //     cout << "\n\n\n\t\t\t\tPress any key to continue...";
        //     getch();
        //     break;
        // }
        if (key != 1)
        {
            cout << "               SORRY !!!!  LOGIN IS UNSUCESSFUL!! PLEASE TRY AGAIN";
            a++;
            getch();
            break;
        }
    } while (a <= 3 && key == 0);
    if (a > 3)
    {
        cout << "\n Sorry you have entered the wrong user name or password many times!!!";
        getch();
        exit(0);
    }
    system("cls");
}
int main()
{
    password();
    char c;
    cout << "----------------------------------------WELCOME TO LIBRARY MANAGEMENT SYSTEM--------------------------------------------\n";
    cout << "\nChoose any one option:- \n1=Student \n2=Librarian \n3=Close Application\n";
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        studentMenu();
        break;
    case 2:
        librarianMenu();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Invalid Option. Choose any other";
        break;
    }
}