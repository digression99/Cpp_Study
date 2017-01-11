#include <iostream>
using namespace std;
#include <deque>

static const int MAXV = 100; // 모서리의 최대 차수
static const int MAXDEGREE = 50; // 출력 차수의 최댓값
static bool processed[MAXV]; // bfs, dfs
static bool discovered[MAXV]; // bfs, dfs
static int parent[MAXV]; // bfs, dfs
static bool finished = false; // dfs

class Graph {
public:
    int edges[MAXV + 1][MAXDEGREE]; // 인접한 셀에 대한 정보
    int degree[MAXV + 1]; // 각 정점의 출력 차수
    int nvertices; // 그래프에 있는 정점 개수
    int nedges; // 그래프에 있는 모서리 수
    
    void readGraph(bool directed);
    void initializeGraph();
    void insertEdge(int x, int y, bool directed);
    void printGraph();
private:
};

void initializeSearch(Graph * g);
void bfs(Graph * g, int start);
void processVertex(int v);
void processEdge(int x, int y);
void findPath(int start, int end, int parents[]); // in bfs
bool validEdge(int e);
void dfs(Graph * g, int v);
void dfsProcessVertex(int v);
void dfsProcessEdge(int x, int y);
void connectedComponents(Graph * g);
void topologicalSort(Graph * g, int sorted[]);
void computeIndegrees(Graph * g, int in[]);
void topSortPrint(int sorted[], int s);

void computeIndegrees(Graph * g, int in[])
{
    for (int i = 1; i <= g->nvertices; ++i)
        in[i] = 0;
    
    for (int i = 1; i <= g->nvertices; ++i)
    {
        for (int j = 0; j < g->degree[i]; ++j)
        {
            in[ g->edges[i][j] ]++;
        }
    }
}

void topSortPrint(int sorted[], int s)
{
    for (int i = 1; i <= s; ++i)
    {
        cout << " " << sorted[i];
    }
    cout << endl;
}

void topologicalSort(Graph * g, int sorted[]) // sorted는 결과배열.
{
    int indegree[MAXV]; // 각 정점의 입력 차수
    deque<int> zeroin; // 입력 차수가 0인 정점
    int x, y; // 현재 정점과 다음 정점
    int j; // 카운터
    
    computeIndegrees(g, indegree);
    zeroin.clear();
    
    for (int i = 1; i <= g->nvertices; ++i)
    {
        if (indegree[i] == 0)
            zeroin.push_back(i);
    }
    
    j = 0;
    while (zeroin.empty() == false)
    {
        j++;
        
        x = *zeroin.begin();
        zeroin.pop_front();
        
        sorted[j] = x;
        for (int i = 0; i < g->degree[x]; ++i) // 앞에 것과 연결된 것부터 degree가 줄어들 것이므로
        {                                      // 앞에서부터 뒤로 진행되는 게 맞다.
            y = g->edges[x][i];
            indegree[y]--;
            if (indegree[y] == 0)
                zeroin.push_back(y);
        }
    }
    
    if (j != g->nvertices)
        cout << "not a dag -- only " << j << "vertices found\n";
}


void connectedComponents(Graph * g)
{
    int c = 0;
    
    initializeSearch(g);
    
    for (int i = 1; i <= g->nvertices; ++i)
    {
        if (discovered[i] == false) // discovered false이면 dfs한번 했는데 모두 연결이 안됐다는 것이다.
        {
            c++;
            cout << "Component " << c << " : ";
            dfs(g, i);
            cout << endl;
        }
    }
}

void dfs(Graph * g, int v)
{
    int y;
    
    if (finished) return;
    
    discovered[v] = true;
    dfsProcessVertex(v);
    
    for (int i = 0; i < g->degree[v]; ++i)
    {
        y = g->edges[v][i];
        
        if (validEdge(g->edges[v][i]) == true)
        {
            if (discovered[y] == false)
            {
                parent[y] = v;
                dfs(g, y);
            }
            else
            {
                if (processed[y] == false)
                {
                    dfsProcessEdge(v, y);
                }
            }
        }
        if (finished) return;
    }
    
    processed[v] = true;
}

void dfsProcessEdge(int x, int y)
{
    if (parent[x] != y)
    {
        cout << "cycle from " << y << " to " << x;
        findPath(y, x, parent);
        finished = true;
    }
    
    cout << "processed edge : (" << x << ", "<<  y << ")" << endl;
    
}

void dfsProcessVertex(int v)
{
    cout << "processed vertex : " << v << endl;
}

void findPath(int start, int end, int parents[])
{
    if ((start == end) || (end == -1))
    {
        cout << endl << start;
    }
    else
    {
        findPath(start, parents[end], parents);
        cout << " " << end;
    }
}

void bfs(Graph * g, int start)
{
    deque<int> q; // 정점 큐
    int v; // 현재 정점
    
    q.clear();
    q.push_back(start);
    discovered[start] = true;
    
    while (q.empty() == false)
    {
        v = *q.begin();
        q.pop_front();
        
        processVertex(v);
        
        processed[v] = true;
        
        for (int i = 0; i < g->degree[v]; ++i) // degree만큼 돈다.
        {
            if (validEdge(g->edges[v][i]) == true)
            {
                if (discovered[g->edges[v][i]] == false)
                {
                    q.push_back(g->edges[v][i]);
                    discovered[g->edges[v][i]] = true;
                    parent[g->edges[v][i]] = v; // pi값을 v로 설정한다. (dijkstra)
                }
                
                if (processed[g->edges[v][i]] == false)
                {
                    processEdge(v, g->edges[v][i]);
                }
            }
        }
    }
}

void initializeSearch(Graph * g)
{
    for (int i = 1; i <= g->nvertices; ++i)
    {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
}

bool validEdge(int v)
{
    return true;
}

void processVertex(int v)
{
    // depth 같은 걸 정의해서 마지막 v에 왔을 때
    // 무언가를 하는 로직을 구현할 수도 있다.
    cout << "processed vertex : " << v << endl;
}

void processEdge(int x, int y)
{
    cout << "processed edge : (" << x << ", "<<  y << ")" << endl;
}

void Graph::readGraph(bool directed)
{
    int m;
    int x, y;
    
    initializeGraph();
    
    cin >> this->nvertices >> m;
    
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        insertEdge(x, y, directed);
    }
}

void Graph::initializeGraph()
{
    this->nvertices = 0;
    this->nedges = 0;
    for (int i = 1; i <= MAXV; ++i)
    {
        this->degree[i] = 0;
    }
}

void Graph::insertEdge(int x, int y, bool directed)
{
    if (this->degree[x] > MAXDEGREE)
    {
        cout << "warning : insertion " << x << y << " exceeds max degree\n";
    }
    
    this->edges[x][this->degree[x]] = y;
    this->degree[x]++;
    
    if (directed == false)
    {
        insertEdge(y, x, true);
    }
    else
        this->nedges++;
}

void Graph::printGraph()
{
    for (int i = 1; i <= this->nvertices; ++i)
    {
        cout << i;
        for (int j = 0; j < this->degree[i]; ++j) // degree는 0부터 시작한다.
        {
            cout << " " << this->edges[i][j];
        }
        cout << endl;
    }
}

int main()
{
    Graph g;
    int sorted[MAXV];
    
    //g.initializeGraph();
    g.readGraph(true);
    g.printGraph();
    
//    cout << "bfs ! " << endl;
//    initializeSearch(&g);
//    bfs(&g, 1);
//    
//    cout << "find path from 1 to end ! " << endl;
//    findPath(1, g.nvertices, parent);
//    cout << endl;
//    
//    cout << "dfs !" << endl;
//    initializeSearch(&g);
//    dfs(&g, 1);
    
    topologicalSort(&g, sorted);
    topSortPrint(sorted, g.nvertices);
    
    return 0;
}