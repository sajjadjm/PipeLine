#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graph.cpp"
#include "Pipe.h"
#include "Turn.h"
#include "GameManager.cpp"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pipe Line");

    /*GameManager g;
    try
    {
        g.GeneratePuzzle();
    }
    catch(exception& e)
    {
        cout << e.what();
    }*/

    Turn c(2);
    cout << c.GetRotation();
    c.Draw();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 255, 255));
        window.draw(c.pipeSprite);
        window.display();
    }

    return 0;
}
