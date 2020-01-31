#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Pipe.h"

class Line : public Pipe
{
private:
    sf::Texture spriteTexture;
public:
    explicit Line(unsigned int);
    virtual void Rotate() override;
    virtual void Draw() override;
};

#endif // LINE_H_INCLUDED
