#pragma once

#include <SFML/Graphics.hpp>

#include "Render.h"

class Sorting {
    std::vector<sf::RectangleShape> bars;
    std::vector<float> heights;
    int maxBars;
    float barWidth;
    int screenWidth, screenHeight;
    Render& render;
public:
    Sorting(int maxBars, int screenWidth, int screenHeight, Render& render);
    void initializeBars();
    void visualizeBubbleSort(sf::RenderWindow& window);
};
