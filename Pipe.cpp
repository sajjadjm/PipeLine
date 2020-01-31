#include "Pipe.h"

using namespace std;

Pipe::Pipe()
{
    SetRotation(0);
    SetRandomRotation(0);
}


void Pipe::SetRotation(int rot)
{
    if(rot < 4 && rot >= 0)
    {
        rotation = rot;
    }
}

void Pipe::SetRandomRotation(int rot)
{
    if(rot < 4 && rot >= 0)
    {
        randomRotation = rot;
    }
}

void Pipe::Rotate()
{
    randomRotation++;
}

int Pipe::GetRotation()
{
    return rotation;
}

int Pipe::GetRandomRotation()
{
    return randomRotation;
}
