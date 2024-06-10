#include "Enemy.hpp"

void Enemy::InitVariables() {}

void Enemy::InitShape(sf::RenderWindow *window)
{
  this->shape.setFillColor(sf::Color::Green);
  this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
  this->shape.setPosition(sf::Vector2f(
    static_cast<float>(rand() % static_cast<int>(window->getSize().x - this->shape.getSize().x)),
    0.0f
  ));
}

Enemy::Enemy(sf::RenderWindow *window){
  this->InitVariables();
  this->InitShape(window);
}

Enemy::~Enemy() {}

sf::Vector2f Enemy::GetPosition() {
  return this->shape.getPosition();
}

void Enemy::Move(float x, float y)
{
  this->shape.move(sf::Vector2f(x, y));
}

void Enemy::Render(sf::RenderTarget *target) {
  target->draw(this->shape);
}
