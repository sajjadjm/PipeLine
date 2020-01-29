#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED
#include <SFML/Graphics.hpp>

class Pipe
{
protected:
    unsigned int rotation;
public:
    sf::Sprite pipeSprite;
    explicit Pipe();
    void SetRotation(int);
    int GetRotation();
    virtual void Draw() = 0;
};

#endif // PIPE_H_INCLUDED
