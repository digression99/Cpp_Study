//
//
//
//
//
//
//
//
//
//

#include <iostream>
using namespace std;
#include <cmath>

const int MAXV = 50;
const int MAXDEGREE = 10;

static int parent[MAXV];

class Edge
{
public:
    int v; // vertex num
    int w; // weight
};

class Graph
{
public:
    Edge edges[MAXV + 1][MAXDEGREE];
    int degree[MAXV + 1];
    int nvertices;
    int nedges;
};
// need to initialize

void prim(Graph * g, int start)
{
    bool intree[MAXV]; // 정점이 트리에 들어있는지 여부
    int distance[MAXV]; // 시작점으로부터의 거리
    int v;          // 지금 처리할 정점
    int w;           // 다음 정점 후보
    int weight;     //모서리의 가중치
    int dist;       //현재 최단 거리
    
    for (int i = 1; i <= g->nvertices; ++i)
    {
        intree[i] = false;
        distance[i] = INT_MAX / 2;
        parent[i] = -1;
    }
    
    distance[start] = 0;
    v = start;
    
    while (intree[v] == false)
    {
        intree[v] = true;
        for (int i = 0; i < g->degree[v]; ++i)
        {
            w = g->edges[v][i].v;
            weight = g->edges[v][i].w;
            if ((distance[w] > weight) && (intree[w] == false)) {
                distance[w] = weight;
                parent[w] = v;
            }
        }
        
        //v = 1;
        dist = INT_MAX / 2;
        for (int i = 1; i <= g->nvertices; ++i)
            if ((intree[i] == false) && (dist > distance[i]))
            {
                dist = distance[i];
                v = i;
            }
    }
}

void dijkstra(Graph * g, int start)
{
    bool intree[MAXV];
    int distance[MAXV];
    int v;
    int w;
    int weight;
    int dist;
    
    for (int i = 1; i <= g->nvertices; ++i)
    {
        intree[i] = false;
        distance[i] = INT_MAX / 2;
        parent[i] = -1;
    }
    
    distance[start] = 0;
    v = start;
    
    while (intree[v] == false)
    {
        intree[v] = true;
        for (int i = 0; i < g->degree[v]; ++i)
        {
//            if (distance[ g->edges[v][i].v ] > (distance[v] + g->edges[v][i].w))
//            {
//                distance[ g->edges[v][i].v ] = distance[v] + g->edges[v][i].w;
//                parent[ g->edges[v][i].v ] = v;
//            }
            
            w = g->edges[v][i].v;
            weight = g->edges[v][i].w;
            
            if (distance[w] > (distance[v] + weight))
            {
                distance[w] = distance[v] + weight;
                parent[w] = v;
            }
        }
        
        v = 1;
        dist = INT_MAX / 2;
        
        for (int i = 1; i <= g->nvertices; ++i)
        {
            if ((intree[i] == false) && (dist > distance[i]))
            {
                dist = distance[i];
                v = i;
            }
        }
    }
}

int main()
{
    return 0;
}
