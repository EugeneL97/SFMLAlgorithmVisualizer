#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    constexpr int WIDTH = 1920;
    constexpr int HEIGHT = 1080;

    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Algorithm Visualizer");

    constexpr int MAX_BARS = 200;
    constexpr float BAR_WIDTH = static_cast<float>(WIDTH) / static_cast<float>(MAX_BARS);

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
        for (int i = 0; i < MAX_BARS; ++i) {
            for (int j = i; j < MAX_BARS - 1; ++j) {
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
                if (heights[j] > heights[j + 1]) {
                    std::swap(heights[j], heights[j + 1]);

                    bars[j].setSize(sf::Vector2f{BAR_WIDTH, static_cast<float>(heights[j])});
                    bars[j].setPosition(j * BAR_WIDTH, HEIGHT - static_cast<float>(heights[j]));

                    bars[j + 1].setSize(sf::Vector2f{BAR_WIDTH, static_cast<float>(heights[j + 1])});
                    bars[j + 1].setPosition((j + 1) * BAR_WIDTH, HEIGHT - static_cast<float>(heights[j + 1]));


                    window.clear(sf::Color::Black);
                    for (const auto& bar: bars) {
                        window.draw(bar);
                    }
                    window.display();

                    sleep(sf::milliseconds(0));
                }
            }
        }
        window.clear(sf::Color::Black);
        for (const auto& bar : bars) {
            window.draw(bar);
        }
        window.display();
    }
    return 0;
}
