#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"
#include "../Header/EventService.h"

PlayerService::PlayerService()
{
	game_window = nullptr;
}

PlayerService::~PlayerService() = default;

//init
void PlayerService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

//take our players input in update, then set the position.
//order is important here
void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPosition());
}

void PlayerService::render()
{
	game_window->draw(player_sprite);
}

void PlayerService::processPlayerInput()
{
	/*
	// Handle keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		move(-1.0f * getMoveSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		move(1.0f * getMoveSpeed());
	}
	*/
	EventService* event_service = ServiceLocator::getInstance()->getEventService(); //get the event service object created in service locator

	if (event_service->isKeyboardEvent()) //check if a key has been pressed
	{
		if (event_service->pressedLeftKey())
		{
			move(-1.0f * getMoveSpeed());
		}

		if (event_service->pressedRightKey())
		{
			move(1.0f * getMoveSpeed());
		}
	}
}

void PlayerService::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
	}
}

void PlayerService::move(float offsetX) {
	position.x += offsetX;
}

//helper functions
sf::Vector2f PlayerService::getPosition() { return position; }
int PlayerService::getMoveSpeed() { return movement_speed; }
