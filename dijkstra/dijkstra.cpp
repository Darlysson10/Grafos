#include <vector>
#include <queue>
#include <fstream>
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> Edge;

void addEdge(vector<Edge> adj[], int u, int v, int weight)
{
	adj[u].push_back(make_pair(v, weight));// Grafo direcionado
	//adj[v].push_back(make_pair(u, weight));
}

void dijkstra(vector<Edge> adj[], int v)
{
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	printf("Começando com V0 = 0\n");
	int s = 0;

	vector<int> cost(v, INF);
	vector<int> parent(v, -1);
	vector<bool> visited(v, false);

	pq.push(make_pair(0, s));
	cost[s] = 0;

	while(!pq.empty())
	{
		int v =  pq.top().second;
		pq.pop();

		visited[v] = true;

		for(auto item: adj[v])
		{
			int u = item.first;
			int wt = item.second;
			if(visited[u] == false && cost[u] > cost[v] + wt)
			{
				cost[u] = cost[v] + wt; // dijkstra 
				pq.push(make_pair(cost[u], u));
				parent[u] = v;
			}
		}
	}
	
	printf("Apresentando solução, Árvore de Dijkstra:\n");
	for (int i = 1; i < v; ++i) 
        printf("%d -> %d\n", parent[i], i);
}

int main() 
{
    int v, e, i, j, wt;
    ifstream in("dij.in");
    in >> v >> e;

    vector<Edge> adj[v];
    printf("Criando Grafo...\n");
    while(e--)
    {
    	in >> i >> j >> wt;
    	addEdge(adj, i, j, wt);
    }
    printf("Iniciando o algoritmo de Dijkstra...\n");
    dijkstra(adj, v); 
  
    return 0; 
} 