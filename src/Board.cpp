//
// Created by Krzysiek on 18/03/2022.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "Board.hpp"

Board::Board(const int posX, const int posY, const int width, const int height, const int cellCountX, const int cellCountY) :
		posX(posX),
		posY(posY)
{
	cells.resize(cellCountX);
	for (int i = 0; i < cellCountX; ++i)
	{
		for (int j = 0; j < cellCountY; ++j)
		{
			cells[i].push_back(Cell(width / cellCountX, height / cellCountY));
		}
	}
}

void Board::drawOn(sf::RenderWindow *window)
{
	for (int x = 0; x < cells.size(); ++x)
	{
		for (int y = 0; y < cells[x].size(); ++y)
		{
			Cell cell = cells[x][y];
			cell.drawOn(posX + x * cell.width, posY + y * cell.height, window);
		}
	}
}

void Board::highlightCell(sf::Vector2i vector2)
{
	for (int x = 0; x < cells.size(); ++x)
	{
		for (int y = 0; y < cells[x].size(); ++y)
		{
			Cell cell = cells[x][y];
			int currentCellX = posX + x * cell.width;
			int currentCellY = posY + y * cell.height;
			if (cell.isOverMe(currentCellX, currentCellY, vector2.x, vector2.y))
			{
				cell.highlight();
			} else
			{
				cell.unHighlight();
			}
		}
	}
}
