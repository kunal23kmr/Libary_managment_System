#include <iostream>
using namespace std;
inline int sum(int a, int b)
{
    return a + b;
}
inline int mul(int a, int b)
{
    return a * b;
}
int main()
{
    int a, b;
    cout << "Enter 'a' and 'b': ";
    cin >> a >> b;

    cout << "In-line sum function:  " << sum(a, b) << endl;
    cout << "In-line multiplication:  " << mul(a, b) << endl;

    return 0;
}