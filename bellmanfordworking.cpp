//
//
// bellman-ford algo
//
//
//
//
//
//
//
//

#include <vector>
#include <iostream>
using namespace std;

const int MAX_WEIGHT = 9999;

class Graph
{
    class Edge;
    class Vertex;
    
    class Edge
    {
    public:
        int weight;
        Vertex * left;
        Vertex * right;
        Edge(int weight, Vertex * l, Vertex * r)
        {
            this->weight = weight;
            this->left = l;
            this->right = r;
        }
    };
    class Vertex
    {
    public:
        int d;
        Vertex * pi;
        //vector<Vertex *> connected;
        Vertex() {}
        Vertex(int d, Vertex * pi)
        {
            this->d = d;
            this->pi = pi;
        }
    };
private:
    vector<Vertex> vertexArr;
    vector<Edge> edgeArr;
public:
    Graph() {}
    void makeVertex(int d, Vertex * pi)
    {
        this->vertexArr.push_back(Vertex(d, pi));
        return;
    }
    
    void pushVertex(Vertex & v)
    {
        vertexArr.push_back(v);
        return;
    }
    void connectVertices(int weight, int idx1, int idx2)
    {
        this->edgeArr.push_back(
            Edge(weight,
                 &this->vertexArr[idx1],
                 &this->vertexArr[idx2]));
        return;
    }
    Vertex * searchVertex(Vertex * target) // return memory address
    {
        for (int i = 0; i < this->vertexArr.size(); ++i)
        {
            if (&this->vertexArr[i] == target)
                return &this->vertexArr[i];
        }
        
        return nullptr;
    }
};

// g.getEdgeArr
// g.getEdgeNum
// g.getVertexNum
// g.getEdgeArr.getLeft
// g.getEdgeArr.getRight

void relax(Edge * e)
{
    if (e->getLeft()->d >
        e->getRight()->d +
        e->weight)
    {
        e->getLeft()->d =
        e->getRight()->d + e->weight;
        e->getLeft()->pi = e->getRight();
    }
}

bool bellmanFord(Graph * g, Vertex * start)
{
    //initialize
    for (int i = 0; i < g.getVertexNum() - 1; ++i)
    {
        for (int j = 0; j < g.getEdgeNum(); ++j)
        {
            relax(&g.getEdgeArr()[j]);
        }
    }
    
    for (int i = 0; i < g.getEdgeNum(); ++j)
    {
        if (g.getEdgeArr()[j].getLeft()->d >
            g.getEdgeArr()[j].getRight()->d +
            g.getEdgeArr()[j].weight)
        {
            return false;
        }
    }
    return true;
}

// initialize
//
// 1. for each vertex
//  v.d = inf;
//  v.pi = nil;
//  s.d = 0;


int main()
{
    Graph g;
    g.makeVertex(MAX_WEIGHT, nullptr);
    g.makeVertex(MAX_WEIGHT, nullptr);
    g.connectVertices(10, 0, 1);
    

    return 0;
}





























