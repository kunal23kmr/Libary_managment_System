// A left rotation operation on an array of size  shifts each of the array&#39;s elements  unit to the
// left. Given an integer, , rotate the array that many steps left and return the result.
#include <iostream>
using namespace std;

void rotate(int *arr, int d, int n);

int main()
{
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;
    int arr[n], i;
    cout << "Enter the array ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int d;
    cout << endl
         << "Enter number of rotations: ";
    cin >> d;
    rotate(arr, d, n);
    return 0;
}
void rotate(int *arr, int d, int n)
{
    int temp = 0, i = 0, a;
    a = d % n;
        while (i < a)
        {
            temp = arr[0];
            for (int j = 0; j < (n - 1); j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = temp;
            i++;
        }
    cout << "The rotated array is: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}