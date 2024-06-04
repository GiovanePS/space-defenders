#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class Player {
  private:
    sf::RectangleShape shape;
    sf::Texture texture;

  public:
    Player();
    ~Player();

    int SetTexture(const string &path);
    void Draw(sf::RenderWindow &window);
    void Movement(sf::RenderWindow &window);
};