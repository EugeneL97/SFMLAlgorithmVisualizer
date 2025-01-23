#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Render
{
public:
    void renderBars(sf::RenderWindow& window, const std::vector<sf::RectangleShape>& bars);
    bool handleWindowEvents(sf::RenderWindow& window);
    void waitForUserInput(sf::RenderWindow& window);
};
