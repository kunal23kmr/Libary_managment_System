#include <iostream>
using namespace std;

int n;

class node
{
    int val;

public:
    node *next, *pre;

    // default constructor...
    node() { next = pre = NULL; }

    // parameterised..

    node(int val)
    {
        this->val = val;
        next = pre = NULL;
    }
    void print(node *head)
    {
        cout << "Printing the list..." << endl;
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

node *createList(int n, node *pre)
{
    int x;
    node *temp = NULL;
    // base condition...
    if (n == 0)
        return temp;
    cout << "Enter the value of node: ";
    cin >> x;
    temp = new node(x);
    temp->pre = pre;
    temp->next = createList(--n, temp);
}

void insert(node *&head, int n)
{
    int x;
    // at head condition..
    if (n == 0)
    {
        node *temp = NULL;
        cout << "Enter the value to insert: ";
        cin >> x;
        temp = new node(x);
        temp->next = head;
        head->pre = temp;
        head = temp;
        return;
    }
    // at last condition..
    while (n--)
    {
        head = head->next;
    }
    if (!head)
    {
        node *temp = NULL;
        cout << "Enter the value to insert: ";
        cin >> x;
        temp = new node(x);
        head->next = temp;
        temp->pre = head;
        return;
    }
    else
    {
        node *temp = NULL, *a = head, *b = head->pre;
        cout << "Enter the value to insert: ";
        cin >> x;
        temp = new node(x);
        b->next = temp;
        temp->next = a;
        temp->pre = b;
        a->pre = temp;
        return;
    }
}

void del(node *&head, int n)
{
    node *t = head;
    // at head...
    if (n == 0)
    {
        head = head->next;
        head->pre = NULL;
        t->next = NULL;
        delete t;
        return;
    }
    // at last...
    while (n--)
    {
        t = t->next;
    }
    //last
    if (!t->next)
    {
        node *temp = t;
        temp->pre->next = NULL;
        temp->pre = NULL;
        delete temp;
    }
    else
    {
        node *a = t->pre, *b = t->next;
        a->next = b;
        b->pre = a;
        t->next = t->pre = NULL;
        delete t;
    }
}
int main()
{
    cout << "Enter the number of node: ";
    cin >> n;
    node *head = NULL;
    head = createList(n, head);
    head->print(head);

    cout << "Enter the index at you want to insert: ";
    cin >> n;
    insert(head, n);
    head->print(head);

    cout << "Enter the index where you want to delete: ";
    cin >> n;
    del(head, n);
    head->print(head);

    return 0;
}