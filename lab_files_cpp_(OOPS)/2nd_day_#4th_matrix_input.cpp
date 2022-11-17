#include <iostream>
using namespace std;
void input(int m, int n, int *arr)
{
    cout << "Start entering elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> *(arr + i * n + j);
        }
    }
}
void output(int m, int n, int *arr)
{
    cout << "The inputed array is: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(arr + i * n + j) << " ";
        }
        cout << endl;
    }
}
int main()
{
    int m, n;
    cout << "Enter the size of matrix:( n and m ) ";
    cin >> m >> n;
    int *arr = new int[m * n];
    input(m, n, arr);
    output(m, n, arr);
    return 0;
}