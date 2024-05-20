#include <SFML/Graphics.hpp>
#include "headers/Player.hpp"

int main() {
  // Window configurations
  sf::VideoMode screensize = sf::VideoMode::getDesktopMode();
  sf::RenderWindow window(screensize, "Space Defenders");

  sf::Texture playerTexture;
  if (!playerTexture.loadFromFile("assets/spaceship.png")) {
    return -1;
  }
  Player player(&playerTexture);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
      window.close();
    }

    player.Movement(); // Player movements

    window.clear();
    player.Draw(window);
    window.display();
  }

  return 0;
}