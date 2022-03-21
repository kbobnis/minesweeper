#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.hpp"

using namespace sf;

//https://www.youtube.com/watch?v=4oh-tmxtIrA&ab_channel=IntMain
//https://dev.to/giovannicodes/sfml-2-5-1-setup-on-macos-with-clion-505m

int main()
{
	const int screenWidth = 640;
	const int screenHeight = 640;
	const int boardWidth = 480;
	const int boardHeight = 480;
	const int boardX = 10;
	const int boardY = 10;
	const int cellsCountVertical = 2;
	const int cellsCountHorizontal = 2;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Minesweeper");
	window.setFramerateLimit(60);

	Board board(boardX, boardY, boardWidth, boardHeight, cellsCountHorizontal, cellsCountVertical);

	sf::Font font;
	font.loadFromFile("../fonts/Forwa_font.TTF");

	sf::CircleShape shape(50);
	shape.setFillColor(sf::Color(100, 250, 50));

	while (window.isOpen())
	{
		sf::Event e;

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
			// keyboard interrupt
			if (e.type == Event::KeyPressed)
			{
				switch (e.key.code)
				{
					case Keyboard::Escape:
						window.close();
						break;
				}
			}
		}

		window.clear(Color::Black);

		Vector2i pos = sf::Mouse::getPosition(window);

		shape.setPosition(pos.x - shape.getRadius(), pos.y - shape.getRadius());
		window.draw(shape);

		board.highlightCell(pos);
		board.drawOn(&window);

		window.display();
	}
}