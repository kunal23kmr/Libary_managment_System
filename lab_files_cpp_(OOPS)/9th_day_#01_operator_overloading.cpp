/*
Create a time class and Overload the assignment operator (=) to copy time object.
*/
#include <iostream>
using namespace std;
class time
{
private:
    int hh;
    float mm;

public:
    void input()
    {   cout << "Enter the time:\n";
        cout << "hh: ";
        cin >> hh;
        cout << "mm: ";
        cin >> mm;    }
    void display() { cout << "hh= " << this->hh << " mm =" << mm << endl; }
    time operator=(time &t1)
    {   this->hh = t1.hh;
        this->mm = t1.mm;    }
};
void main()
{   time t1;
    t1.input();
    cout << "\nPrinting t1: \n";
    t1.display();
    time t2 = t1;
    cout << "\nPrinting t2: \n";
    t2.display();   }