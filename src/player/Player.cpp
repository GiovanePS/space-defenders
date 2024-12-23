#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player(sf::RenderWindow *window) { this->InitSprite(window); }

sf::Texture Player::getTexture() { return sf::Texture(); }

void Player::InitSprite(sf::RenderWindow *window) {
    if (!this->texture.loadFromFile("assets/antiaircraft-transparent.png")) {
        cerr << "Error on loading texture from " << "\n";
    }
    this->sprite.setTexture(this->texture);
    sf::IntRect textureRect = sf::IntRect(0, 0, 56, 51);
    this->sprite.setTextureRect(textureRect);
    this->size = sf::Vector2f(100.0f, 100.0f);
    float scaleX = this->size.x / static_cast<float>(textureRect.width);
    float scaleY = this->size.y / static_cast<float>(textureRect.height);
    this->sprite.setScale(scaleX, scaleY);

    this->sprite.setPosition(static_cast<float>(window->getSize().x) / 2 -
                                 this->size.x,
                             window->getSize().y - this->size.y);
}

void Player::Render(sf::RenderTarget *window) { window->draw(this->sprite); }

void Player::Movement(sf::RenderWindow *window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        this->frameCounter++;
        if (this->frameCounter % 5 == 0) {
            this->frameIndex++;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        this->frameCounter++;
        if (this->frameCounter % 5 == 0) {
            this->frameIndex--;
        }
    }
    if (this->frameIndex < 0) {
        this->frameIndex = 0;
    }

    int frameWidth = 56;
    int frameHeight = 51;
    int totalFrames = 17;
    this->frameIndex = this->frameIndex % totalFrames;
    sf::IntRect textureRect =
        sf::IntRect(this->frameIndex * frameWidth, 0, frameWidth, frameHeight);
    this->sprite.setTextureRect(textureRect);
}
