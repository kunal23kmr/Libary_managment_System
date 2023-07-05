// Ajacency matrix representation.
//(Undirected-Graph)
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int arr[n][n] = {214783647}; // vertex + weight
    bool visited[n] = {false};

    cout << "Enter Both vertices and there corressponding weight:" << endl;
    for (int i = 0; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u][v] = w;
        arr[v][u] = w;
    }
    stack<int> s;
    s.push(0);

    while (!s.empty())
    {
        visited[s.top()] = true;
        int min;
        for (int i = 0; i < n; i++)
        {
            if (arr[s.top()][i] != 214783647)
            {
                if (!visited[s.top()])
                {
                    s.push(arr[s.top()][i]);
                }
            }
        }
    }

    
    return 0;
}