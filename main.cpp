#include <iostream>
#include <SFML/Graphics.hpp>

#include "Sorting.h"
#include "Render.h"
#include "Menu.h"

int main()
{
    enum AppState
    {
        MENU,
        SORTING,
        PATHFINDING
    };
    constexpr int SCREEN_WIDTH = 1920;
    constexpr int SCREEN_HEIGHT = 1080;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Algorithm Visualizer");

    Menu menu;
    AppState currentState = MENU;
    Render render;
    Sorting sorting(50, SCREEN_WIDTH, SCREEN_HEIGHT, render);
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (currentState == MENU) {
                    if (event.key.code == sf::Keyboard::Up) menu.moveUp();
                    else if (event.key.code == sf::Keyboard::Down) menu.moveDown();
                    else if (event.key.code == sf::Keyboard::Enter)
                    {
                        int selected = menu.getSelectedOption();
                        switch (selected) {
                            case BUBBLESORT:
                                currentState = SORTING;
                                sorting.bubbleSort(window);
                                currentState = MENU;
                                break;
                            case EXIT:
                                window.close();
                                break;
                            default:
                                break;
                        }
                    }
                    else if (event.key.code == sf::Keyboard::Escape)
                    {
                        currentState = MENU;  // Go back to the menu
                    }
                }
            }
        }

        // Clear and draw based on the current state
        window.clear();
        if (currentState == MENU)
        {
            menu.draw(window);
            window.display();
        }
    }
    return 0;
}
