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
    

public:
    vector<Edges> edg;
    vector<Edges> tree; 
    int *father;
    int *v;
    int *rank;

    Graph(int N)
    {
        this->N = N;
        father = new int[N];
        v = new int[N];
        rank = new int[N];
    }

    void addEdge(int nv1, int nv2, int nwdt)
    {
        Edges new_edge(nv1,nv2,nwdt);
        edg.push_back(new_edge);
    }

    void printGraph()
    {

        for (int i = 0; i < edg.size(); i++)
        {
            cout << edg[i].returnV1() << " " << edg[i].returnV2() << " " <<edg[i].weight() << endl;
          
        }

    }
    void makeset(int x)
    {
        father[x] = x;
        rank[x] = 0;
    }

    int find(int x)
    {
        if(father[x] != x)
        {
            father[x] = find(father[x]);
        }
        return father[x];

    }

    void unite(int x, int y)
    {
        if (rank[x] >= rank[y])
        {
            father[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
        else   
            father[x] = y;
    }

    void getV()
    {
        int index1,index2;
        for (int i = 0; i < edg.size(); i++) 
        {
            index1 = edg[i].returnV1();
            index2 = edg[i].returnV2();
            if (v[index1] != index1)
            {
                v[index1] = index1;
                
            }
            if (v[index2] != index2)
            {
                v[index2] = index2;
            }

        }
    }

    void kruskal()
    {
         
        getV();
       
        for (int i = 0; i < N; i++)
        {
            makeset(i);
        }

        sort(edg.begin(), edg.end());
        
        for (int i = 0; i < edg.size(); i++)
        {
            int rep1 = find(edg[i].returnV1());
            int rep2 = find(edg[i].returnV2());
            if (rep1 != rep2)
            {
                tree.push_back(edg[i]);
                unite(rep1,rep2);
            }
        }
        
        for (int i = 0; i < tree.size(); i++)
        {
            cout << tree[i].returnV1() << " " << tree[i].returnV2() << " " << tree[i].weight() << endl; 
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
    cout << "Arvore:" << endl;
    g.kruskal();

    //g.printGraph();
    
    return 0;
}