#include "Pipe.h"

using namespace std;

Pipe::Pipe()
{
    SetRotation(0);
}


void Pipe::SetRotation(int rot)
{
    if(rot < 4 && rot >= 0)
    {
        rotation = rot;
    }
}

int Pipe::GetRotation()
{
    return rotation;
}
