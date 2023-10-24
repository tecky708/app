// C++ program to print an array 

#include<iostream>
#include<conio.h>

using namespace std;

class Employee{
    int id;
    char name[30];
    public:

        void getdata();

        void putdata();
};

void Employee::getdata(){
    cout << "Enter ID : ";
    cin >> id;
    cout << "Enter Name : ";
    cin >> name;
}

void Employee::putdata(){
    cout << id << " ";
    cout << name << " ";
    cout << endl;
}

int main(){
    Employee emp [30];
    int n , i ;
    cout << "Enter the number of Employees : ";
    cin >> n;

    for(i=0; i<n; i++)
    emp[i].getdata();
    cout << "Employee Data - " << endl;

    for(i=0; i<n; i++)
    emp[i].putdata();
    getch();
}



