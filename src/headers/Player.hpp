#pragma once
#include <SFML/Graphics.hpp>

class Player {
  private:
    sf::RectangleShape shape;

  public:
    Player(sf::Texture *texture) {
      shape.setSize(sf::Vector2f(100.0f, 100.0f));
      shape.setPosition(900.0f, 960.0f);
      shape.setTexture(texture);
    };

    ~Player() {};

  void Draw(sf::RenderWindow &window) {
    window.draw(shape);
  }

  void Movement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      shape.move(-0.3f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      shape.move(0.3f, 0.0f);
    }
  }
};