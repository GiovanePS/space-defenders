#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class Player {
  private:
    sf::RectangleShape shape;

  public:
    Player();
    ~Player();

    int SetTexture(string path);
    void Draw(sf::RenderWindow &window);
    void Movement(sf::RenderWindow &window);
};