#include "Game.hpp"

void Game::InitWindow() {
  this->videoMode.width = 1000;
  this->videoMode.height = 600;

  this->window = new sf::RenderWindow(this->videoMode, "Space Defenders", sf::Style::Titlebar | sf::Style::Close);

  this->window->setFramerateLimit(80);
}

Game::Game()
{
  this->InitWindow();
}

Game::~Game() {
  delete this->window;
}

bool Game::IsRunning() {
  return this->window->isOpen();
}

void Game::PollEvents() {
  while (this->window->pollEvent(this->event)) {
    switch (this->event.type)
    {
    case sf::Event::Closed:
      this->window->close();
      break;
    
    case sf::Event::KeyPressed:
      if (event.key.code == sf::Keyboard::Escape) {
        this->window->close();
      }
      break;
    }
  }
}

void Game::Update()
{
  this->PollEvents();
}

void Game::Render() {}
