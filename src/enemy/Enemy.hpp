#pragma once

#include <SFML/Graphics.hpp>

class Enemy {
  private:
    sf::Sprite sprite;
    static sf::Texture texture;
    sf::Vector2f size;
    int frameIndex;
    int frameCounter;

    void InitSizeAndPosition(sf::RenderWindow *window);
    void InitSprite();

  public:
    Enemy(sf::RenderWindow *window);
    ~Enemy();

    sf::Vector2f GetPosition();
    void Move();

    void Update();
    void Render(sf::RenderTarget *target);
};
