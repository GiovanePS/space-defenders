#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "../enemy/Enemy.hpp"

class Game {
  private:
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

    // Game logic

    int health;
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemiesAtSameTime;
    int maxEnemies;
    bool endGame;

    // Game objects

    std::vector<Enemy> enemies;

    void InitVariables();
    void InitWindow();
    void InitBackground();
  public:
    Game();
    ~Game();

    // Getters

    bool IsRunning();
    bool GetEndGame();

    // Methods

    void PollEvents();

    void SpawnEnemy(sf::RenderWindow *window);

    void UpdateEnemies();
    void Update();

    void RenderBackground(sf::RenderWindow *window);
    void RenderEnemies(sf::RenderWindow *window);
    void Render();
};