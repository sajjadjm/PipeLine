#include "Line.h"

Line::Line(unsigned int rot)
{
    SetRotation(rot);
}

void Line::Draw()
{
    spriteTexture.loadFromFile("Sprites/Line.png");
    pipeSprite.setTexture(spriteTexture);
}
