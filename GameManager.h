#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED

#include "Graph.h"

class GameManager
{
private:
    Graph board;
    void CreateBoard();
    int RandomNum(int max);
public:
    void GeneratePuzzle();
    static int temp;
};

#endif // GAMEMANAGER_H_INCLUDED
