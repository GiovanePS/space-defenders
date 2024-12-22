#include "Game.hpp"
#include <iostream>

void Game::InitVariables() {
    this->window = nullptr;

    this->endGame = false;
    this->maxEnemies = 15;
    this->maxEnemiesAtSameTime = 5;
    this->enemySpawnTimerMax = 10.0f;
    this->points = 0;
    this->health = maxEnemies / 2 + 1;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
}

void Game::InitWindow() {
    this->videoMode.width = 900;
    this->videoMode.height = 800;

    this->window = new sf::RenderWindow(this->videoMode, "Space Defenders",
                                        sf::Style::Titlebar | sf::Style::Close);
    this->InitBackground();

    this->window->setFramerateLimit(80);
}

void Game::InitBackground() {
    if (!this->backgroundTexture.loadFromFile("assets/background.jpg")) {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Error on loading enemy asset."
                  << "\n";
    }
    this->backgroundSprite.setTexture(this->backgroundTexture);

    // Resize the image to fit window
    float x = this->window->getSize().x /
              this->backgroundSprite.getGlobalBounds().width;
    float y = this->window->getSize().y /
              this->backgroundSprite.getGlobalBounds().height;
    this->backgroundSprite.setScale(x, y);
}

Game::Game() {
    this->InitVariables();
    this->InitWindow();
}

Game::~Game() { delete this->window; }

bool Game::IsRunning() { return this->window->isOpen(); }

bool Game::GetEndGame() { return this->endGame; }

void Game::PollEvents() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
            break;
        default:
            break;
        }
    }
}

void Game::SpawnEnemy(sf::RenderWindow *window) {
    this->enemies.push_back(Enemy(window));
}

void Game::UpdateEnemies() {
    if (this->enemies.size() < this->maxEnemiesAtSameTime) {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            this->SpawnEnemy(this->window);
            this->enemySpawnTimer = 0.0f;
        } else {
            this->enemySpawnTimer += 0.1f;
        }
    }

    for (int i = 0; i < this->enemies.size(); i++) {
        this->enemies[i].Move();

        // Deleting enemy if he passed on the screen limit
        if (this->enemies[i].GetPosition().y > this->window->getSize().y) {
            this->enemies.erase(this->enemies.begin() + i);

            this->health -= 1;
        }
    }
}

void Game::Update() {
    this->PollEvents();

    if (!this->endGame) {
        this->UpdateEnemies();
    }

    if (this->health <= 0) {
        this->endGame = true;
    }
}

void Game::RenderBackground(sf::RenderWindow *window) {
    window->draw(this->backgroundSprite);
}

void Game::RenderEnemies(sf::RenderWindow *window) {
    for (auto &e : this->enemies) {
        e.Render(window);
    }
}

void Game::Render() {
    this->window->clear();

    this->RenderBackground(this->window);
    this->RenderEnemies(this->window);

    this->window->display();
}
