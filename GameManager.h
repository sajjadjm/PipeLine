#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED

#include "Graph.h"
#include "Pipe.h"

#include <map>

class GameManager
{
private:
    Graph board;
    std::map<int, Pipe*> Pipes;
    void CreateBoard();
    void GetPipeTypes(int source, int curser, int target);
    int RandomNum(int max);
public:
    std::map<int, Pipe*> GeneratePuzzle();
    ~GameManager();
};

#endif // GAMEMANAGER_H_INCLUDED
