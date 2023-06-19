#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node(int val)
    {
        this->val = val;
    }
};

node *createNode(int a)
{
    node *temp = NULL;

    if (a == 0)
    {
        return temp;
    }
    int n;
    cin >> n;
    temp = new node(n);
    temp->next = createNode(a - 1);
    return temp;
}

int compare_list(node *head1, node *head2)
{
    int x = 1;
    while (head1 && head2)
    {
        if (head1->val != head2->val)
        {
            x = 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 || head2)
        x = 0;
    return x;
}

int main()
{
    int size1 = 0, size2 = 0;
    node *head1 = NULL, *head2 = NULL;

    cout << "Enter the size of list 1: ";
    cin >> size1;
    cout << "Start entering the elements of list1:\n";
    head1 = createNode(size1);

    cout << "Enter the size of list 2: ";
    cin >> size2;
    cout << "Start entering the elements of list2:\n";
    head2 = createNode(size2);

    // comparing the lists...
    cout << "Return value of comparision: " << compare_list(head1, head2) << ".\n";

    return 0;
}