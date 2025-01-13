#include <iostream>
#include <SFML/Graphics.hpp>

#include "Sorting.h"
#include "Render.h"
#include "Menu.h"

int main() {
    constexpr int SCREEN_WIDTH = 1920;
    constexpr int SCREEN_HEIGHT = 1080;
    int totalBars = 0;

    std::cout << "How many bars would you like? ";
    std::cin >> totalBars;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Algorithm Visualizer");

    Menu menu;

    Render render;
    Sorting sorting(totalBars, SCREEN_WIDTH, SCREEN_HEIGHT, render);

    sorting.visualizeBubbleSort(window);

    return 0;
}
