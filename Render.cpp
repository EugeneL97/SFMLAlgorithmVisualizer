#include "Render.h"

void Render::renderBars(sf::RenderWindow &window, const std::vector<sf::RectangleShape>& bars) {
    window.clear(sf::Color::Black);
    for (const auto& bar : bars) {
        window.draw(bar);
    }
    window.display();
}

bool Render::handleWindowEvents(sf::RenderWindow &window) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return false;
        }
    }
    return true;
}
