#include "Turn.h"

Turn::Turn(unsigned int rot)
{
    SetRotation(rot);
}

void Turn::Draw()
{
    spriteTexture.loadFromFile("Images/Turn.png");
    pipeSprite.setTexture(spriteTexture);
    pipeSprite.setOrigin(54, 54);
}
