#include <iostream>
#include <string.h> 
#include <vector>
#include <algorithm>
#include <stdio.h> 


using namespace std;

class Edges
{
    int v1,v2,wdt;
public:
    Edges(int x1, int x2, int w)
    {
        v1 = x1;
        v2 = x2;
        this->wdt = w;

    }
    int returnV1()
    {
        return v1;
    }
    int returnV2()
    {
        return v2;

    }
    int weight()
    {
        return wdt;
    }

    bool operator < (const Edges& edge) const
    {
        return (wdt < edge.wdt);
    }
};

class Graph
{
    int N;
    vector<Edges> edg;
    int *d; //distancias

public:
    
    Graph(int N)
    {
        this->N = N;

    }

    void addEdge(int nv1, int nv2, int nwdt)
    {
        Edges new_edge(nv1,nv2,nwdt);
        edg.push_back(new_edge);
    }

    void update(int u, int v, int w, int max)
    {
        if (d[u] != max && d[u]+w < d[v])
        {
            d[v] = d[u] + w;
        }

    }

    int check()
    {
        int u,v,w;
        for (int i = 0; i < N -1; i++)
        {
            u = edg[i].returnV1();
            v = edg[i].returnV2();
            w = edg[i].weight();
            if (d[u]+w < d[v])
            {
                
                return 1;
            }

        }
        return 0;
    }   

    void bellman_ford()
    {
        
        int max_number = std::numeric_limits<int>::max();
        int size = edg.size();
        int u,v,w;
        d = new int[size];
        int begin = edg[0].returnV1();
        for (int i = 0; i < N; i++)
        {
            d[i] = max_number;
        }
        d[begin] = 0;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < edg.size(); j++)
            {
                u = edg[j].returnV1();
                v = edg[j].returnV2();
                w = edg[j].weight();
                update(u,v,w,max_number);
            }
        }
        if (check()) return;
        else printGraph();

       

    }

    void printGraph()
    {

        cout << "distancia em relacao ao inicio do grafo" << endl;
        for (int i = 0; i < N; i++)
        {
            cout << "Vertice: "<< i << " distancia: " << d[i] << endl;
          
        }

    }


};



int main(int argc, char *argv[])
{
    int nVertices, nEdges, v1, v2, w;
    freopen("graph.dat", "r", stdin);
    cin >> nVertices;
    cin >> nEdges;
 
    Graph g(nVertices);
    for (int i = 0; i < nEdges; i++)
    {
        cin >> v1;
        cin >> v2;
        cin >> w;

        g.addEdge(v1,v2,w);
    }
    g.bellman_ford();
    //g.printGraph();

    
    return 0;
}