#include <iostream>
#include <SFML/Graphics.hpp>

#include "Sorting.h"
#include "Render.h"
#include "Menu.h"

int main() {
    // constexpr int SCREEN_WIDTH = 1920;
    // constexpr int SCREEN_HEIGHT = 1080;
    // int totalBars = 0;
    //
    // std::cout << "How many bars would you like? ";
    // std::cin >> totalBars;
    //
    // sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Algorithm Visualizer");
    //
    // Menu menu;
    //
    // Render render;
    // Sorting sorting(totalBars, SCREEN_WIDTH, SCREEN_HEIGHT, render);
    //
    // sorting.visualizeBubbleSort(window);
    //
    // return 0;



    // constexpr int SCREEN_WIDTH = 1920;
    // constexpr int SCREEN_HEIGHT = 1080;
    // sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Algorithm Visualizer");
    //
    // Menu menu;
    // bool inMenu = true;
    //
    // while (window.isOpen()) {
    //     sf::Event event{};
    //     while (window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //         else if (event.type == sf::Event::KeyPressed) {
    //             if (inMenu) {
    //                 if (event.key.code == sf::Keyboard::Up) menu.moveUp();
    //                 else if (event.key.code == sf::Keyboard::Down) menu.moveDown();
    //                 else if (event.key.code == sf::Keyboard::Enter) {
    //                     int selected = menu.getSelectedOption();
    //                     if (selected == EXIT) window.close();
    //                     else {
    //                         // Call respective visualization function
    //                         inMenu = false;
    //                     }
    //                 }
    //             } else if (event.key.code == sf::Keyboard::Escape) {
    //                 inMenu = true;
    //             }
    //         }
    //     }
    //
    //     window.clear();
    //     if (inMenu) menu.draw(window);
    //     else {
    //         Render render;
    //         Sorting sorting(200, SCREEN_WIDTH, SCREEN_HEIGHT, render);
    //
    //         sorting.visualizeBubbleSort(window);
    //     }
    //     window.display();
    // }
    //
    // return 0;
    enum AppState {
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
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (currentState == MENU) {
                    if (event.key.code == sf::Keyboard::Up) menu.moveUp();
                    else if (event.key.code == sf::Keyboard::Down) menu.moveDown();
                    else if (event.key.code == sf::Keyboard::Enter) {
                        int selected = menu.getSelectedOption();
                        switch (selected) {
                            case BUBBLESORT:
                                currentState = SORTING;
                                sorting.visualizeBubbleSort(window);
                                currentState = MENU;
                                break;
                            case EXIT:
                                window.close();
                                break;
                            default:
                                break;
                        }
                    } else if (event.key.code == sf::Keyboard::Escape) {
                        currentState = MENU;  // Go back to the menu
                    }
                }
            }
        }

        // Clear and draw based on the current state
        window.clear();
        if (currentState == MENU) {
            menu.draw(window);
            window.display();
        }
    }
    return 0;
}
