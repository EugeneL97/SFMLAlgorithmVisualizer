#include <cstdlib>
#include <SFML/System.hpp>

#include "Sorting.h"

Sorting::Sorting(int maxBars, int screenWidth, int screenHeight, Render &render)
: maxBars(maxBars), screenWidth(screenWidth), screenHeight(screenHeight), render(render) {
    barWidth = static_cast<float>(screenWidth) / static_cast<float>(maxBars);
    bars.resize(maxBars);
    heights.resize(maxBars);
}

void Sorting::initializeBars() {

    for (int i = 0; i < maxBars; ++i) {
        heights[i] = rand() % screenHeight;
        bars[i].setSize(sf::Vector2f{barWidth, static_cast<float>(heights[i])});
        bars[i].setPosition(i * barWidth, screenHeight - static_cast<float>(heights[i]));
        bars[i].setFillColor(sf::Color::White);
    }
}
void Sorting::visualizeBubbleSort(sf::RenderWindow& window) {
    initializeBars();
    for (int i = 0; i < maxBars; ++i) {
        for (int j = i; j < maxBars - 1; ++j) {
            if (!render.handleWindowEvents(window)) {
                return;
            }
            if (heights[j] > heights[j + 1]) {
                std::swap(heights[j], heights[j + 1]);

                bars[j].setSize(sf::Vector2f{barWidth, static_cast<float>(heights[j])});
                bars[j].setPosition(j * barWidth, screenHeight - static_cast<float>(heights[j]));

                bars[j + 1].setSize(sf::Vector2f{barWidth, static_cast<float>(heights[j + 1])});
                bars[j + 1].setPosition((j + 1) * barWidth, screenHeight - static_cast<float>(heights[j + 1]));

                render.renderBars(window, bars);

                sleep(sf::milliseconds(10));
            }
        }
    }
}
