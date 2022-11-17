// To check whether the number is prime or not....
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter(integer) number to check: ";
    cin >> n;
    if (n & 1 == 1 && n != 0 && n != 2)
    {
        int a = n / 2, j = 0;
        for (int i = a; j > 0; i -= 2)
        {
            if (n % i == 0)
            {
                j++;
                break;
            }
        }
        if (j)
        {
            cout << "Not a prime.";
        }
        else
            cout << "Is prime.";
    }
    else
    {
        cout << "The number is not prime.";
    }
    return 0;
}