/* ******************************************************************************/
/*                                                                              */
/*  File:       window.cpp                                     /\_/\            */
/*  Author:     Daniela Padilha                               ( o.o )           */
/*  Created:    2025/07/15 12:27:02                            > ^ <            */
/*  Updated:    2025/07/16 16:23:07                                             */
/*                                                                              */
/* ******************************************************************************/

#include "inc/ticTacToe.hpp"

sf::RenderWindow* windowCreate()
{
	return (new sf::RenderWindow (sf::VideoMode(745, 800), "Tic Tac Toe"));
}

void drawGrid(sf::RenderWindow& window)
{
    sf::RectangleShape line;

    // Horizontal lines
    line.setSize(sf::Vector2f(3 * CELL_SIZE, GRID_THICKNESS));
    line.setFillColor(sf::Color::White);
    line.setPosition(GRID_PADDING, GRID_PADDING + CELL_SIZE);
    window.draw(line);
    line.setPosition(GRID_PADDING, GRID_PADDING + 2 * CELL_SIZE);
    window.draw(line);

    // Vertical lines
    line.setSize(sf::Vector2f(GRID_THICKNESS, 3 * CELL_SIZE));
    line.setPosition(GRID_PADDING + CELL_SIZE, GRID_PADDING);
    window.draw(line);
    line.setPosition(GRID_PADDING + 2 * CELL_SIZE, GRID_PADDING);
    window.draw(line);
}

void resetBoard(char board[3][3])
{
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            board[row][col] = ' ';
}

void drawRestartButton(sf::RenderWindow& window)
{
    sf::RectangleShape button(sf::Vector2f(150, 40));
    button.setPosition(580, 750);
    button.setFillColor(sf::Color(100, 100, 255));
    button.setOutlineColor(sf::Color::White);
    button.setOutlineThickness(2);
    window.draw(button);

    sf::Font font;
    if (!font.loadFromFile("assets/ShareTechMono-Regular.ttf"))
	{
		std::cerr << "Failed to load font!" << std::endl;
		return ;
	}
    sf::Text text("Restart", font, 17);
    text.setFillColor(sf::Color::White);
    text.setPosition(625, 760);
    window.draw(text);
}

