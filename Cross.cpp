#include "Cross.h"

Cross::Cross(unsigned int rot)
{
    SetRotation(rot);
}

void Cross::Draw()
{
    spriteTexture.loadFromFile("Sprites/Cross.png");
    pipeSprite.setTexture(spriteTexture);
}
