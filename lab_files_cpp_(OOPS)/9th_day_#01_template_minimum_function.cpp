#include <iostream>
using namespace std;

// template...
template <class t>
t minFun(t *arr, int n)
{
    t min = arr[0];
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (min > arr[i])
                min = arr[i];
        }
    }
    cout << "minimum is: " << min << endl;
}

// deriver function...
int main()
{

    int arr1[5] = {1, 5, 3, 7, 9};
    char arr2[5] = {'a', 'c', 't', 'e', 'g'};
    float arr3[5] = {20.4, 4.2, 4, 30, 1.1};
    minFun<int>(arr1, 5);
    minFun<char>(arr2, 5);
    minFun<float>(arr3, 5);
    return 0;
}