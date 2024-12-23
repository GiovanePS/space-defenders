#pragma once

#include "../enemy/Enemy.hpp"
#include "../player/Player.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

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

	Player *player;
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

	void InitPlayer(sf::RenderWindow *window);
    void SpawnEnemy(sf::RenderWindow *window);

	void UpdatePlayer();
    void UpdateEnemies();
    void Update();

    void RenderBackground(sf::RenderWindow *window);
	void RenderPlayer(sf::RenderWindow *window);
    void RenderEnemies(sf::RenderWindow *window);
    void Render();
};
