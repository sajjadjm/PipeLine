#include "Turn.h"

Turn::Turn(unsigned int rot)
{
    SetRotation(rot);
}

void Turn::Draw()
{
    spriteTexture.loadFromFile("Sprites/Turn.png");
    pipeSprite.setTexture(spriteTexture);
}
