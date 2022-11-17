// Program to form a fibonacci series upto 'n' term....
#include <iostream>
using namespace std;
void sequence(int n);
int main()
{
    int n;
    cout << "Enter the number of terms (n)" << endl;
    cin >> n;
    switch (n)
    {
    case 1:
    {
        cout << "0 ";
        break;
    }
    case 2:
    {
        cout << "0 1 ";
        break;
    }
    default:
    {
        cout << "0 1 ";
        sequence(n);
    }
    }
    return 0;
}
void sequence(int n)
{
    int a = 0, b = 1;
    for (int temp, i = 3; i <= n; i++)
    {
        temp = a + b;
        cout << temp << " ";
        a = b;
        b = temp;
    }
}