# SFML Algorithm Visualizer

The goal is to create an interactive and educational tool that allows users to explore different algorithms visually. I’m starting with sorting algorithms and eventually plan to add pathfinding algorithms. 

## Why This Project?

I've always been a visual learner, and when I first studied Data Structures and Algorithms, I found it frustrating not being able to *see* what was happening. This tool is my way of making sorting and pathfinding algorithms more digestible through visualization.

By observing best-case, average-case, and worst-case scenarios in action, the goal is to solidify the core concepts and highlight why different algorithms are suited for different tasks. Understanding these trade-offs visually can reinforce the idea that no single algorithm is universally the best. Each is a tool optimized for a specific job.

## Why SFML?

I chose SFML because of its straightforward implementation and learning curve. It lets me focus on implementing algorithms without being overly concerned by the extra boilerplate code of lower level graphics engines, while reinforcing my C++ knowledge.

## Current Features

- **Sorting Visualization:** Watch how various sorting algorithms operate step by step.
- **Interactive Controls:** Play, pause, and eventually go back to the menu to pick another algorithm.
- **Clean and Readable Code:** I prioritize readability to make it easier to understand and maintain.

## What’s Next?

I’m planning to:
- Add the commonly used sorting algorithms as well as the ones we learn in school.
- Integrate pathfinding algorithms to expand the visualizer’s scope.
- Experiment with new UI/UX ideas to allow for more flexibility and practicality from the user's perspective.
- Translating this into a web app (Three.js?) to make it accessible without requiring SFML installation.
  
## Contributing
### Clone the Repo

```bash
git clone https://github.com/EugeneL97/SFMLAlgorithmVisualizer
cd SFMLAlgorithmVisualizer
```
### Build and Run the Project

```bash
mkdir build && cd build
cmake ..
make
./SFMLAlgorithmVisualizer
```
### Submit a Pull Request

If you'd like to contribute, fork the repo, and open a pull request to the 'main' branch!
