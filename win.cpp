/* ******************************************************************************/
/*                                                                              */
/*  File:       win.cpp                                        /\_/\            */
/*  Author:     Daniela Padilha                               ( o.o )           */
/*  Created:    2025/07/15 16:01:27                            > ^ <            */
/*  Updated:    2025/07/16 16:32:00                                             */
/*                                                                              */
/* ******************************************************************************/

#include "inc/ticTacToe.hpp"

char checkWinner(char board[3][3], std::vector<std::pair<int, int>>& winCells)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        // Row
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
        {
            winCells = {{i, 0}, {i, 1}, {i, 2}};
            return board[i][0];
        }
        // Column
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
        {
            winCells = {{0, i}, {1, i}, {2, i}};
            return board[0][i];
        }
    }

    // Diagonals
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
    {
        winCells = {{0, 0}, {1, 1}, {2, 2}};
        return board[0][0];
    }

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
    {
        winCells = {{0, 2}, {1, 1}, {2, 0}};
        return board[0][2];
    }

    return ' ';
}

void drawWinningLine(sf::RenderWindow& window, const std::vector<std::pair<int, int>>& winCells)
{
    if (winCells.size() != 3)
        return;

    sf::Vector2f start(
        GRID_PADDING + winCells[0].second * CELL_SIZE + CELL_SIZE / 2,
        GRID_PADDING + winCells[0].first * CELL_SIZE + CELL_SIZE / 2
    );

    sf::Vector2f end(
        GRID_PADDING + winCells[2].second * CELL_SIZE + CELL_SIZE / 2,
        GRID_PADDING + winCells[2].first * CELL_SIZE + CELL_SIZE / 2
    );

    sf::Vector2f direction = end - start;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    float angle = std::atan2(direction.y, direction.x) * 180 / 3.14159f;

    sf::RectangleShape line(sf::Vector2f(length, WIN_LINE_THICKNESS));
    line.setFillColor(sf::Color::Green);
    line.setOrigin(0, WIN_LINE_THICKNESS / 2);
    line.setPosition(start);
    line.setRotation(angle);

    window.draw(line);
}


void drawWinnerMessage(sf::RenderWindow& window, char winner)
{
    sf::Font font;
    if (!font.loadFromFile("assets/ShareTechMono-Regular.ttf"))
	{
		std::cerr << "Failed to load font!" << std::endl;
		return ;
	}
    std::string message;
    if (winner == 'T') {
        message = "It's a Tie!";
    } else {
        message = "Winner: ";
        message += winner;
    }

    sf::Text text(message, font, 25);
    text.setFillColor(sf::Color::Green);
    text.setPosition(20, 760);
    window.draw(text);
}

