#include "game/Game.hpp"
#include <SFML/Graphics.hpp>

int main() {
    std::srand(static_cast<unsigned>(time(NULL)));

    Game game;

    while (game.IsRunning()) {
        game.Update();

        game.Render();
    }

    return 0;
}
