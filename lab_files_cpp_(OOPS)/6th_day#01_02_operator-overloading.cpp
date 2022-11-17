/*
Program to overload "++" operator in prefix notation using member function and friend function.
*/
//====using friend function
#include <iostream>
using namespace std;
class complex
{    int real = 0, img = 0;
public:
    // constructor...
    complex(int r, int i) { this->real = r, this->img = i; }
    // operator overloading...in prefix
    void display()
    {        cout << "complex number = " << this->real << " + i" << this->img << endl;    }
    friend complex operator++(complex &obj);
};
complex operator++(complex &obj)
{   cout << "Using the friend function...\n";
    ++obj.real;
    ++obj.img;  }
int main()
{   complex c1(2, 3);
    c1.display();
    ++c1;
    // c1++;
    c1.display();
    return 0;   }