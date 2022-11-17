#include <iostream>
using namespace std;

void insertionSort(int *arr, int n)
{
    cout << "Sorting..." << endl;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j--];
        }
        arr[j + 1] = key;
    }
}

void print(int *arr, int n)
{
    cout << "printing array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);
    print(arr, n);

    return 0;
}