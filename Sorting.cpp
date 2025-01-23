#include <cstdlib>
#include <SFML/System.hpp>

#include "Sorting.h"

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

void Sorting::bubbleSort(sf::RenderWindow& window)
{
    initializeBars();
    for (int i = 0; i < maxBars; ++i)
    {
        for (int j = 0; j < maxBars - 1; ++j)
        {
            if (!render.handleWindowEvents(window))
            {
                return;
            }
            if (heights[j] > heights[j + 1])
            {
                std::swap(heights[j], heights[j + 1]);

                bars[j].setSize(sf::Vector2f{barWidth, (heights[j])});
                bars[j].setPosition(j * barWidth, screenHeight - heights[j]);

                // Track bar being swapped
                bars[j + 1].setFillColor(sf::Color::Red);
                bars[j + 1].setSize(sf::Vector2f{barWidth, heights[j + 1]});
                bars[j + 1].setPosition((j + 1) * barWidth, screenHeight - heights[j + 1]);

                render.renderBars(window, bars);

                // Reset to white as to not leave trace red bars behind
                bars[j + 1].setFillColor(sf::Color::White);

                sleep(sf::milliseconds(50));
            }
        }
    }
    render.waitForUserInput(window);
}

void Sorting::selectionSort(sf::RenderWindow &window)
{

}

void Sorting::insertionSort(sf::RenderWindow &window)
{

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
