#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <map>
#include <typeinfo>
#include "Graph.cpp"
#include "Pipe.h"
#include "GameManager.cpp"

using namespace std;
using namespace sf;

const int N = 5;
int pipeSize = 108;
Vector2f offset(173, 170);
array<array<Pipe*, 5>, 5> pipeArray;

bool CheckWin();

int main()
{
    GameManager g;
    map <int, Pipe*> pipes;

    try
    {
        pipes = g.GeneratePuzzle();
    }
    catch(exception& e)
    {
        cout << e.what();
    }

    int counter = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            pipeArray[i][j] = pipes[counter];
            counter++;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            pipeArray[i][j]->Draw();
        }
    }

    RenderWindow window(VideoMode(780, 780), "Pipe Line");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
                if(event.key.code == Mouse::Left)
                {
                    Vector2i pos = Mouse::getPosition(window) + Vector2i(pipeSize/2, pipeSize/2) - Vector2i(offset);
                    pos/=pipeSize;
                    if(pos.x > 4 || pos.x < 0 || pos.y < 0 || pos.y > 4 || Mouse::getPosition(window).y < 117 || Mouse::getPosition(window).x < 117)
                    {
                        continue;
                    }
                    pipeArray[pos.y][pos.x]->Rotate();
                    Pipe *p = pipeArray[pos.y][pos.x];
                    cout << p->GetRotation() << "  " << p->GetRandomRotation() << endl;
                }
        }

        window.clear(Color(255, 255, 255));

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                Pipe* p = pipeArray[i][j];
                p->pipeSprite.setTextureRect(IntRect(0, 0, pipeSize, pipeSize));
                p->pipeSprite.setRotation(90 * p->GetRandomRotation());
                p->pipeSprite.setPosition(j * pipeSize, i * pipeSize);
                p->pipeSprite.move(offset);
                window.draw(p->pipeSprite);
            }
        }
        if(CheckWin())
        {
            cout << "You Win!!!" << endl;
        }
        window.display();
    }

    return 0;
}

bool CheckWin()
{
    int counter = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Pipe* p = pipeArray[i][j];
            if(p->GetRotation() != -1 && p->GetRotation() != p->GetRandomRotation())
            {
                if(typeid(*p) != typeid(Cross))
                {
                    counter++;
                }
            }
        }
    }
    if(counter == 0)
        return true;
    else
        return false;
}
