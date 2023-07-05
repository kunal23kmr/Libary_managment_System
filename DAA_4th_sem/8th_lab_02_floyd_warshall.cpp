#include <iostream>
using namespace std;
#define V 4							//vertex
#define INF 99999999				//infinity value
void printSolution(int graph[][V]){
	for (int i = 0; i < V; i++)	{
		for (int j = 0; j < V; j++){
			if (graph[i][j] == INF)
				cout << "INF ";
			else
				cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}
void floydWarshall(int graph[][V]){
	int i, j, k;
	for (k = 0; k < V; k++){
		for (i = 0; i < V; i++){
			for (j = 0; j < V; j++){
				if ((graph[k][j] != INF && graph[i][k] != INF) && (graph[i][j] > (graph[i][k] + graph[k][j])))
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	cout << "The result of floyd warshall algorithm:" << endl;
	printSolution(graph);
}
int main(){
	int graph[V][V] = {{0, 5, INF, 10}, 	// weight matrix
					   {INF, 0, 3, INF},
					   {INF, INF, 0, 1},
					   {INF, INF, INF, 0}};
	floydWarshall(graph);
	return 0;
}