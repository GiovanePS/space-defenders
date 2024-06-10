#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Enemy {
  private:
    sf::RectangleShape shape;
    sf::Texture texture;

    void InitVariables();
    void InitShape(sf::RenderWindow *window);
    void InitTexture();
  public:
    Enemy(sf::RenderWindow *window);
    ~Enemy();

    sf::Vector2f GetPosition();
    void Move();

    void Update();
    void Render(sf::RenderTarget *target);

};