#pragma once

#include <SFML/Graphics.hpp>

#include "Render.h"

class Sorting
{
    std::vector<sf::RectangleShape> bars;
    std::vector<float> heights;
    int maxBars;
    float barWidth;
    int screenWidth, screenHeight;
    Render& render;
public:
    Sorting(int maxBars, int screenWidth, int screenHeight, Render& render);
    void initializeBars();
    void swapBars(sf::RenderWindow& window, size_t idx1, size_t idx2, sf::Int32 sleepDur);
    void bubbleSort(sf::RenderWindow& window);
    void selectionSort(sf::RenderWindow& window);
    void insertionSort(sf::RenderWindow& window);
    void mergeSort(sf::RenderWindow& window);
    void heapSort(sf::RenderWindow& window);
    void quickSort(sf::RenderWindow& window);
    void countingSort(sf::RenderWindow& window);
    void radixSort(sf::RenderWindow& window);
    void bucketSort(sf::RenderWindow& window);
    void bogoSort(sf::RenderWindow& window);
};
