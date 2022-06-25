#include "Game.hpp"

int main()
{
    Game game;
    while (!game.GetWindow()->IsDone()) {
        game.HandleInput();
        game.Update();
        game.Render();
        // sf::sleep(sf::seconds(0.2));
        game.RestartClock();
    }

    return 0;
}