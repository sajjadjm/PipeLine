#include "Pipe.h"
#include <SFML/Graphics.hpp>



using namespace std;
using namespace sf;

Pipe::Pipe(int x, int y)
{
    set_Coordinate(x, y);
}

void Pipe::set_Coordinate(int x, int y)
{
    coordinates.x = x;
    coordinates.y = y;
}

void Pipe::set_Orientation(int angle)
{
    orientation = angle;
}

Vector2i Pipe::get_Coordinate()
{
    return coordinates;
}

int Pipe::get_Orientation()
{
    return orientation;
}

