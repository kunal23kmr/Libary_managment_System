#include <iostream>
#define n 5
using namespace std;
int top = -1;
int *stack = new int[n];
void push(int x)
{
    if (top == n - 1)
        cout << "The stack is full :(" << endl;
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top == (-1))
        cout << "Stack is empty :(" << endl;
    else
        top--;
}
void display()
{
    int i = top;
    if (i < 0)
        cout << "Stack is empty." << endl;
    while (i >= 0)
    {
        cout << stack[i] << " ";
        i--;
    }
}
int main()
{
    int x;
    cout << endl
         << "The size of stack is: " << n << endl;
    cout << "pushing.." << endl;
    for (int i = 0; i < n; i++)
    {
        push(i);
    }
    cout << "Displaying.." << endl;
    display();
    cout << endl
         << "Poping..." << endl;
    for (int i = 0; i < n; i++)
    {
        pop();
        display();
        cout<<endl;
    }
    cout << "Displaying.." << endl;
    display();
    // cout << "Enter 1 for push:" << endl
    //      << "Entyer 2 for pop: " << endl
    //      << "Enter 3 for display: ";
    // cin >> x;
    // switch (x)
    // {
    // case 1:
    //     int a;
    //     cout << "Enter the number to push: ";
    //     cin >> a;
    //     push(a);
    //     break;
    // case 2:
    //     pop();
    //     break;
    // case 3:
    //     display();
    //     break;
    // default:
    //     cout << "Invalid input" << endl;
    // }

    return 0;
}