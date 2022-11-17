#include <iostream>
using namespace std;

void merge(int *arr, int l, int mid, int r)
{
    int *arr1 = new int[mid - l + 1];
    int *arr2 = new int[r - mid];

    //  1st array
    for (int i = 0; i < mid - l + 1; i++)
    {
        arr1[i] = arr[l + i];
    }
    // 2nd array
    for (int i =0; i < r - mid; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < (mid - l + 1) && j < (r - mid))
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < mid - l + 1)
    {
        arr[k] = arr1[i];
        k++,i++;
    }
    while (j < r - mid)
    {
        arr[k] = arr2[j];
        k++,j++;
    }
    delete []arr1;
    delete []arr2;
}

void mergesort(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int mid =(r + l) / 2;

    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

void print(int *arr, int n)
{
    cout << "The array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of element: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    print(arr, n);
    mergesort(arr, 0, n-1);
    print(arr, n);
    return 0;
}