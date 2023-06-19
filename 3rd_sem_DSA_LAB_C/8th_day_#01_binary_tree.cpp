// 1.) Write C++ program to construct a binary search tree of integers and traverse
//     the tree using all the methods i.e. inorder, preorder & postorder to display
//     the elements in the tree.
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};
node *temp;

void insertNode(node *&head, int *arr, int i)
{
    temp = new node;
    temp->data = arr[i];
    temp->left = NULL;
    temp->right = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    if (head->data > temp->data)
    {
        insertNode(head->left, arr, i);
        return;
    }
    else if (head->data < temp->data)
    {
        insertNode(head->right, arr, i);
        return;
    }
    else if (head->data == temp->data)
    {
        cout << "Invalid case:";
        return;
    }
}
// inorder...
void inorder(node *head)
{
    // base case...
    if (head == NULL)
        return;

    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}

// pre-order
void preorder(node *head)
{
    // base case...
    if (head == NULL)
        return;

    cout << head->data << " ";
    preorder(head->left);
    preorder(head->right);
}

// post-order..
void postorder(node *head)
{
    // base case...
    if (head == NULL)
        return;

    postorder(head->left);
    postorder(head->right);
    cout << head->data << " ";
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Start enternig the elemnts : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        insertNode(head, arr, i);
    }
    cout << "Printing In-order: ";
    inorder(head);
    cout << "\nPrinting Pre-order: ";
    preorder(head);
    cout << "\nPrinting Post-order: ";
    postorder(head);

    return 0;
}