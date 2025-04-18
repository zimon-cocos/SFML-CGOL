#pragma once
#include "Objects.h"



void checkCells(int cellNum)
{


    //sused S
    if(cellNum - boxesX >=0)
    {
        std::cout << "Checking S " << cellNum-boxesX << '\n';
        boxes[cellNum-boxesX].shape.setFillColor(sf::Color::Green);
    }

    //sused J
    boxes[cellNum+boxesX].shape.setFillColor(sf::Color::Green);
    std::cout << "Checking J " << cellNum+boxesX<< '\n';

    //sused V
    if(boxes[cellNum+1].gridYValue == boxes[cellNum].gridYValue)
    {
        boxes[cellNum+1].shape.setFillColor(sf::Color::Green);
    }

    std::cout << "Checking V " << cellNum+1<< '\n';

    //sused Z
    if(cellNum-1>=0 && (boxes[cellNum-1].gridYValue == boxes[cellNum].gridYValue))
    {
        boxes[cellNum-1].shape.setFillColor(sf::Color::Green);
        std::cout << "Checking Z " <<cellNum-1 << '\n';
    }

    //sused SZ
    if(cellNum-boxesX+1>0 && (boxes[cellNum-boxesX+1].gridYValue + 1 == boxes[cellNum].gridYValue))
    {
        boxes[cellNum-boxesX+1].shape.setFillColor(sf::Color::Green);
        std::cout << "Checking SZ " <<cellNum-boxesX+1 << '\n';
    }

    //sused SV
    if(cellNum-boxesX-1>0 && (boxes[cellNum-boxesX-1].gridYValue + 1 == boxes[cellNum].gridYValue))
    {
        boxes[cellNum-boxesX-1].shape.setFillColor(sf::Color::Green);
        std::cout << "Checking SV " << cellNum-boxesX-1 << '\n';
    }

    //sused JZ
    if((boxes[cellNum+boxesX+1].gridYValue-1) == boxes[cellNum].gridYValue)
    {
        boxes[cellNum+boxesX+1].shape.setFillColor(sf::Color::Green);
    }

    std::cout << "Checking JZ " << cellNum+boxesX+1<< '\n';

    //sused JV
    if(cellNum+boxesX-1>0 && boxes[cellNum+boxesX-1].gridYValue - 1 == boxes[cellNum].gridYValue)
    {
        boxes[cellNum+boxesX-1].shape.setFillColor(sf::Color::Green);
        std::cout << "Checking JV " <<cellNum+boxesX << '\n';
    }

}

void clearCells()
{
    for(auto& box: boxes)
    {
        box.shape.setFillColor(sf::Color::White);
    }
}
