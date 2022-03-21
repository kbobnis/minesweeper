//
// Created by Krzysiek on 21/03/2022.
//

#ifndef MINESWEEPER_CELL_HPP
#define MINESWEEPER_CELL_HPP


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Cell
{
	bool isHighlighted = false;
	sf::RectangleShape rectangle;

public:
	int width;
	int height;

	Cell(int width, int height);

	void drawOn(int x, int y, sf::RenderWindow *window);

	bool isOverMe(int myPosX, int myPosY, int mousePosX, int mousePosY);

	void highlight();

	void unHighlight();
};


#endif //MINESWEEPER_CELL_HPP
