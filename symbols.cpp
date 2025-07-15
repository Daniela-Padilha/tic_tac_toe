/* ******************************************************************************/
/*                                                                              */
/*  File:       symbols.cpp                                    /\_/\            */
/*  Author:     Daniela Padilha                               ( o.o )           */
/*  Created:    2025/07/15 12:45:05                            > ^ <            */
/*  Updated:    2025/07/15 15:06:02                                             */
/*                                                                              */
/* ******************************************************************************/

# include "inc/ticTacToe.hpp"

void drawCircle(sf::RenderWindow& window, int row, int col)
{
	sf::CircleShape circle(80);

	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(5);
	circle.setOutlineColor(sf::Color::Red);

	circle.setPosition(col * 200 + 5, row * 200 + 5);
	window.draw(circle);
}

void drawX(sf::RenderWindow& window, int row, int col)
{
	sf::RectangleShape line1(sf::Vector2f(180, 5));
	sf::RectangleShape line2(sf::Vector2f(180, 5));

	line1.setFillColor(sf::Color::Blue);
	line2.setFillColor(sf::Color::Blue);

	line1.setOrigin(0, 2.5f);
	line2.setOrigin(0, 2.5f);

	line1.setRotation(45);
	line2.setRotation(-45);

	float x = col * 200 + 5;
	float y = row * 200 + 10;

	line1.setPosition(x, y);
	line2.setPosition(x, y);

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
