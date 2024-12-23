#include "Enemy.hpp"
#include <iostream>

void Enemy::InitSizeAndPosition(sf::RenderWindow *window) {
    sf::IntRect textureRect = this->sprite.getTextureRect();
    this->size = sf::Vector2f(50.f, 50.f);
    float scaleX = this->size.x / static_cast<float>(textureRect.width);
    float scaleY = this->size.y / static_cast<float>(textureRect.height);

    this->sprite.setScale(scaleX, scaleY);
    this->sprite.setPosition(sf::Vector2f(
        static_cast<float>(
            rand() % static_cast<int>(window->getSize().x - this->size.x)),
        0.0f));
}

sf::Texture Enemy::texture;

void Enemy::InitSprite() {
    if (!Enemy::texture.loadFromFile("assets/enemy-sprites.png")) {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Error on loading enemy asset."
                  << "\n";
    }

    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 400, 400));
}

Enemy::Enemy(sf::RenderWindow *window) : frameIndex(0), frameCounter(0) {
    this->InitSprite();
    this->InitSizeAndPosition(window);
}

Enemy::~Enemy() {}

sf::Vector2f Enemy::GetPosition() { return this->sprite.getPosition(); }

void Enemy::Move() {
    int frameWidth = 400;
    int frameHeight = 400;
    int totalFrames = 21;
    this->frameIndex = this->frameIndex % totalFrames;
    this->sprite.setTextureRect(
        sf::IntRect(this->frameIndex * frameWidth, 0, frameWidth, frameHeight));
	this->frameCounter++;
    if (this->frameCounter % 5 == 0) {
        this->frameIndex++;
    }

    float x = 0.0f;
    float y = 1.0f;
    this->sprite.move(sf::Vector2f(x, y));
}

void Enemy::Render(sf::RenderTarget *target) { target->draw(this->sprite); }
