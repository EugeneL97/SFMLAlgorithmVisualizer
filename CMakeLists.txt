cmake_minimum_required(VERSION 3.30)
project(SFMLAlgorithmVisualizer)

set(CMAKE_CXX_STANDARD 17)

add_executable(SFMLAlgorithmVisualizer main.cpp
        Sorting.cpp
        Render.cpp
        Menu.cpp
        Menu.h)

target_link_libraries(SFMLAlgorithmVisualizer sfml-system sfml-window sfml-graphics)
