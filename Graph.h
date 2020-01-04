#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <list>

class Graph
{
private:
    static const int MAXIMUM = 25;
    bool adjacencyMatrix [MAXIMUM][MAXIMUM];

public:
    void CreateGridGraph();
    void AddEdge(int source, int target);
    void RemoveEdge(int source, int target);
    bool HasEdge(int source, int target)const;
    bool IsReachable(int source, int target);
    std::list<int> Neighbors(int vertex);
};


#endif // GRAPH_H_INCLUDED
