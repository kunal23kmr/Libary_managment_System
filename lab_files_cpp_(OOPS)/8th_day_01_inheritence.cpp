/*
Program to demonstrate the concept of constructor,destructor,multiple inheritence,
multil-level inheritence and hybrid inheritence, and concept of contaniorship...
*/

// multiple inheritence...

#include <iostream>
using namespace std;

class a
{
public:
    a()
    {
        cout << "Class 'a' consturctor.And is a base class" << endl;
    }
    ~a(){cout<<"Distructor of a."<<endl;}
};

class b
{
public:
    b()
    {
        cout << "Class 'b' consturctor.And is a base class" << endl;
    }
    ~b(){cout<<"Distructor of b."<<endl;}
};

class c : public a, b
{
public:
    c()
    {
        cout << "Class 'c' constructor. And c is examole of multiple inheritence." << endl;
    }
    ~c(){cout<<"Distructor of c."<<endl;}
};

int main()
{
    c obj1;
    return 0;
}