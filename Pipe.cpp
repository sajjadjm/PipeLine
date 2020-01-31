#include "Pipe.h"
#include <iostream>

using namespace std;

Pipe::Pipe()
{
    SetRotation(0);
    SetRandomRotation(0);
}


void Pipe::SetRotation(int rot)
{
    if(rot < 4 && rot >= -1)
    {
        rotation = rot;
    }
    else
    {
        cout << "Invalid argument!!!" << endl;
    }
}

void Pipe::SetRandomRotation(int rot)
{
    if(rot < 4 && rot >= 0)
    {
        randomRotation = rot;
    }
}

int Pipe::GetRotation()
{
    return rotation;
}

int Pipe::GetRandomRotation()
{
    return randomRotation;
}
