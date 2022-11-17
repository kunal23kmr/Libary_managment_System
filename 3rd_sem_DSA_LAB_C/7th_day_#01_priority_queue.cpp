#include <iostream>
using namespace std;

struct elements
{
    int value;
    int priority;
};

elements *arr = new elements[1000];
int size = -1;

void enqueue(int value, int priority)
{
    size++;
    if (size == 0)
    {
        arr[size].value = value;
        arr[size].priority = priority;
    }
    else
    {
        int i;
        for (i = size-1; i > -1; i--)
        {
            if (arr[i].priority <= priority)
            {
                // size++;
                arr[size].value = value;
                arr[size].priority = priority;
                break;
            }
            else
            {
                // size++;
                arr[i + 1].value = arr[i].value;
                arr[i + 1].priority = arr[i].priority;
            }
        }        
    }
}
void print()
{
    cout << "Printing..." << endl;
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i].value << " ";
    }
    cout << endl;
}

void dequeue()
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main()
{
    enqueue(10, 1);
    enqueue(11, 2);
    enqueue(12, 3);
    enqueue(13, 3);
    enqueue(14, 4);
    enqueue(15, 5);
    cout << endl;
    print();
    dequeue();
    dequeue();
    dequeue();
    print();
    delete[] arr;
    return 0;
}