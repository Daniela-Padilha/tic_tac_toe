/* ******************************************************************************/
/*                                                                              */
/*  File:       symbols.cpp                                    /\_/\            */
/*  Author:     Daniela Padilha                               ( o.o )           */
/*  Created:    2025/07/15 12:45:05                            > ^ <            */
/*  Updated:    2025/07/16 16:30:49                                             */
/*                                                                              */
/* ******************************************************************************/

# include "inc/ticTacToe.hpp"

void drawCircle(sf::RenderWindow& window, int row, int col)
{
    float radius = (CELL_SIZE / 2) - SYMBOL_PADDING;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(5);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOrigin(radius, radius);
    circle.setPosition(GRID_PADDING + col * CELL_SIZE + CELL_SIZE / 2,
                       GRID_PADDING + row * CELL_SIZE + CELL_SIZE / 2);
    window.draw(circle);
}

void drawX(sf::RenderWindow& window, int row, int col)
{
    float length = CELL_SIZE - 2 * SYMBOL_PADDING;
    sf::Vector2f center(
        GRID_PADDING + col * CELL_SIZE + CELL_SIZE / 2,
        GRID_PADDING + row * CELL_SIZE + CELL_SIZE / 2
    );

    sf::RectangleShape line1(sf::Vector2f(length, 5));
    line1.setFillColor(sf::Color::Blue);
    line1.setOrigin(length / 2, 2.5f);
    line1.setRotation(45);
    line1.setPosition(center);

    sf::RectangleShape line2(sf::Vector2f(length, 5));
    line2.setFillColor(sf::Color::Blue);
    line2.setOrigin(length / 2, 2.5f);
    line2.setRotation(-45);
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
