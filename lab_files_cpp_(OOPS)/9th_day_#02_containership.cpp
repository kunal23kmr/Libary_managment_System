// example of containorship...
#include <iostream>
using namespace std;

class A
{
    int a, b;

public:
    A()
    {
        a = 100, b = 200;
        cout << "Class 'A' consturctor." << endl;
    }
    A(int p, int q)
    {
        p = a,q = b;
        cout << "Class 'A' consturctor." << endl;
    }
    void display()
    {
        cout << "a=" << a << " b=" << b << endl;
    }
    ~A(){cout<<"Distructor of A."<<endl;}
};
class B
{
    int c, d;
    A obj;

public:
    B()
    {
        c = 300, d = 400;
        A x(c + 10, d + 10);
        obj = x;
        cout << "Class 'B' constructor." << endl;
    }
    B(int l, int m)
    {
        c = l, d = m;
        A x(c + 10, d + 10);
        // cout<<1<<endl;
        obj = x;
        cout << "Class 'B' constructor." << endl;
    }
    void display()
    {
        cout << "c=" << c << " d=" << d << endl;
    }
    ~B(){cout<<"Distructor of B."<<endl;}
};
int main()
{
    A obj1;
    obj1.display();

    B obj2(20,30);
    obj2.display();

    return 0;
}