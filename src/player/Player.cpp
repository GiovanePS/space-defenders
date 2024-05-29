#include <iostream>
#include "Player.hpp"

using namespace std;

Player::Player() {
  shape.setSize(sf::Vector2f(100.0f, 100.0f));
  shape.setPosition(900.0f, 960.0f);
  this->SetTexture(string("./assets/spaceship.png"));
}

Player::~Player() {}

int Player::SetTexture(string path) {
  sf::Texture texture;
  if (!texture.loadFromFile(path)) {
    exit(1);
  } else {
    shape.setTexture(&texture);
    return 0;
  }
}

void Player::Draw(sf::RenderWindow &window) {
  window.draw(shape);
}

void Player::Movement(sf::RenderWindow &window) {
  sf::Vector2f movement(0.0f, 0.0f);
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    movement.x -= 0.3f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    movement.x += 0.3f;
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