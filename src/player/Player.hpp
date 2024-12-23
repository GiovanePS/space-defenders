#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class Player {
  private:
    sf::Sprite sprite;
    sf::Texture texture;
	sf::Vector2f size;
    int frameIndex;
    int frameCounter;

  public:
    Player(sf::RenderWindow *window);
    ~Player();

    sf::Texture getTexture();
    void InitSprite(sf::RenderWindow *window);
    void Render(sf::RenderTarget *target);
    void Movement(sf::RenderWindow *window);
};
