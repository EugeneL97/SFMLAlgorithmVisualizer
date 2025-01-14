#include "Menu.h"

Menu::Menu() : selectedIndex(0){
    options = {"Bubble Sort", "Test", "Exit"};
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "We gotta blow this whole thing up...";
    }
}

void Menu::drawMenu(sf::RenderWindow& window) {
    for (size_t i = 0; i < options.size(); ++i) {
        menuText.setString(options[i]);
        menuText.setPosition(100, 100 + i * 40);
        menuText.setFillColor(i == selectedIndex ? highlightedColor : defaultColor);
        window.draw(menuText);
    }
}

void Menu::moveUp() {
    if (selectedIndex > 0) {
        selectedIndex--;
    }
}

void Menu::moveDown() {
    if (selectedIndex < options.size() - 1) {
        selectedIndex++;
    }
}

int Menu::getSelectedOption() {
    return selectedIndex;
}

