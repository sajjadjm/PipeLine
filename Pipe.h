#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class Pipe
{
public:

    Pipe(int, int);
    Pipe* begin_Cell;
    void set_Coordinate(int, int);
    sf::Vector2i get_Coordinate();
    void set_Orientation(int);
    int get_Orientation();

protected:

    bool is_Border;
    bool is_Empty;
    int orientation;
    sf::Vector2i coordinates;

};

#endif // PIPE_H_INCLUDED
