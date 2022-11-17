/*
Write program to demonstrate the concept of default constructor, parameterized
constructor, copy constructor and constructor overloading.
*/
#include <iostream>
using namespace std;
class rectangle
{
    int l, w;

public:
    // default
    rectangle()
    {
        cout << "Default constructor called." << endl;
    }
    // parameterized
    rectangle(int a, int b)
    {
        cout << "Parametrized constructor is called" << endl;
        this->setDimension(a, b);
    }
    // copy
    rectangle(rectangle &copyfrom)
    {
        this->l = copyfrom.l, this->w = copyfrom.w;
    }
    void display()
    {
        cout << "Length is:" << l << endl
             << "Width is :" << w << endl
             << "Area is: " << (l * w) << endl
             << "Lenght of circumfarence is: " << (l + w) << endl;
    }
    ~rectangle()
    {
        cout << "The distructor is called to free the memory." << endl;
    }
    void setDimension(int &l, int &w)
    {
        this->l = l, this->w = w;
    }
};
int main()
{
    int a, b;
    cout << "Enter the dimensions: ";
    cin >> a;
    cin >> b;
    rectangle r1(a, b);
    rectangle r2 = r1;
    r1.display();
    r2.display();
    return 0;
}