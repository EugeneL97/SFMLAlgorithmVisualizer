#include "Render.h"

void Render::renderBars(sf::RenderWindow &window, const std::vector<sf::RectangleShape>& bars)
{
    window.clear(sf::Color::Black);
    for (const auto& bar : bars)
    {
        window.draw(bar);
    }
    window.display();
}

bool Render::handleWindowEvents(sf::RenderWindow &window)
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return false;
        }
        // Able to quit to menu during sorting (if it's taking too long)
        if (event.key.code == sf::Keyboard::Escape)
        {
            return false;
        }
    }
    return true;
}

void Render::waitForUserInput(sf::RenderWindow& window)
{
    sf::Event event{};
    while (window.waitEvent(event)) {
        if (event.type == sf::Event::KeyPressed &&
           (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Escape))
        {
            return;  // Exit on Enter or Escape
        }
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return;
        }
    }
}