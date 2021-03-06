#include "Cross.h"

Cross::Cross(unsigned int rot)
{
    SetRotation(rot);
}

void Cross::Rotate()
{
    if(randomRotation == 3)
    {
        randomRotation = 0;
    }
    else
    {
        randomRotation++;
    }
}

void Cross::Draw()
{
    spriteTexture.loadFromFile("Images/Cross.png");
    pipeSprite.setTexture(spriteTexture);
    pipeSprite.setOrigin(54, 54);
}
