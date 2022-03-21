//
// Created by Krzysiek on 21/03/2022.
//

#include "Cell.hpp"

Cell::Cell(int width, int height) :
		width(width),
		height(height),
		rectangle(sf::Vector2f(width, height)),
		isHighlighted(false)
{
	rectangle.setOutlineColor(sf::Color::Blue);
	rectangle.setOutlineThickness(2);
}

void Cell::drawOn(int x, int y, sf::RenderWindow *window)
{
	rectangle.setFillColor(isHighlighted ? sf::Color::Red : sf::Color::White);

	rectangle.setPosition(x, y);
	window->draw(rectangle);
}

bool Cell::isOverMe(int myPosX, int myPosY, int mousePosX, int mousePosY)
{
	return mousePosX > myPosX && mousePosX < (myPosX + width); // && mousePosY > myPosY && mousePosY < (myPosY + height);
}

void Cell::highlight()
{
	isHighlighted = true;
}

void Cell::unHighlight()
{
	isHighlighted = false;
}
