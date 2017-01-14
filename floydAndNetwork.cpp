#include <iostream>
using namespace std;

const int MAXV = 100;
const int MAXINT = 987654321;

int parent[MAXV];

class AdjacencyMatrix
{
public:
    int weight[MAXV + 1][MAXV + 1];
    int nvertices;
};

class Edge
{
public:
    int v; // 이웃한 정점
    int capacity; // 모서리 용량
    int flow; // 모서리를 통과하는 흐름
    int residual; // 남은 용량
};

class FlowGraph
{
public:
    Edge edges[MAXV][MAXV];
    int degree[MAXV];
    
};

void addResidualEdges(FlowGraph * g);
void initializeSearch(FlowGraph * g);
void bfs(FlowGraph * g, int s);
int pathVolume(FlowGraph * g, int s, int sink, int * parent);
void augmentPath(FlowGraph * g, int source, int sink, int * parent, int vol);
Edge * findEdge(FlowGraph * g, int x, int y);

void initializeAdjancencyMatrix(AdjacencyMatrix * g)
{
    g->nvertices = 0;
    
    for (int i = 1; i <= MAXV; ++i)
    {
        for (int j = 1; j <= MAXV; ++j)
        {
            g->weight[i][j] = MAXINT;
        }
    }
}

void readAdjacencyMatrix(AdjacencyMatrix * g, bool directed)
{
    int m; // 모서리 개수
    int x, y, w; // 모서리, 가중치 저장용
    
    initializeAdjancencyMatrix(g);
    
    cin >> g->nvertices >> m;
    
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y >> w;
        g->weight[x][y] = w;
        if (directed == false)
            g->weight[y][x] = w;
    }
}

void floyd(AdjacencyMatrix * g)
{
    int through_k;
    
    for (int k = 1; k <= g->nvertices; ++k)
    {
        for (int i = 1; i <= g->nvertices; ++i)
        {
            for (int j = 1; j <= g->nvertices; ++j)
            {
                through_k = g->weight[i][k] + g->weight[k][j];
                if (through_k < g->weight[i][j])
                {
                    g->weight[i][j] = through_k;
                }
            }
        }
    }
}

void netflow(FlowGraph * g, int source, int sink)
{
    int volume; // 증가 경로의 가중치
    
    addResidualEdges(g);
    initializeSearch(g);
    bfs(g, source);
    
    volume = pathVolume(g, source, sink, parent);
    
    while (volume > 0)
    {
        augmentPath(g, source, sink, parent, volume);
        initializeSearch(g);
        bfs(g, source);
        volume = pathVolume(g, source, sink, parent);
    }
}

bool validEdge(Edge e)
{
    if (e.residual > 0) return true;
    return false;
}

int pathVolume(FlowGraph * g, int start, int end, int parents[])
{
    Edge * e;
    
    if (parents[end] == -1) return 0;
    
    e = findEdge(g, parents[end], end);
    if (start == parents[end])
        return e->residual;
    else
        return min(pathVolume(g, start, parents[end], parents), e->residual);
}

Edge * findEdge(FlowGraph * g, int x, int y)
{
    for (int i = 0; i < g->degree[x]; ++i)
    {
        if (g->edges[x][i].v == y)
            return &g->edges[x][i];
    }
    return nullptr;
}

void augmentPath(FlowGraph * g, int start, int end, int * parents, int volume)
{
    Edge * e;
    
    if (start == end) return;
    
    e = findEdge(g, parents[end], end);
    e->flow += volume;
    e->residual -= volume;
    
    e = findEdge(g, end, parents[end]);
    e->residual += volume;
    
    augmentPath(g, start, parents[end], parents, volume);
}

