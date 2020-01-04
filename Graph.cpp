#include "Graph.h"
#include <iostream>
#include <iterator>

using namespace std;

void Graph::CreateGridGraph()
{
    for(int i = 0; i < MAXIMUM; i++)
    {
        for(int j = 0; j < MAXIMUM; j++)
        {
            adjacencyMatrix[i][j] = false;
        }
    }
}

void Graph::AddEdge(int source, int target)
{
    adjacencyMatrix[source][target] = true;
    adjacencyMatrix[target][source] = true;
}

bool Graph::HasEdge(int source, int target) const
{
    bool isAnEdge = false;
    isAnEdge = (adjacencyMatrix[source][target] || adjacencyMatrix[target][source]);
    return isAnEdge;
}

list<int> Graph::Neighbors(int vertex)
{
    list<int> vertexNeighbors;

    for(int index = 0; index < MAXIMUM; index++)
    {
        if(adjacencyMatrix[vertex][index] || adjacencyMatrix[index][vertex])
        {
            vertexNeighbors.push_back(index);
        }
    }
    return vertexNeighbors;
}

bool Graph::IsReachable(int source, int target)
{
    bool *visited = new bool[MAXIMUM];
    for (int i = 0; i < MAXIMUM; i++)
        visited[i] = false;

    list<int> queue;

    visited[source] = true;
    queue.push_back(source);

    list<int>::iterator i;

    while(!queue.empty())
    {
        source = queue.front();
        queue.pop_front();

        for(i = this->Neighbors(source).begin(); i != this->Neighbors(source).end(); ++i)
        {
            if(*i == target)
            {
                return true;
            }

            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::RemoveEdge(int source, int target)
{
    adjacencyMatrix[source][target] = false;
    adjacencyMatrix[target][source] = false;
}
