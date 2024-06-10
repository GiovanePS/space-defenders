#pragma once

#include <SFML/Graphics.hpp>

class Enemy {
  private:
    sf::RectangleShape shape;

    void InitVariables();
    void InitShape(sf::RenderWindow *window);
  public:
    Enemy(sf::RenderWindow *window);
    ~Enemy();

    sf::Vector2f GetPosition();
    void Move(float x, float y);

    void Update();
    void Render(sf::RenderTarget *target);

};