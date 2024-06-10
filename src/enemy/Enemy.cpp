#include "Enemy.hpp"

void Enemy::InitVariables() {}

void Enemy::InitShape(sf::RenderWindow *window) {
  this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
  this->shape.setPosition(sf::Vector2f(
    static_cast<float>(rand() % static_cast<int>(window->getSize().x - this->shape.getSize().x)),
    0.0f
  ));
}

void Enemy::InitTexture() {
  if (!this->texture.loadFromFile("assets/enemy.gif")) {
    std::cout << "Error on loading enemy asset." << "\n";
  }
}

Enemy::Enemy(sf::RenderWindow *window){
  this->InitVariables();
  this->InitShape(window);
  this->InitTexture();
}

Enemy::~Enemy() {}

sf::Vector2f Enemy::GetPosition() {
  return this->shape.getPosition();
}

void Enemy::Move() {
  float x = 0.0f;
  float y = 1.0f;
  this->shape.move(sf::Vector2f(x, y));
}

void Enemy::Render(sf::RenderTarget *target) {
  this->shape.setTexture(&this->texture);
  target->draw(this->shape);
}
