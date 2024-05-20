cmake_minimum_required(VERSION 3.10)

# Set the project name
project(space-defenders)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the executable
add_executable(game src/main.cpp)

# Link the SFML libraries
target_link_libraries(game sfml-graphics sfml-window sfml-system)