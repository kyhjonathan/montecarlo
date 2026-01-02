cmake_minimum_required(VERSION 3.10)

# Name of your project and say it's a C++ (CXX) project
project(MonteCarloSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create an executable named "montecarlo" from these source files
# For now, just src/main.cpp. Add more .cpp files to this list as you create them.
add_executable(montecarlo
    src/main.cpp
)
