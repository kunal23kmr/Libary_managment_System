/*
Overload "++" operator in suffix notation using member function and friend function.
*/
//===using friend function
#include <iostream>
using namespace std;
class complex
{
    int real = 0, img = 0;

public:
    complex(int r, int i) { this->real = r, this->img = i; }
    void display()
    {
        cout << "complex number = " << this->real << " + i" << this->img << endl;
    }
    friend complex operator++(complex &obj, int);
};
complex operator++(complex &obj, int)
{
    complex x(0, 0);
    cout << "Using the friend function" << endl;
    x.real = obj.real++;
    x.img = obj.img++;
    return x;
}
int main()
{
    complex c1(2, 3);
    c1.display();
    c1++;
    c1.display();
    return 0;
}