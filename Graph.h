#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <set>

class Graph
{
private:
    static const int MAXIMUM = 25;
    bool adjacencyMatrix [MAXIMUM][MAXIMUM];
    int manyVertices = 0;

public:
    void AddVertex();
    void AddEdge(int source, int target);
    void RemoveEdge(int source, int target);
    void Test();
    bool HasEdge(int source, int target)const;
    std::set<int> Neighbors(int vertex);
};


#endif // GRAPH_H_INCLUDED
