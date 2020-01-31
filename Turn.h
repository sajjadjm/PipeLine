#ifndef TURN_H_INCLUDED
#define TURN_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Pipe.h"

class Turn : public Pipe
{
private:
    sf::Texture spriteTexture;
public:
    explicit Turn(unsigned int rot);
    virtual void Rotate() override;
    virtual void Draw() override;
};

#endif // TURN_H_INCLUDED
