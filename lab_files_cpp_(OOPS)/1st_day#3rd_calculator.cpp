// Make calculator to performe +,-,*,/, and exit action.
#include <iostream>
using namespace std;
int main()
{
    while (1)
    {
        char a;
        int x, y, result = 0;
        cout << "Enter the value of a and b: ";
        cin >> x >> y;
        cout << "Choose any(+,-,/,*,'e'(to exit)): ";
        cin >> a;
        if (a == 'e')
        {
            return 0;
        }
        switch (a)
        {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '/':
        {
            if (y != 0)
                result = x / y;
            else
            {
                cout << "Error";
                return 0;
            }
        }
        case '*':
            result = x * y;
        default:
        {
            cout << "wrong input.";
            return 0;
        }
        }
        cout << "Result= " << result << endl;
    }
    return 0;
}