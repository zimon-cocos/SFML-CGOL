#include <iostream>
#include <SFML/Graphics.hpp>
#include "headers/ConstantsAndVariables.h"
#include "headers/Functions.h"
#include "headers/Objects.h"
#include "headers/Random.h"

int main()

{
    sf::Clock clock;
    sf::RenderWindow window (sf::VideoMode({width,height}),"Boilerplate");
    window.setFramerateLimit(fps);

    for(int i {0}; i<boxAmountY; ++i)
        {
        for(int i {0};i<boxAmountX; ++i)
            {
                boxes.emplace_back(outlineThickness*2+gapX+boxesOffset,outlineThickness*2+gapY+boxesOffset);
                gapX += boxWidth+outlineThickness*2;

            }

        gapX  = 0;
        gapY += boxWidth+outlineThickness*2;
        }

    for(long unsigned int i {0}; i<boxes.size(); ++i)
        {
            if(boxesX < boxAmountX)
            {
                boxes[i].gridXValue = boxesX;
                boxes[i].gridYValue = boxesY;
                ++boxesX;
            }
            else
            {
                boxesX = 0;
                ++boxesY;
                boxes[i].gridXValue = boxesX;
                boxes[i].gridYValue = boxesY;
                ++boxesX;
            }

        }



    while(window.isOpen())
        {

        while(const std::optional event = window.pollEvent())
            {

        if(event->is<sf::Event::Closed>())
            {
            window.close();
            }
        else if(const auto*keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            {
                window.close();
            }
            }

        }

        if((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))) && clock.getElapsedTime().asSeconds() > 0.2)
        {
            clock.restart();
            auto mousePos = sf::Mouse::getPosition(window);
            auto transMousePos = window.mapPixelToCoords(mousePos);
            for(unsigned int i {0};i<boxes.size();++i)
            {
                if(boxes[i].shape.getGlobalBounds().contains(transMousePos))
                {
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        checkCells(i);
                        nextGen(i);
                    }
                    else
                    {
                        boxes[i].shape.setFillColor(sf::Color::Magenta);
                        boxes[i].alive = true;
                        boxes[i].unpopulated = false;
                    }
                }
            }
        }




        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            clearCells();
        }
        /*
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && clock.getElapsedTime().asSeconds()>0.2)
        {
            clock.restart();
            for(unsigned int i {0}; i<boxes.size();++i)
            {
                checkCells(i);

            }
            for(unsigned int i {0}; i<boxes.size();++i)
            {
                nextGen(i);
                boxes[i].nAliveAdj = 0;

            }

        }*/

       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            start = true;
        }

        while(start)
        {
            if(clock.getElapsedTime().asSeconds()>0.02)
            {
                clock.restart();

                for(unsigned int i {0}; i<boxes.size();++i)
                    {
                        checkCells(i);

                    }

                for(unsigned int i {0}; i<boxes.size();++i)
                {
                    nextGen(i);
                    boxes[i].nAliveAdj = 0;

                }
            }

            window.clear(sf::Color::White);
            for(auto& box : boxes) window.draw(box.shape);
            window.display();

        }
        //Render
        window.clear(sf::Color::White);

        //DRAWING
        //window->draw(sprite);

        for(auto& box : boxes) window.draw(box.shape);
        window.display();
    }

}


