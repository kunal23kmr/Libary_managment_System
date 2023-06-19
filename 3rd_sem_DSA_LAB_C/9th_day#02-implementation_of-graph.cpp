// Write a program to implement a graph using adjacency matrix representation.
//(Undirected-Graph)
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    // int **arr=new int[n][n];
    int *arr = new int[n * n];
    for (int i = 0; i < n * n; i++)
    {
        arr[i] = 0;
    }

    int *val = new int[n];
    cout << "Enter the key value of edges: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int edges;
    cout << "Enter the number of vertices: ";
    cin >> edges;
    int i = edges;

    while (i--)
    {
        int a = 0, b = 0;
        int indexA = n, indexB = n;
        cout << "Enter the pair to connect: ";
        cin >> a >> b;

        for (int i = 0; i < n; i++)
        {
            if (val[i] == a)
                indexA = i;
            if (val[i] == b)
                indexB = i;
        }
        if (indexA < n && indexB < n)
        {
            arr[n * indexA + indexB] = arr[n * indexB + indexA] = 1;
        }
    }

    // // cout << "Press '1' for YES, and '0' for NO \n";

    // // for (int i = 0; i < n; i++)
    // // {
    // //     for (int j = i + 1; j < n; j++)
    // //     {
    // //         int x = 0;
    // //         cout << "Is there a edge between " << val[i] << " and " << val[j] << ": ";

    // //         cin >> x;
    // //         if (x == 1)
    // //         {
    // //             arr[i * n + j] = 1;
    // //             arr[j * n + i] = 1;
    // //         }
    // //         else
    // //         {
    // //             arr[i * n + j] == 0;
    // //             arr[j * n + i] = 0;
    // //         }
    // //     }
    // // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i * n + j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << "The list: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << val[i] << " -> ";
        for (int j = 0; j < n; j++)
        {
            if (arr[(n * i + j)] == 1)
            {
                cout << val[j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}