#include "Line.h"

Line::Line(unsigned int rot)
{
    SetRotation(rot);
}

void Line::SetRandomRotation(int rot)
{
    if(rot == 0 || rot == 2)
    {
        randomRotation = 0;
    }
    else if(rot == 1 || rot == 3)
    {
        randomRotation = 1;
    }
}

void Line::Rotate()
{
    if(randomRotation == 0 || randomRotation == 2)
    {
        randomRotation = 1;
    }
    else if(randomRotation == 1 || randomRotation == 3)
    {
        randomRotation = 0;
    }
}

void Line::Draw()
{
    spriteTexture.loadFromFile("Images/Line.png");
    pipeSprite.setTexture(spriteTexture);
    pipeSprite.setOrigin(54, 54);
}
