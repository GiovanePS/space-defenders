#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player() {
    shape.setSize(sf::Vector2f(75.0f, 75.0f));
    shape.setPosition(0.0f, 0.0f);
    this->SetTexture("assets/spaceship.png");
}

Player::~Player() {}

sf::Texture Player::getTexture() { return sf::Texture(); }

int Player::SetTexture(const string &path) {
    if (!texture.loadFromFile(path)) {
        cerr << "Error on loading texture from " << path << endl;
        return 1;
    } else {
        shape.setTexture(&texture);
        return 0;
    }
}

void Player::Draw(sf::RenderWindow &window) { window.draw(shape); }

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
