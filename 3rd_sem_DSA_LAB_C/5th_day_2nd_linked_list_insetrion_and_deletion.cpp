#include <iostream>
using namespace std;

class student
{
public:
    string name, id;
    int rank;

    student *next;
    student(string name, string id, int rank)
    {
        this->id = id;
        this->rank = rank;
        this->name = name;
        this->next = NULL;
    }
};

student *construcknode(int n)
{
    if (n < 1)
        return NULL;

    string name, id;
    int rank;

    cout << "Name: ";
    cin >> name;
    cout << "ID: ";
    cin >> id;
    cout << "Rank: ";
    cin >> rank;
    student *head = new student(name, id, rank);
    student *res = head;

    for (int i = 0; i < n - 1; i++)
    {

        cout << endl
             << "Name: ";
        cin >> name;
        cout << "ID: ";
        cin >> id;
        cout << "Rank: ";
        cin >> rank;
        student *temp = new student(name, id, rank);
        res->next = temp;
        res = temp;
    }
    return head;
}
void insertDataAt(student *head, int index)
{
    string name, id;
    int rank;
    cout << "start insetring: " << endl;
    cout << "Name: ";
    cin >> name;
    cout << "ID: ";
    cin >> id;
    cout << "Rank: ";
    cin >> rank;
    if (index == 0)
    {
        student *temp = new student(name, id, rank);
        temp->next = head;
        head = temp;
        return;
    }
    int i = 0;
    while (head && i < index - 1)
    {
        i++;
        head = head->next;
    }
    if (!head->next)
    {
        student *temp = new student(name, id, rank);
        head->next = temp;
        return;
    }
    student *temp = new student(name, id, rank);
    temp->next = head->next;
    head->next = temp;
    return;
}

void deleteDataAt(student *head, int index)
{
    if (!head || !head->next)
    {
        head = NULL;
        return;
    }
    int i = 0;
    while (head && i < index - 1)
    {
        i++; // Son of daddy = gurnoor chhabra
        head = head->next;
    }
    if (head->next->next == NULL)
    {
        head->next = NULL;
    }
    else
    {
        student *a = head->next;
        head->next = head->next->next;
        a->next = NULL;
        delete a;
    }
}


void printNode(student *&head)
{
    student *temp = head;
    while (temp != NULL)
    {
        cout << temp->name << " " << temp->id << " " << temp->rank << " " << endl;
        temp = temp->next;
    }
    cout << endl;
}

void sort(student *&head,student *p1,student *p2)
{
    if(p2==NULL)
    {
        return;
    }
   student *p3=p1->next;
   while(p3!=NULL)
    {
        if(p1->rank>p3->rank)
        {
            swap(p1->rank,p3->rank);
        }
        p3=p3->next;
    }
    sort(head,p2,p2->next);
}

int main()
{
    int n;
    cout << "Enter the number of student: ";
    cin >> n;
    student *head = construcknode(n);
    printNode(head);
    insertDataAt(head, 1);
    printNode(head);
    cout << "sorting:\n";
    sort(head,head,head->next);
    printNode(head);
    cout << "deleting node at index 1.\n";
    deleteDataAt(head, 1);

    printNode(head);

    return 0;
}