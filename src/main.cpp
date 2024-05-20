#include <SFML/Graphics.hpp>

int main() {
  sf::VideoMode screensize = sf::VideoMode::getDesktopMode();
  sf::RenderWindow window(screensize, "SFML works!");
  sf::CircleShape player(100.f);
  player.setFillColor(sf::Color::Blue);
  player.setPosition(250, 400);

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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      player.move(-0.3f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      player.move(0.3f, 0.0f);
    }

    window.clear();
    window.draw(player);
    window.display();
  }

  return 0;
}