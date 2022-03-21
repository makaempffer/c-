#include "Resource.h"
#include "Game.h"
#include <ctime>
void Resource::initVariables()
{
	this->amountLeft = 100;
	this->size = sf::Vector2f(10.f, 10.f);

}

void Resource::initResources()
{
	this->res.setPosition(
		static_cast<float>(rand() % static_cast<int>(Game::getWindowSize().x)),
		static_cast<float>(rand() % static_cast<int>(Game::getWindowSize().y))
	);
}


void Resource::spawnResource()
{
}

void Resource::updateResources()
{
}

void Resource::renderResources()
{
}
