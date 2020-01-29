#include <list>
#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include "GameManager.h"
#include "Turn.h"
#include "Line.h"
#include "Cross.h"

using namespace std;

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

map<int, Pipe*> GameManager::GeneratePuzzle()
{
    srand(time(0));

    CreateBoard();

    int curser = 0;
    int source = -5;
    int target = 0;

    while(curser <= 24)
    {
        cout << "Curser: " << curser << endl;

        if(curser == 24)
        {
            return Pipes;
        }

        vector<int> reachables;

        int neighbors[4] = {-1, -1, -1, -1};

        int counter = 0;

        list<int>::const_iterator i;
        for(i = board.adjacencyMatrix[curser].begin(); i != board.adjacencyMatrix[curser].end(); i++)
        {
            neighbors[counter] = *i;
            counter++;
        }

        for(int i = 0; i < 4; i++)
        {
            if(neighbors[i] != -1)
            {
                board.RemoveEdge(curser, neighbors[i]);
                if(board.IsReachable(neighbors[i], 24))
                {
                    reachables.push_back(neighbors[i]);
                }
            }
        }

        if(reachables.empty())
        {
            throw underflow_error("Error: No Reachable Vertex!!!");
        }

        else if(reachables.size() > 1)
        {
            int r = RandomNum(reachables.size());
            target = reachables[r];
            GetPipeTypes(source, curser, target);
            cout << typeid(*(Pipes[curser])).name() << endl;
            source = curser;
            curser = reachables[r];
        }
        else
        {
            board.adjacencyMatrix[curser].clear();
            target = reachables[0];
            GetPipeTypes(source, curser, target);
            cout << typeid(*(Pipes[curser])).name() << endl;
            source = curser;
            curser = reachables[0];
        }

        reachables.clear();
    }
}

void GameManager::GetPipeTypes(int source, int curser, int target)
{
    int temp1 = source - curser;
    int temp2 = curser - target;
    Pipe* p;

    if((temp1 == -5 && temp2 == -1) || (temp1 == 1 && temp2 == 5))
    {
        Pipes[curser] = new Turn(0);
    }

    else if((temp1 == 5 && temp2 == -1) || (temp1 == 1 && temp2 == -5))
    {
        Pipes[curser] = new Turn(1);
    }

    else if((temp1 == -1 && temp2 == -5) || (temp1 == 5 && temp2 == 1))
    {
        Pipes[curser] = new Turn(2);
    }

    else if((temp1 == -1 && temp2 == 5) || (temp1 == -5 && temp2 == 1))
    {
        Pipes[curser] = new Turn(3);
    }

    else if((abs(temp1) == abs(temp2)) && (abs(temp1) == 1))
    {
        int rand = RandomNum(2);

        if(rand == 0)
        {
            Pipes[curser] = new Line(1);
        }
        else
        {
            Pipes[curser] = new Cross(0);
            board.AddEdge(curser, curser + 1);
            board.AddEdge(curser, curser - 1);
        }
    }

    else if((abs(temp1) == abs(temp2)) && (abs(temp1) == 5))
    {
        int rand = RandomNum(2);

        if(rand == 0)
        {
            Pipes[curser] = new Line(0);
        }
        else
        {
            Pipes[curser] = new Cross(0);
            board.AddEdge(curser, curser + 5);
            board.AddEdge(curser, curser - 5);
        }
    }
}

int GameManager::RandomNum(int max)
{
    int i;
    i = (rand()%max);
    return i;
}
