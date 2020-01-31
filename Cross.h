#ifndef CROSS_H_INCLUDED
#define CROSS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Pipe.h"

class Cross : public Pipe
{
private:
    sf::Texture spriteTexture;
public:
    explicit Cross(unsigned int);
    virtual void Rotate() override;
    virtual void Draw() override;
};

#endif // CROSS_H_INCLUDED
