#include "Graph.h"
#include <assert.h>
#include <iostream>

using namespace std;

void Graph::AddVertex()
{
    int newVertexNumber = manyVertices;
    manyVertices++;

    for(int otherVertexNumber = 0; otherVertexNumber < manyVertices; otherVertexNumber++)
    {
        adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
        adjacencyMatrix[newVertexNumber][otherVertexNumber] = false;
    }
}

void Graph::AddEdge(int source, int target)
{
    adjacencyMatrix[source][target] = true;
}

bool Graph::HasEdge(int source, int target) const
{
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target];
    return isAnEdge;
}

set<int> Graph::Neighbors(int vertex)
{
    set<int> vertexNeighbors;

    for(int index = 0; index < MAXIMUM; index++)
    {
        if(adjacencyMatrix[vertex][index])
        {
            vertexNeighbors.insert(index);
        }
    }
    return vertexNeighbors;
}

void Graph::RemoveEdge(int source, int target)
{
    adjacencyMatrix[source][target] = false;
}

void Graph::Test()
{
    cout << MAXIMUM;
}
