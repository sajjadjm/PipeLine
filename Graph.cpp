#include "Graph.h"
#include "GameManager.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void Graph::AddEdge(int source, int target)
{
    adjacencyMatrix[source].push_back(target);
    adjacencyMatrix[target].push_back(source);
}

void Graph::RemoveEdge(int source, int target)
{
    adjacencyMatrix[source].remove(target);
    adjacencyMatrix[target].remove(source);
}

bool Graph::IsReachable(const int s, int d)
{
    int source = s;
    if (source == d)
      return true;

    bool *visited = new bool[MAXIMUM];
    memset(visited, false, sizeof(visited));

    list<int> queue;

    visited[source] = true;
    queue.push_back(source);

    while (!queue.empty())
    {
        source = queue.front();
        queue.pop_front();

        list<int>::iterator i;
        for (i = adjacencyMatrix[source].begin(); i != adjacencyMatrix[source].end(); i++)
        {
            if (*i == d)
                return true;

            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    delete[] visited;
    return false;
}
