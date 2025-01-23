#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
/* Arrow Up and Arrow Down Navigation
 * Highlight text when currently on it (text is Yellow when highlighted, White otherwise)
 * Once you hit enter and select an option, execute that algorithm
 * Can create a Menu and Sorting object in main.cpp
 *      Use the Sorting object to call the Sorting algorithm
 *      Will expand this to pathfinding algorithms eventually
 *      Should it only create a Sorting object when it selects the algorithm? I think so.
 *          If we expand to Pathfinding, we wouldn't want to create both objects in the menu when we're not using both.
 */
enum MenuOptions
{
    BUBBLESORT,
    BOGOSORT,
    EXIT
};
class Menu
{
private:
    std::vector<std::string> options;
    sf::Font font;
    sf::Text menuText;
    int selectedIndex;
    sf::Color defaultColor = sf::Color::White;
    sf::Color highlightedColor = sf::Color::Yellow;
public:
    Menu();
    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    int getSelectedOption() const;
};

