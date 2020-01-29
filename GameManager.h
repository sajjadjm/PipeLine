#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED

#include "Graph.h"
#include "Pipe.h"

#include <map>

class GameManager
{
private:
    Graph board;
    void CreateBoard();
    Pipe* GetPipeTypes(int source, int curser, int target);
    int RandomNum(int max);
public:
    std::map<int, Pipe*> GeneratePuzzle();
};

#endif // GAMEMANAGER_H_INCLUDED
