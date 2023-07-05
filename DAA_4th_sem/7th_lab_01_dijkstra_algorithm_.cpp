#include <iostream>
#include <limits.h>
using namespace std;

int minDistance(int dist[], bool visited[]){
    int min = INT_MAX, min_index;
    for (int v = 0; v < 4; v++) {
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    }
    return min_index;
}
void print(int dist[]){
    cout << "Vertex --> Distance from Source" << endl;
    for (int i = 0; i < 4; i++)
        cout << i << "   -->  " << dist[i] << endl;
}
void dijkstra(int graph[4][4], int src){
    int dist[4];
    bool visited[4];
    for (int i = 0; i < 4; i++)
        dist[i] = INT_MAX, visited[i] = false;
    dist[src] = 0;
    for (int i = 0; i < 4 - 1; i++){
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < 4; v++){
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    print(dist);
}
int main(){
    cout << "Source node is : 0" << endl;    
    int graph[4][4] = {{0, 4, 0, 2}, {4, 0, 8, 0}, {0, 8, 0, 7}, {2, 0, 7, 0}};
    dijkstra(graph, 0);
    return 0;
}