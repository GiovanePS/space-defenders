#pragma once

#include <SFML/Graphics.hpp>

class Game {
  private:
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;

    void InitWindow();
  public:
    Game();
    ~Game();

    // Getters

    bool IsRunning();

    // Methods

    void PollEvents();

    void Update();

    void Render();
};