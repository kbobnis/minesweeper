//
// Created by Krzysiek on 18/03/2022.
//

#ifndef MINESWEEPER_BOARD_HPP
#define MINESWEEPER_BOARD_HPP


#include <SFML/Graphics/RenderWindow.hpp>
#include "Cell.hpp"

using namespace sf;
using namespace std;

class Board
{
	const int posX;
	const int posY;
	vector<vector<Cell>> cells;

public:
	Board(const int posX, const int posY, const int width, const int height, const int cellCountX, const int cellCountY);

	void drawOn(sf::RenderWindow *window);

	void highlightCell(sf::Vector2i vector2);
};


#endif //MINESWEEPER_BOARD_HPP
