#pragma once

uint16_t  width {1000};
uint16_t height {1000};
int fps {60};
bool start {false};


float gapX {0};
float gapY {0};
float boxWidth {15.0f};
float outlineThickness {2.0f};
float boxesOffset{0};

int boxAmountX {20};
int boxAmountY {20};
int boxesX {0};
int boxesY {0};

//colors

sf::Color dead(128,128,128);
sf::Color alive(173,255,47);
sf::Color background(102, 108, 138);

