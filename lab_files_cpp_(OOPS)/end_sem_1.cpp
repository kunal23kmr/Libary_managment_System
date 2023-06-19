#include <iostream>
using namespace std;

class stack
{
    int n, top;
    int *arr;

public:
    stack(int size)
    {
        arr = new int[size];
        n = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = (i + 1);
        }
        top = size - 1;
    }

    void push(int a)
    {
        top++;
        arr[top] = a;
    }
    void pop()
    {
        top--;
    }
    void display()
    {
        cout << "Printing element from top-to-bottom." << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{

    stack s(5);
    s.push(6);
    s.push(9);
    s.pop();
    s.display();

    return 0;
}