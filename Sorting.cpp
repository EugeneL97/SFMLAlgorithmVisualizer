#include <cstdlib>
#include <SFML/System.hpp>

#include "Sorting.h"

#include <chrono>

Sorting::Sorting(int maxBars, int screenWidth, int screenHeight, Render &render)
: maxBars(maxBars), screenWidth(screenWidth), screenHeight(screenHeight), render(render)
{
    barWidth = static_cast<float>(screenWidth) / maxBars;
    bars.resize(maxBars);
    heights.resize(maxBars);
}

void Sorting::initializeBars()
{
    for (int i = 0; i < maxBars; ++i)
        {
        heights[i] = rand() % screenHeight;
        bars[i].setSize(sf::Vector2f{barWidth, (heights[i])});
        bars[i].setPosition(i * barWidth, screenHeight - heights[i]);
        bars[i].setFillColor(sf::Color::White);
    }
}

void Sorting::swapBars(sf::RenderWindow& window, size_t idx1, size_t idx2, sf::Int32 sleepDur)
{
    std::swap(heights[idx1], heights[idx2]);

    bars[idx1].setSize(sf::Vector2f(barWidth, heights[idx1]));
    bars[idx1].setPosition(idx1 * barWidth, screenHeight - heights[idx1]);

    bars[idx2].setFillColor(sf::Color::Red);
    bars[idx2].setSize(sf::Vector2f(barWidth, heights[idx2]));
    bars[idx2].setPosition(idx2 * barWidth, screenHeight - heights[idx2]);

    render.renderBars(window, bars);

    bars[idx2].setFillColor(sf::Color::White);

    sleep(sf::milliseconds(sleepDur));
}
void Sorting::bubbleSort(sf::RenderWindow& window)
{
    initializeBars();
    for (size_t i = 0; i < maxBars; ++i)
    {
        for (size_t j = 0; j < maxBars - 1; ++j)
        {
            if (!render.handleWindowEvents(window))
            {
                return;
            }
            if (heights[j] > heights[j + 1])
            {
                swapBars(window, j, j + 1, 5);
            }
        }
    }
    render.waitForUserInput(window);
}

void Sorting::selectionSort(sf::RenderWindow &window)
{
    initializeBars();
    for (size_t i = 0; i < maxBars; ++i)
    {
        size_t minIdx = i;
        for (size_t j = i + 1; j < maxBars; ++j) {
            if (!render.handleWindowEvents(window))
            {
                return;
            }
            if (heights[j] < heights[minIdx])
            {
                minIdx = j;

            }
        }
        swapBars(window, i, minIdx, 10);
    }
    render.waitForUserInput(window);
}

void Sorting::insertionSort(sf::RenderWindow &window)
{
    initializeBars();
    for (int i = 1; i < maxBars; ++i)
    {
        float key = heights[i];
        int j = i - 1;
        while (j >= 0 && heights[j] > key)
        {
            swapBars(window, j, j + 1, 10);
            j -= 1;
        }
        heights[j + 1] = key;
    }
    render.waitForUserInput(window);
}

void Sorting::mergeSort(sf::RenderWindow &window)
{

}

void Sorting::heapSort(sf::RenderWindow &window)
{

}

void Sorting::quickSort(sf::RenderWindow &window)
{

}

void Sorting::countingSort(sf::RenderWindow &window)
{

}

void Sorting::radixSort(sf::RenderWindow &window)
{

}

void Sorting::bucketSort(sf::RenderWindow &window)
{

}

void Sorting::bogoSort(sf::RenderWindow& window)
{
    initializeBars();
    
    render.waitForUserInput(window);
}
