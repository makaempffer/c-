#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

std::vector<std::vector<sf::RectangleShape>> makeArray(int rows, int cols, float size)
{
	std::vector<std::vector<sf::RectangleShape>> array;
	for (int x = 0; x < rows; x++)
		
	{
		std::vector<sf::RectangleShape> row;
		row.push_back(sf::RectangleShape(sf::Vector2f(size, size)));
		for (int y = 0; y < cols; y++)
		{
			row[x].setPosition(sf::Vector2f(float(x) * size, float(y) * size));
			row[x].setFillColor(sf::Color::Green);

			printf("x = %i, y = %i\n",x, y);
		}
		array.push_back(row);
		
	}

	return array;
}
int main()
{
	//setup
	int width = 600;
	int height = 600;
	float size = 10.0f;
	int rows = width / int(size);
	int cols = height /int(size);
	printf("sizes = %i, %i, %f", rows, cols, size);
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML APP", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape square(sf::Vector2f(10, 10));
	std::vector<std::vector<sf::RectangleShape>> array = makeArray(rows, cols, size);
	printf("success\n");
	



	while (window.isOpen())
	{
		sf::Event evnt;

		while (window.pollEvent(evnt))
		{

			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		 /*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			square.move(0.1f, 0.0f);
		} 
		 */
		window.clear();		
		for (int x = 0; x < array.size(); x++)
		{
			for (int y = 0; y < array[x].size(); y++)
			{
				window.draw(array[x][y]);
			}
		}
		window.display();
	}
	return 0;
}