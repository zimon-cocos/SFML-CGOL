#pragma once


struct Box
{

    //!DOLEZITE!
    sf::RectangleShape shape;
    //!DOLEZITE!

    float centerPosX {0};
    float centerPosY {0};


    bool wasClicked {false};

    int gridXValue {0};
    int gridYValue {0};

    Box(float bX, float bY)
    {
        shape.setPosition({bX,bY});
        shape.setFillColor(sf::Color::Transparent);
        shape.setSize({boxWidth,boxWidth});
        shape.setOutlineThickness(outlineThickness);
        shape.setOutlineColor(sf::Color::Black);
        centerPosX = (bX + (boxWidth/2));
        centerPosY = (bY + (boxWidth/2));
    }

};

std::vector<Box> boxes;
