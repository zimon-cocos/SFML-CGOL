#pragma once
#include "Objects.h"



void checkCells(int cellNum)
{


    //sused S
    if(cellNum - boxesX >=0)
    {
        std::cout << "Checking " << cellNum-boxesX << '\n';
        boxes[cellNum-boxesX].shape.setFillColor(sf::Color::Green);
    }

    //sused J

    boxes[cellNum+boxesX].shape.setFillColor(sf::Color::Green);
    //sused V
    boxes[cellNum+1].shape.setFillColor(sf::Color::Green);
    //sused Z

    if(cellNum-1>=0)
    {
        boxes[cellNum-1].shape.setFillColor(sf::Color::Green);
    }

    //sused SZ
    if(cellNum-boxesX+1>=0)
    {
        boxes[cellNum-boxesX+1].shape.setFillColor(sf::Color::Green);
    }

    //sused SV
    if(cellNum-boxesX+1>=0)
    {
        boxes[cellNum-boxesX-1].shape.setFillColor(sf::Color::Green);
    }

    //sused JZ
    boxes[cellNum+boxesX+1].shape.setFillColor(sf::Color::Green);
    //sused JV

    if(cellNum+boxesX-1>=0)
    {
        boxes[cellNum+boxesX-1].shape.setFillColor(sf::Color::Green);
    }



}
