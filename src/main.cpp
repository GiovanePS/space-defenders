#include <iostream>
#include <SFML/Graphics.hpp>
#include "player/Player.hpp"
#include "animation/Animation.hpp"
#include <pthread.h>

struct ThreadData {
  int id;
  sf::RenderWindow *window;
};

void *thread_printing(void *data);

int main() {
  // Window settings
  sf::VideoMode screensize = sf::VideoMode(1000, 1000);
  sf::RenderWindow window(screensize, "Space Defenders");
  
  Player player = Player();
  Animation animation(&player.getTexture(), sf::Vector2u(17, 1), 0.3f);

  float deltaTime = 0.0f;
  sf::Clock clock;

  // Thread settings
  pthread_t threads[1];
  ThreadData thread;
  thread.id = 1;
  thread.window = &window;
  pthread_create(&threads[0], NULL, thread_printing, (void*)&thread);

  while (window.isOpen()) {
    clock.restart().asSeconds();
    
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
      window.close();
    }

    animation.Update(0, deltaTime);
    player.SetTexture(animation.uvRect);

    window.clear();
    player.Draw(window);
    window.display();
  }

  pthread_join(threads[0], NULL);

  return 0;
}

void *thread_printing(void *arg) {
  ThreadData *data = (ThreadData*)(arg);
  sf::RenderWindow *window = data->window;

  while (window->isOpen()) {
  // std::cout << "Thread is printing!!" << std::endl;
  }
  std::cout << "Bye!!" << std::endl;

  pthread_exit(NULL);
}