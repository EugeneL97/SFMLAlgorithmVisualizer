#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    const int WIDTH = 1920;
    const int HEIGHT = 1080;

    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Algorithm Visualizer");

    const int MAX_BARS = 100;
    const float BAR_WIDTH = WIDTH / MAX_BARS;

    std::vector<sf::RectangleShape> bars (MAX_BARS);
    std::vector<int> heights (MAX_BARS);

    for (int i = 0; i < MAX_BARS; ++i) {
        heights[i] = rand() % HEIGHT;
        bars[i].setSize(sf::Vector2f{BAR_WIDTH, static_cast<float>(heights[i])});
        bars[i].setPosition(i * BAR_WIDTH, HEIGHT - static_cast<float>(heights[i]));
        bars[i].setFillColor(sf::Color::White);
    }
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        for (auto bar: bars) {
            window.draw(bar);
        }
        window.display();
    }

    return 0;
}
