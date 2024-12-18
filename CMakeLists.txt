cmake_minimum_required(VERSION 3.10)

# Set the project name
project(space-defenders)
set(EXECUTABLE_NAME game)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the executable
add_executable(${EXECUTABLE_NAME} src/main.cpp src/game/Game.cpp src/player/Player.cpp src/enemy/Enemy.cpp)

# Link the SFML libraries
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)

set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)

add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSETS_DIR} $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/assets)
