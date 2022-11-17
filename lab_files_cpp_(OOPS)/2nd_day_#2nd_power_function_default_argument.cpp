#include <iostream>
using namespace std;
int pow(int x, int y = 2);
int main()
{
    int a, b, p;
    cout << "Press '1' to input both 'a' and 'b':" << endl
         << "Press 2 for only 'a':"<<endl;
    cin >> p;
    switch (p)
    {
    case 1:
        cout << "Enter 'a' and 'b': ";
        cin >> a >> b;
        cout << "Callling the pow  function" << endl;
        p = pow(a, b);
        cout << "pow=" << p << endl;
        break;
    case 2:
        cout << "Enter 'a': ";
        cin >> a;
        cout << "Callling the pow  function" << endl;
        p = pow(a);
        cout << "pow=" << p << endl;
        break;

    default:
        cout << "Invalid input";
        break;
    }
    return 0;
}
int pow(int x, int y )
{
    int result = 1;
    while (y)
    {
        result = result * x;
        y--;
    }

    return result;
}