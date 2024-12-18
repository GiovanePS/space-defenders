#include "Animation.hpp"

Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount,
                     float switchTime) {
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
}

void Animation::Update(int frame, float deltaTime) {
    currentImage.x = frame;
    totalTime += deltaTime;

    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x > imageCount.x) {
            currentImage.x = 0;
        }
    }

    uvRect.left = currentImage.x * uvRect.width;
}
