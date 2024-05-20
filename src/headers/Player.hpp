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

  void Movement(sf::RenderWindow &window) {
    sf::Vector2f movement(0.0f, 0.0f);
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      movement.x -= 0.3f;
      // shape.move(-0.3f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      movement.x += 0.3f;
      // shape.move(0.3f, 0.0f);
    }

    // Collision with window wall
    sf::Vector2f newPosition = shape.getPosition() + movement;
    sf::Vector2u windowSize = window.getSize();

    if (newPosition.x < 0) {
      newPosition.x = 0.0f;
    }
    if (newPosition.x + shape.getSize().x > windowSize.x) {
      newPosition.x = windowSize.x - shape.getSize().x;
    }

    shape.setPosition(newPosition);
  }
};