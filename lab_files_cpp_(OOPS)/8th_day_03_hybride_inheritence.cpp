// hybride inheritence...without virtual inhERITANCE...
#include <iostream>
using namespace std;

class a
{
public:
    a()
    {
        cout << "Class 'a' consturctor.And a is a base class" << endl;
    }
    ~a() { cout << "Distructor of a." << endl; }
};

class b
{
public:
    b()
    {
        cout << "Class 'b' consturctor.And is a base class." << endl;
    }
    ~b() { cout << "Distructor of b." << endl; }
};

class c : public b
{
public:
    c()
    {
        cout << "Class 'c' constructor. And example of multi-level inheritence." << endl;
    }
    ~c() { cout << "Distructor of c." << endl; }
};

class d : public a, public b, public c
{
public:
    d()
    {
        cout << "Class 'd' constructor. And example of hybride-inheritence." << endl;
    }
    ~d() { cout << "Distructor of d." << endl; }
};

int main()
{
    d obj1;
    return 0;
}