// multi-level inheritence...
#include <iostream>
using namespace std;

class a
{
public:
    a()
    {
        cout << "Class 'a' consturctor." << endl;
    }
    ~a(){cout<<"Distructor of a."<<endl;}
};

class b:public a
{
public:
    b()
    {
        cout << "Class 'b' consturctor.And an example of single inheritence." << endl;
    }
    ~b(){cout<<"Distructor of b."<<endl;}
};

class c : public b
{
public:
    c()
    {
        cout << "Class 'c' constructor. And example of multi-level inheritence." << endl;
    }
    ~c(){cout<<"Distructor of c."<<endl;}
};

int main()
{
    c obj1;
    return 0;
}