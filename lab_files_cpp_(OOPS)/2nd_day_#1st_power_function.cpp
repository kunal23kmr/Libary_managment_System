#include <iostream>
using namespace std;
int pow(int x);
int pow(int x, int y);
int main()
{
    int a, b;
    cout << "Enter 'a' and 'b': ";
    cin >> a >> b;
    cout << "Callling the pow(int x)" << endl;
    int p = pow(a);
    cout << "pow=" << p << endl;
    cout << "Callling the pow(int x,int y)" << endl;
    p = pow(a, b);
    cout << "pow=" << p << endl;
    return 0;
}
int pow(int x)
{
    int result = 1;
    result = x * x;
    return result;
}
int pow(int x, int y)
{
    int result = 1;
    while (y)
    {
        result = result * x;
        y--;
    }
    return result;
}