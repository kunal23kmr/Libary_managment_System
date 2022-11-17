#include <iostream>
using namespace std;

class Queue
{
    int front, rear, capacity;
    int *queue;

public:
    Queue(int capacity)
    {
        front = rear = 0;
        this->capacity = capacity;
        queue = new int[this->capacity];
    }

    ~Queue()
    {
        delete[] queue;
    }

    void enqueue(int data)
    {
        if (capacity == rear)
        {
            cout << endl
                 << "The queue is full";
            return;
        }
        else
        {
            queue[rear] = data;
            rear++;
        }
        return;
    }

    void dequeue()
    {
        if (front == rear)
        {
            cout << endl
                 << "The queue is empty." << endl;
            return;
        }
        else
        {
            for (int i = 0; i < rear - 1; i++)
            {
                queue[i] = queue[i + 1];
                rear--;
            }
            return;
        }
    }

    void display()
    {
        cout << endl;
        int i;
        if (front == rear)
        {
            cout << endl
                 << "The queue is empty." << endl;
            return;
        }
        for (i = front; i < rear; i++)
        {
            cout << queue[i] << " ";
        }
        return;
    }
    int isfull()
    {
        if (capacity == rear)
        {
            cout << "Queue is full.";
            this->display();
            return 0;
        }
        else
            return 1;
    }
};

int main()
{
    int a, b;
    cout << "Enter the size: ";
    cin >> b;
    // here Queue is a user defined data structure (class)...
    Queue q1(b);
    cout << "Enter the element to enqueue: ";
    for (; q1.isfull();)
    {
        cin >> a;
        q1.enqueue(a);
    }
    return 0;
}