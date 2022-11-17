/*
Overload "++" operator in suffix notation using member function and friend function.
*/
//====using member function
#include <iostream>
using namespace std;
class complex
{
    int real = 0, img = 0;

public:
    complex(int r, int i) { this->real = r, this->img = i; }
    complex operator++(int)
    {
        cout << "Using the member function" << endl;
        this->real++;
        this->img++;
    }
    void display()
    {
        cout << "complex number = " << this->real << " + i" << this->img << endl;
    }
};
int main()
{
    complex c1(2, 3);
    c1.display();
    c1++;
    c1.display();
    return 0;
}