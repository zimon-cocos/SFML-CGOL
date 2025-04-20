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
                        //boxes[i].shape.setFillColor(sf::Color::Black);
                        std::cout<< "[" << boxes[i].gridXValue << "," << boxes[i].gridYValue << "]\n";
                        std::cout << "Klikol si na " << i << '\n';
                    }
                    else
                    {
                        boxes[i].shape.setFillColor(sf::Color::Magenta);
                        boxes[i].alive = true;
                        boxes[i].unpopulated = false;
                    }



                   /* //sused S
                    boxes[i-boxesX].shape.setFillColor(sf::Color::Green);
                    //sused J
                    boxes[i+boxesX].shape.setFillColor(sf::Color::Green);
                    //sused V
                    boxes[i+1].shape.setFillColor(sf::Color::Green);
                    //sused Z
                    boxes[i-1].shape.setFillColor(sf::Color::Green);

                    //sused SZ
                    boxes[i-boxesX+1].shape.setFillColor(sf::Color::Green);
                    //sused SV
                    boxes[i-boxesX-1].shape.setFillColor(sf::Color::Green);

                    //sused JZ
                    boxes[i+boxesX+1].shape.setFillColor(sf::Color::Green);
                    //sused JV
                    boxes[i+boxesX-1].shape.setFillColor(sf::Color::Green);
*/

                }
            }
        }




        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            clearCells();
        }

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

            }
            for(unsigned int i {0}; i<boxes.size();++i)
            {
                boxes[i].nAliveAdj = 0;

            }
        }

       /* while(start)
        {
            for(unsigned int i {0}; i<boxes.size();++i)
                {
                    checkCells(i);
                    nextGen(i);
                }

            window.clear(sf::Color::White);
            for(auto& box : boxes) window.draw(box.shape);
            window.display();

        }*/


        //Render
        window.clear(sf::Color::White);

        //DRAWING
        //window->draw(sprite);

        for(auto& box : boxes) window.draw(box.shape);
        window.display();
    }

}


