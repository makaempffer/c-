#include <vector>
#include <iostream>
#include "Game.h"

int main()
{
	//init random
	std::srand(static_cast<unsigned>(time(NULL)));


	//init game engine
	Game game;


	while (game.running())
	{
		//update
		game.update();

		//render
		game.render();
	}

	return 0;
}