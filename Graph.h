#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <list>
#include <array>

class Graph
{
private:
    static const int MAXIMUM = 25;
public:
    void AddEdge(int source, int target);
    void RemoveEdge(int source, int target);
    bool IsReachable(int source, int target);
    std::array<std::list<int>, MAXIMUM> adjacencyMatrix;
};


#endif // GRAPH_H_INCLUDED
