#include <bits/stdc++.h>
using namespace std;
void IOS_width()
{
    cout << "Implementing ios::width\n";
    int a = 512;
    cout.width(5);
    cout << a << "\n";
}
void IOS_precision()
{
    cout << "\nImplementing ios::precision\n";
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);
    cout << 3.1422;
    cout << "\n";
}
void IOS_fill()
{
    cout << "\nImplementing ios::fill\n";
    char ch = 'd';
    cout.fill('*');
    cout.width(10);
    cout << ch << "\n";
    int i = 4;
    cout.width(5);
    cout << i;
    cout << "\n";
}
void IOS_setf()
{
    cout << "\nImplementing ios::setf\n";
    int val1 = 100, val2 = 200;
    cout.setf(ios::showpos);
    cout << val1 << " " << val2;
    cout << "\n";
}
void IOS_unsetf()
{
    cout << "\nImplementing ios::unsetf\n";
    cout.setf(ios::showpos | ios::showpoint);
    cout.unsetf(ios::showpos);
    cout << 200.0;
    cout << "\n";
}
main()
{
    IOS_width();
    IOS_precision();
    IOS_fill();
    IOS_setf();
    IOS_unsetf();
}
