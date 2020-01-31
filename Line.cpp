#include "Line.h"

Line::Line(unsigned int rot)
{
    SetRotation(rot);
}

void Line::Draw()
{
    spriteTexture.loadFromFile("Images/Line.png");
    pipeSprite.setTexture(spriteTexture);
    pipeSprite.setOrigin(54, 54);
}
