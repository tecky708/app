#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

class Library {
public:
    string bookname[50], auname[50], ibook[100];
    int bookid[100], iid[100];
    int choice;

    Library() {
        bookname[0] = "harry potter";
        bookname[1] = "twilight";
        bookname[2] = "diwan-e-ghalib";
        bookname[11] = "for the love of physics";
        bookname[12] = "newtonian";
        bookname[13] = "einstein physics";
        bookname[21] = "calculus v1";
        bookname[22] = "calculus v2";
        auname[0] = "jk rowling";
        auname[1] = "stephenie meyer";
        auname[2] = "mirza ghalib";
        auname[11] = "walter lewin";
        auname[12] = "newton jr";
        auname[13] = "einstein";
        auname[21] = "sir nadeem";
        auname[22] = "sir shoiab";
        bookid[0] = 1;
        bookid[1] = 2;
        bookid[2] = 3;
        bookid[11] = 12;
        bookid[12] = 13;
        bookid[13] = 14;
        bookid[21] = 22;
        bookid[22] = 23;
    }

    void begin() {
        system("cls");
        system("Color F5");

        cout << "\n\n\t\t     ~~~~~~~~ WELCOME TO THE MAIN MENU ~~~~~~~~";
        cout << "\n\n\n\n\t 1. Student";
        cout << "\n\n\t 2. Librarian";
        cout << "\n\n\t 3. Exit program";
        cout << "\n\n\n\t Enter your choice: ";
    }

    void booklist(int i) {
        system("cls");

        int b, j, r;
        system("cls");
        b = course(i);
        system("cls");

        if (b == 1) {
            r = 0;
            for (j = 0; bookid[j] != 0 && bookid[j] <= 100; j++) {
                cout << "\n\n\t\t~~" << r++ << "~~\n\n";
                cout << "Book Name: " << bookname[j] << endl;
                cout << "Author Name: " << auname[j] << endl;
                cout << "Book ID: " << bookid[j] << endl;
            }
        }
        else if (b == 2) {
            r = 0;
            for (j = 11; bookid[j] != 0 && bookid[j] <= 100; j++) {
                cout << "\n\n\t\t~~" << r++ << "~~\n\n";
                cout << "Book Name: " << bookname[j] << endl;
                cout << "Author Name: " << auname[j] << endl;
                cout << "Book ID: " << bookid[j] << endl;
            }
        }
        else if (b == 3) {
            r = 0;
            for (j = 21; bookid[j] != 0 && bookid[j] <= 100; j++) {
                cout << "\n\n\t\t~~" << r++ << "~~\n\n";
                cout << "Book Name: " << bookname[j] << endl;
                cout << "Author Name: " << auname[j] << endl;
                cout << "Book ID: " << bookid[j] << endl;
            }
        }

        begin();
    }

    int course(int x) {
        int i;
        cout << "\n\t\t>>Please Choose one Branch :-\n";
        cout << "\n\t\t1. Novels\n";
        cout << "\t\t2. Physics\n";
        cout << "\t\t3. Calculus\n";
        cout << "\t\t4. Go to menu\n";
        cout << "\n\t\tEnter your choice: ";
        cin >> i;
        switch (i) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            system("cls");
            if (x == 1)
                begin();
            else {
                Library::begin();
            }
        default:
            cout << "\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            course(0);
        }
    }
};

class Student : public Library {
public:
    int opt;
	int j;

    void begin() {
        system("cls");
        system("Color F3");
        cout << endl;
        cout << "\n\n\t\t\t\t~~~~STUDENT PORTAL~~~~\n\n\n\n";
        cout << "\n\n\t Choose an option ";
        cout << "\n\n\t 1. View all Books";
        cout << "\n\n\t 2. Search a Book";
        cout << "\n\n\t 3. Go to Main Menu";
        cout << "\n\n\t Enter your Option: ";
        cin >> opt;

        if (opt == 1) {
            booklist(1);
        }
        else if (opt == 2) {
            search(1);
        }
        else if (opt == 3) {
            Library::begin();
        }
        else {
            cout << "\n\n\t\tWrong Choice! ";
            getch();
            begin();
        }
    }

    void search(int i) {
        system("cls");
        string searchbook;
        int a, r = 0, j, k;
        cout << "\n\n\t\t\t~~~SEARCH A BOOK~~~\n\n";
        cout << "\t\tPlease Enter Book Name: ";
        cin.ignore();
        getline(cin, searchbook);
        a = course(i);
        for (j = 0; bookname[j] != " " && bookname[j] != "0"; j++) {
            if (searchbook == bookname[j]) {
                cout << "\n\n\t\t\tBook Found!";
                cout << "\n\n\t\tBook Name: " << bookname[j];
                cout << "\n\t\tAuthor Name: " << auname[j];
                cout << "\n\t\tBook ID: " << bookid[j];
                r = 1;
                cout << "\n\n\t\t 1. Issue Book";
                cout << "\n\t\t 2. Go to main menu";
                cout << "\n\n\t\t Enter your choice: ";
                cin >> k;
                if (k == 1) {
                    issue(j);
                }
                else if (k == 2) {
                    Library::begin();
                }
                else {
                    cout << "\n\t\tPlease enter the correct option :(";
                    getch();
                    Library::begin();
                }
            }
        }
        if (r == 0) {
            cout << "\n\n\t\tSorry! Book not found :(";
            getch();
            Library::begin();
        }
    }

    void issue(int i) {
        string name;
        int j, x;
        cout << "\n\n\t\t\tPlease Enter your name: ";
        cin.ignore();
        getline(cin, name);
        for (j = 0; iid[j] != 0; j++);
        iid[j] = j + 1;
        ibook[j] = bookname[i];
        cout << "\n\n\t\tBook Issued Successfully :)";
        cout << "\n\t\tIssued Book Name: " << ibook[j];
        cout << "\n\t\tIssued Book ID: " << bookid[i];
        cout << "\n\t\tIssued ID: " << iid[j];
        cout << "\n\n\t\t\t\tThanks " << name << "!";
        x = _getch();
        Library::begin();
    }
};

class Librarian : public Library {
public:
    string username, password;

    void pass() {
        system("cls");
        cout << "\n\n\t\t\t~~~~~~LIBRARIAN PORTAL~~~~~~\n\n\n";
        cout << "\n\n\t\tPlease enter your username: ";
        cin >> username;
        cout << "\n\t\tPlease enter your password: ";
        cin >> password;
        if (username == "admin" && password == "admin123") {
            menu();
        }
        else {
            cout << "\n\n\t\tWrong Username or Password :(";
            getch();
            begin();
        }
    }

    void menu() {
        system("cls");
        int k;
        cout << "\n\n\t\t\t~~~~~MAIN MENU~~~~~\n\n";
        cout << "\n\n\t\t1. Add Book";
        cout << "\n\t\t2. Delete Book";
        cout << "\n\t\t3. View Book List";
        cout << "\n\t\t4. Issue Book";
        cout << "\n\t\t5. View Issued Book List";
        cout << "\n\t\t6. Go to Student Portal";
        cout << "\n\t\t7. Exit Program";
        cout << "\n\n\t\tEnter your choice: ";
        cin >> k;
        switch (k) {
        case 1:
            add();
            break;
        case 2:
            Delete();
            break;
        case 3:
            viewbooklist();
            break;
        case 4:
            issue();
            break;
        case 5:
            issuedbooklist();
            break;
        case 6:
            Library::begin();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "\n\n\t\tPlease enter the correct option :(";
            getch();
            menu();
        }
    }

    void add() {
        system("cls");
        int i, j;
        cout << "\n\n\t\t\tAdd Book Details\n\n";
        for (i = 0; bookid[i] != 0; i++);
        bookid[i] = i + 1;
        cout << "\n\t\tBook ID: " << bookid[i];
        cin.ignore();
        cout << "\n\t\tBook Name: ";
        getline(cin, bookname[i]);
        cout << "\n\t\tAuthor Name: ";
        getline(cin, auname[i]);
        cout << "\n\n\t\tBook Added Successfully :)";
        _getch();
        menu();
    }

    void Delete() {
        system("cls");
        int k;
        cout << "\n\n\t\t\tDelete Book\n\n";
        cout << "\n\t\t1. Delete by Book ID";
        cout << "\n\t\t2. Delete by Book Name";
        cout << "\n\t\t3. Go to Menu";
        cout << "\n\n\t\tEnter your choice: ";
        cin >> k;

        if (k == 1) {
            int id;
            cout << "\n\t\tEnter the Book ID: ";
            cin >> id;
            int i = searchbyID(id);
            if (i != -1) {
                bookid[i] = 0;
                bookname[i] = "";
                auname[i] = "";
                cout << "\n\n\t\tBook Deleted Successfully :)";
                _getch();
            }
            else {
                cout << "\n\n\t\tBook not found :(";
                _getch();
            }
        }
        else if (k == 2) {
            string name;
            cout << "\n\t\tEnter the Book Name: ";
            cin.ignore();
            getline(cin, name);
            int i = searchbyName(name);
            if (i != -1) {
                bookid[i] = 0;
                               bookname[i] = "";
                auname[i] = "";
                cout << "\n\n\t\tBook Deleted Successfully :)";
                _getch();
            }
            else {
                cout << "\n\n\t\tBook not found :(";
                _getch();
            }
        }
        else if (k == 3) {
            menu();
        }
        else {
            cout << "\n\n\t\tPlease enter the correct option :(";
            _getch();
            Delete();
        }
        menu();
    }

    int searchbyID(int id) {
        for (int i = 0; bookid[i] != 0 && i < 100; i++) {
            if (bookid[i] == id) {
                return i;
            }
        }
        return -1;
    }

    int searchbyName(string name) {
        for (int i = 0; bookname[i] != "" && i < 100; i++) {
            if (bookname[i] == name) {
                return i;
            }
        }
        return -1;
    }

    void viewbooklist() {
        system("cls");
        cout << "\n\n\t\t\tAll Books List\n\n";
        int r = 0;
        for (int j = 0; bookid[j] != 0 && j < 100; j++) {
            cout << "\n\n\t\t~~" << r++ << "~~\n\n";
            cout << "Book Name: " << bookname[j] << endl;
            cout << "Author Name: " << auname[j] << endl;
            cout << "Book ID: " << bookid[j] << endl;
        }
        _getch();
        menu();
    }

    void issue() {
        system("cls");
        string name;
        int i, x;
        cout << "\n\n\t\t\tIssue Book\n\n";
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        int id;
        cout << "Enter Book ID: ";
        cin >> id;
        i = searchbyID(id);
int j;
        if (i != -1) {
            for (j = 0; iid[j] != 0 && j < 100; j++);
            iid[j] = j + 1;
            ibook[j] = bookname[i];
            cout << "\n\n\t\tBook Issued Successfully :)";
            cout << "\n\t\tIssued Book Name: " << ibook[j];
            cout << "\n\t\tIssued Book ID: " << bookid[i];
            cout << "\n\t\tIssued ID: " << iid[j];
            cout << "\n\n\t\tThanks " << name << "!";
            x = _getch();
        }
        else {
            cout << "\n\n\t\tBook not found :(";
            _getch();
        }
        menu();
    }

    void issuedbooklist() {
        system("cls");
        cout << "\n\n\t\t\tAll Issued Books List\n\n";
        int r = 0;
        for (int j = 0; iid[j] != 0 && j < 100; j++) {
            cout << "\n\n\t\t~~" << r++ << "~~\n\n";
            cout << "Issued Book Name: " << ibook[j] << endl;
            cout << "Issued Book ID: " << bookid[j] << endl;
            cout << "Issued ID: " << iid[j] << endl;
        }
        _getch();
        menu();
    }
};

int main() {
    Library lib;
    Student stud;
    Librarian librn;
    lib.begin();

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        stud.begin();
        break;
    case 2:
        librn.pass();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "\n\n\t\tPlease enter the correct option :(";
        break;
    }
    return 0;
}

