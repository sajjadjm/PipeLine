#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED
#include <SFML/Graphics.hpp>

class Pipe
{
protected:
    unsigned int randomRotation;
    unsigned int rotation;
public:
    sf::Sprite pipeSprite;
    explicit Pipe();
    void SetRotation(int);
    void Rotate();
    int GetRotation();
    void SetRandomRotation(int);
    int GetRandomRotation();
    virtual void Draw() = 0;
};

#endif // PIPE_H_INCLUDED
