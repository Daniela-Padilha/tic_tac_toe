/* ******************************************************************************/
/*                                                                              */
/*  File:       window.cpp                                     /\_/\            */
/*  Author:     Daniela Padilha                               ( o.o )           */
/*  Created:    2025/07/15 12:27:02                            > ^ <            */
/*  Updated:    2025/07/15 12:44:19                                             */
/*                                                                              */
/* ******************************************************************************/

#include "inc/ticTacToe.hpp"

sf::RenderWindow* windowCreate()
{
	return (new sf::RenderWindow (sf::VideoMode(600, 600), "Tictactoe"));
}

void drawGrid(sf::RenderWindow& window)
{
	sf::RectangleShape line(sf::Vector2f(600, 5));
	line.setFillColor(sf::Color::White);

	// Horizontal lines
	line.setPosition(0, 200);
	window.draw(line);
	line.setPosition(0, 400);
	window.draw(line);

	// Vertical lines
	line.setSize(sf::Vector2f(5, 600));
	line.setPosition(200, 0);
	window.draw(line);
	line.setPosition(400, 0);
	window.draw(line);
}
