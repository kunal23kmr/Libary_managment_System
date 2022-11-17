/*
Create a class TIME to store time in hourse and minutes.
Write a friend function to add two time objects.
*/
#include <iostream>
using namespace std;
class TIME
{
private:
    int hh;
    float mm;
public:
    void input()
    {
        cout << "Enter the time:\n";
        cout << "hh: ";
        cin >> hh;
        cout << "mm: ";
        cin >> mm;
    }
    void display(int th, int tm)
    {
        cout << "The sum of two times are: " << th << "(hh): " << tm << "(mm)" << endl;
    }
    void add1(TIME &t2)
    {
        int th = 0;
        float tm = 0;
        tm = this->mm + t2.mm;
        if (tm >= 60)
        {
            tm = tm - 60;
            th++;
        }
        th += this->hh + t2.hh;
        cout << "Using member function" << endl;
        display(th, tm);
    }
    friend void add(TIME &t1, TIME &t2);
};
void add(TIME &t1, TIME &t2)
{
    int th = 0;
    float tm = 0;
    tm = t1.mm + t2.mm;
    if (tm >= 60)
    {
        tm = tm - 60;
        th++;
    }
    th += t1.hh + t2.hh;
    cout << "Using friend function" << endl;
    t1.display(th, tm);
}
int main()
{
    TIME t1, t2;
    t1.input();
    t2.input();
    add(t1, t2);
    t1.add1(t2);
    return 0;
}