// write a program to implement binary search in an array. Also analyze it's time complexity.
#include <iostream>
using namespace std;
void sort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                continue;
            }
            if (arr[i] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main()
{
    int target, n, i;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, n);
    cout << "THe array is: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl
         << "Enter the elemnet for search: ";
    cin >> target;
    int start = 0, end = 9;
    int mid, x;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (a[mid] == target)
        {
            cout << "Element founded at index " << mid << "." << endl;
            x++;
            break;
        }
        else if (a[mid] < target)
        {
            start = mid + 1;
        }
        else if (a[mid] > target)
        {
            end = mid - 1;
        }
    }
    if (x)
    {
        cout << endl
             << "Element not found...";
    }

    return 0;
}