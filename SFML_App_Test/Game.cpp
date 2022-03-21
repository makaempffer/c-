#include "Game.h"
#include <ctime>
//player can add pipes to the world to transport resources to places
//player can harvest resources by hand
//player can store resources in storage
//resources are infinite but time restricted, player must setup energy usage
//pipes waste energy
//can see resources travelling through pipes 


//private functions
void Game::initVariables()
{
	this->window = nullptr;

	//game logic
	//--enemies--
	this->points = 0;
	this->enemySpawnTimerMax = 1000.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
	//--resources--
	this->resourceLeft = 10;
	this->startingResources = 5;
	this->maxResources = 5;
	//--Player--
	this->playerHp = 100;
	this->playerRange = 100;
	this->playerSpeed = 10.f;
	

}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "SFML APP", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initPlayer()
{
	this->player.setPosition(0.f, 0.f);
	this->player.setSize(sf::Vector2f(5.f, 5.f));
	this->player.setFillColor(sf::Color::White);

}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(50.f, 50.f));
	this->enemy.setFillColor(sf::Color::Red);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}




//constructors / Destructos
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initEnemies();
	this->initResources();
}

Game::~Game()
{
	delete this->window;
}

//Accesors:
const bool Game::running() const
{
	return this->window->isOpen();
}






//Functions
//--PLAYER FUNCTIONS--
void Game::updatePlayer()
{

}
void Game::renderPlayer()
{
	this->window->draw(this->player);
}
//RESOURCES FUNCTIONS---------------
void Game::initResources()
{
	this->resource.setSize(sf::Vector2f(10.f, 10.f));
	this->resource.setFillColor(sf::Color::Red);

}

void Game::spawnResource()
{
	//set a random x, y position
	this->resource.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->resource.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->resource.getSize().y))
	);
	this->resources.push_back(this->resource);
}

void Game::updateResources()
{
	if (this->resources.size() < this->maxResources)
	{
		if (this->enemies.size() < this->startingResources)
			this->spawnResource();
	}
}

void Game::renderResources()
{
	for (auto &r : this->resources)
	{
		this->window->draw(r);
	}
}





//ENEMIES--------------
void Game::spawnEnemy()
{
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);	

	this->enemy.setFillColor(sf::Color::Green);
	//spawn enemy
	this->enemies.push_back(this->enemy);
}	

void Game::updateEnemies()
{

	//updating timer for enemy spawn
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//spawn enemy / reset timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;

		}
		else
		{
			this->enemySpawnTimer += 1.f;
		}
	}
	//move enemies
	for (auto &e : this->enemies)
	{
		e.move(0.f, 1.f);
	}
}

void Game::renderEnemies()
{
	//rendering enemies
	for (auto &e : this->enemies)
	{
		this->window->draw(e);
	}
}

//------------------------------

//WINDOW STUFF----------------
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			//player movement
			if (this->ev.key.code == sf::Keyboard::D)
				this->player.move(sf::Vector2f(this->playerSpeed, 0.f));
			if (this->ev.key.code == sf::Keyboard::S)
				this->player.move(sf::Vector2f(0.f, this->playerSpeed));
			if (this->ev.key.code == sf::Keyboard::A)
				this->player.move(sf::Vector2f(-this->playerSpeed, 0.f));
			if (this->ev.key.code == sf::Keyboard::W)
				this->player.move(sf::Vector2f(0.f, -this->playerSpeed));

			break;
		}
	}
}

void Game::updateMousePositions()
{
	//vector2i
	//Takes a reference a the window not a pointer so we dereference with *...
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}


void Game::update()
{

	this->pollEvents();

	this->updateMousePositions();

	this->updateResources();

	this->updateEnemies();
}	

void Game::render()
{
	
	/*
		@return void
		Renders game objects(clears frame, renders objects, displays in window...)
	*/
	this->window->clear();

	//draw game objects
	this->renderEnemies();

	this->renderResources();

	this->renderPlayer();

	this->window->display();
}
//--------------------------