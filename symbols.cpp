/* ******************************************************************************/
/*                                                                              */
/*  File:       symbols.cpp                                    /\_/\            */
/*  Author:     Daniela Padilha                               ( o.o )           */
/*  Created:    2025/07/15 12:45:05                            > ^ <            */
/*  Updated:    2025/07/15 15:48:44                                             */
/*                                                                              */
/* ******************************************************************************/

# include "inc/ticTacToe.hpp"

void drawCircle(sf::RenderWindow& window, int row, int col)
{
	float cellSize = 200.0f;
	float padding = 20.0f;
	float radius = (cellSize / 2) - padding;

	sf::CircleShape circle(radius);

	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(5);
	circle.setOutlineColor(sf::Color::Red);

	circle.setOrigin(radius, radius);
	circle.setPosition(col * cellSize + cellSize / 2, row * cellSize + cellSize / 2);
	window.draw(circle);
}

void drawX(sf::RenderWindow& window, int row, int col)
{
	float cellSize = 200.0f;
	float padding = 20.0f;
	float lenght = cellSize - 2* padding;
	float thickness = 5.0f;

	sf::Vector2f center(
        col * cellSize + cellSize / 2,
        row * cellSize + cellSize / 2
    );

	sf::RectangleShape line1(sf::Vector2f(lenght, thickness));
	sf::RectangleShape line2(sf::Vector2f(lenght, thickness));

	line1.setFillColor(sf::Color::Blue);
	line2.setFillColor(sf::Color::Blue);

	line1.setOrigin(lenght / 2, thickness / 2);
	line2.setOrigin(lenght / 2, thickness / 2);

	line1.setRotation(45);
	line2.setRotation(-45);

	line1.setPosition(center);
	line2.setPosition(center);

	window.draw(line1);
	window.draw(line2);
}

void drawBoard(sf::RenderWindow& window, char board[3][3])
{
    for (int row = 0; row < 3; ++row) 
	{
        for (int col = 0; col < 3; ++col) 
		{
            if (board[row][col] == 'X')
                drawX(window, row, col);
            else if (board[row][col] == 'O')
                drawCircle(window, row, col);
        }
    }
}
