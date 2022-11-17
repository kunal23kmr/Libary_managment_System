/*
Overload '+' operator using friend function.
*/
#include <iostream>
using namespace std;
class complex{int real, img;
public:complex(int r, int i)
    {this->real = r, this->img = i;}
    complex() {}
    void display()
    {cout << "complex number = " << this->real << " + i" << this->img << endl;}
    friend complex operator+(complex &obj1,complex &obj2);};
complex operator+(complex &obj1,complex &obj2)
{   cout << "(Using friend function...)" << endl;
    complex c3;
    c3.real = obj2.real + obj1.real;
    c3.img = obj2.img + obj1.img;
    return c3;}
int main()
{   complex c1(2, 3), c2(4, 5), c3;
    cout << "c1 is:\n";
    c1.display();
    cout << "c2 is:\n";
    c2.display();
    cout << "c3 is:\n";
    cout << "After addition c3 is:";
    c3 = c1 + c2;
    c3.display();
    return 0;
}