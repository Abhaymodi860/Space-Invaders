#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../Header/Gameplay/GameService.h"

using namespace Main;

int main()
{
    //GameService* gameservive;
    GameService* game_service = new GameService();

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

    return 0;
}