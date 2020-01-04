#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graph.cpp"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pipe Line");

    Graph g;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 255, 255));
        window.display();
    }

    return 0;
}
