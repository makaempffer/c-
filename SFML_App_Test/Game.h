#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
//engine class

class Game
{

private:
	//variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//mouse positions
	sf::Vector2i mousePosWindow;

	//game logics
	int points;
	//--enemies--
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	//--resources--
	int startingResources;
	int resourceLeft;
	int maxResources;
	//--player--
	int playerHp;
	int playerRange;
	float playerSpeed;




	//gameObjects
	//--enemies--
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	//--resources--
	std::vector<sf::RectangleShape> resources;
	sf::RectangleShape resource;
	//player
	sf::RectangleShape player;


	//private functions
	void initVariables();
	void initWindow();
	void initPlayer();
	void initEnemies();
	void initResources();

public:
	//constructos / destructos
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//functions
	//--resources--
	void spawnResource();
	void updateResources();
	void renderResources();
	//--enemies--
	void spawnEnemy();
	void updateEnemies();
	void renderEnemies();
	//--player--
	void updatePlayer();
	void renderPlayer();
	//--window--
	void pollEvents();
	void updateMousePositions();
	void update();
	void render();
};

