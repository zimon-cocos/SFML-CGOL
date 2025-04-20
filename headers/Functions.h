#pragma once
#include "Objects.h"



void checkCells(int cellNum)
{


    //sused S
    if(cellNum - boxesX >=0)
    {
        std::cout << "Checking S " << cellNum-boxesX << '\n';
       // boxes[cellNum-boxesX].shape.setFillColor(sf::Color::Green);
        if(boxes[cellNum-boxesX].alive)
        {
            ++boxes[cellNum].nAliveAdj;
        }

    }

    //sused J
    //boxes[cellNum+boxesX].shape.setFillColor(sf::Color::Green);
    std::cout << "Checking J " << cellNum+boxesX<< '\n';
    if(boxes[cellNum+boxesX].alive)
    {
        ++boxes[cellNum].nAliveAdj;
    }

    //sused V
    if(boxes[cellNum+1].gridYValue == boxes[cellNum].gridYValue)
    {
       // boxes[cellNum+1].shape.setFillColor(sf::Color::Green);
        if(boxes[cellNum+1].alive)
        {
            ++boxes[cellNum].nAliveAdj;
        }
    }

    std::cout << "Checking V " << cellNum+1<< '\n';

    //sused Z
    if(cellNum-1>=0 && (boxes[cellNum-1].gridYValue == boxes[cellNum].gridYValue))
    {
       // boxes[cellNum-1].shape.setFillColor(sf::Color::Green);
        std::cout << "Checking Z " <<cellNum-1 << '\n';
        if(boxes[cellNum-1].alive)
        {
            ++boxes[cellNum].nAliveAdj;
        }
    }

    //sused SZ
    if(cellNum-boxesX+1>0 && (boxes[cellNum-boxesX+1].gridYValue + 1 == boxes[cellNum].gridYValue))
    {
       // boxes[cellNum-boxesX+1].shape.setFillColor(sf::Color::Green);
        std::cout << "Checking SZ " <<cellNum-boxesX+1 << '\n';
        if(boxes[cellNum-boxesX+1].alive)
        {
            ++boxes[cellNum].nAliveAdj;
        }

    }

    //sused SV
    if(cellNum-boxesX-1>0 && (boxes[cellNum-boxesX-1].gridYValue + 1 == boxes[cellNum].gridYValue))
    {
       // boxes[cellNum-boxesX-1].shape.setFillColor(sf::Color::Green);
        std::cout << "Checking SV " << cellNum-boxesX-1 << '\n';
        if(boxes[cellNum-boxesX-1].alive)
        {
            ++boxes[cellNum].nAliveAdj;
        }
    }

    //sused JZ
    if((boxes[cellNum+boxesX+1].gridYValue-1) == boxes[cellNum].gridYValue)
    {
       // boxes[cellNum+boxesX+1].shape.setFillColor(sf::Color::Green);
    }
    if(boxes[cellNum+boxesX+1].alive)
    {
        ++boxes[cellNum].nAliveAdj;
    }

    std::cout << "Checking JZ " << cellNum+boxesX+1<< '\n';

    //sused JV
    if(cellNum+boxesX-1>0 && boxes[cellNum+boxesX-1].gridYValue - 1 == boxes[cellNum].gridYValue)
    {
       // boxes[cellNum+boxesX-1].shape.setFillColor(sf::Color::Green);
        std::cout << "Checking JV " <<cellNum+boxesX << '\n';
    }
    if(boxes[cellNum+boxesX-1].alive)
    {
        ++boxes[cellNum].nAliveAdj;
    }

    std::cout << "Living neighbours: " << boxes[cellNum].nAliveAdj << '\n';
}

void nextGen(int cellNum)
{
    bool living {boxes[cellNum].alive};
    switch(boxes[cellNum].nAliveAdj)
    {
    case 0:
        if(living)
        {
            std::cout << cellNum << " dies\n";
            boxes[cellNum].alive = false;
            boxes[cellNum].shape.setFillColor(dead);
        }

        break;
    case 1:
        if(living)
        {
            std::cout << cellNum << " dies\n";
            boxes[cellNum].alive = false;
            boxes[cellNum].shape.setFillColor(dead);
        }

        break;
    case 2:
        if(living)
        {
            std::cout << cellNum << " survives\n";
            boxes[cellNum].alive = true;
            boxes[cellNum].shape.setFillColor(alive);
        }

        break;
    case 3:
        if(boxes[cellNum].unpopulated || !boxes[cellNum].alive)
        {
            boxes[cellNum].alive = true;
            boxes[cellNum].shape.setFillColor(alive);
            std::cout << cellNum << " comes alive\n";
        }

        break;
    case 4:
        if(living)
        {
            std::cout << cellNum << " dies\n";
            boxes[cellNum].alive = false;
            boxes[cellNum].shape.setFillColor(dead);
        }

        break;
    case 5:
        if(living)
        {
            std::cout << cellNum << " dies\n";
            boxes[cellNum].alive = false;
            boxes[cellNum].shape.setFillColor(dead);
        }

        break;
    case 6:
        if(living)
        {
            std::cout << cellNum << " dies\n";
            boxes[cellNum].alive = false;
            boxes[cellNum].shape.setFillColor(dead);
        }

        break;
    case 7:
        if(living)
        {
            std::cout << cellNum << " dies\n";
            boxes[cellNum].alive = false;
            boxes[cellNum].shape.setFillColor(dead);
        }

        break;
    case 8:
        if(living)
        {
            std::cout << cellNum << " dies\n";
            boxes[cellNum].alive = false;
            boxes[cellNum].shape.setFillColor(dead);
        }
        break;

    }



}

void clearCells()
{
    for(auto& box: boxes)
    {
        box.shape.setFillColor(sf::Color::White);
        box.nAliveAdj = 0;
        box.alive = false;
        box.unpopulated = true;
    }
}
