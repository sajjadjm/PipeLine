#include <list>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "GameManager.h"
#include "Graph.h"

using namespace std;

int GameManager::temp = 0;

void GameManager::CreateBoard()
{
    for(int i = 0; i < 25; i++)
    {
        if((i + 1) % 5 != 0)
        {
            board.AddEdge(i, i+1);
        }
    }

    for(int i = 0; i < 25; i++)
    {
        if((i + 5) < 25)
        {
            board.AddEdge(i, i+5);
        }
    }
}

void GameManager::GeneratePuzzle()
{
    srand(time(0));

    CreateBoard();

    int curser = 0;

    while(curser < 24)
    {
        cout << "Curser: " << curser << endl;

        vector<int> reachables;

        int neighbors[4] = {-1, -1, -1, -1};

        int counter = 0;

        list<int>::const_iterator i;
        for(i = board.adjacencyMatrix[curser].begin(); i != board.adjacencyMatrix[curser].end(); i++)
        {
            cout << *i << endl;
            neighbors[counter] = *i;
            counter++;
        }
        cout << endl;

        for(int i = 0; i < 4; i++)
        {
            if(neighbors[i] != -1)
            {
                board.RemoveEdge(curser, neighbors[i]);
                if(board.IsReachable(neighbors[i], 24))
                {
                    cout << neighbors[i] << endl;
                    reachables.push_back(neighbors[i]);
                }
            }
        }

        vector<int>::iterator it;
        cout << "Rechables: ";
        for(it = reachables.begin(); it != reachables.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;

        if(reachables.empty())
        {
            throw underflow_error("Error: No Reachable Vertex!!!");
            return;
        }

        if(reachables.size() > 1)
        {
            int r = RandomNum(reachables.size());
            curser = reachables[r];
        }
        else
        {
            board.adjacencyMatrix[curser].clear();
            curser = reachables[0];
        }

        reachables.clear();
    }
}

int GameManager::RandomNum(int max)
{
    int i;
    i = (rand()%max);
    return i;
}
