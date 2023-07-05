#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> s;
void visit(int node, vector<bool> &visited, vector<vector<int>> &adj){
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++){
        if (visited[adj[node][i]] == false)
            visit(adj[node][i], visited, adj);
    }
    s.push(node);
}
vector<int> DAG(int n, vector<vector<int>> &edges){
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < edges.size(); i++)
        adj[edges[i][0]].push_back(edges[i][1]);

    for (int i = 0; i < n; i++){
        if (visited[i] == false)
            visit(i, visited, adj);
    }
    vector<int> v;
    while (!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    return v;
}
int main(){
    cout << "Source node is : 0"  << endl;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    cout << "The edges are: \n";
    for (auto i : edges){
        cout << i[0]<<"->" <<i[1]<<endl;
    }
    vector<int> tSortOrder = DAG(6, edges);
    cout << "The topological sorted order is: \n";
    for (auto i : tSortOrder){
        cout << i << " ";
    }
    return 0;
}