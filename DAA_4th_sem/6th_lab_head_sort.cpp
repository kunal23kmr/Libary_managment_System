#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && v[l] > v[largest])
        largest = l;
    if (r < n && v[r] > v[largest])
        largest = r;
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}
void heapSort(vector<int> &v, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
void printV(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of element: ";
    cin >> n;
    vector<int> v;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    cout << "The input array is: ";
    printV(v);
    heapSort(v, n);
    cout<<"Sorted array is: ";
    printV(v);
    return 0;
}