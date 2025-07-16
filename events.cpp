/* ******************************************************************************/
/*                                                                              */
/*  File:       events.cpp                                     /\_/\            */
/*  Author:     Daniela Padilha                               ( o.o )           */
/*  Created:    2025/07/15 12:54:35                            > ^ <            */
/*  Updated:    2025/07/16 16:33:40                                             */
/*                                                                              */
/* ******************************************************************************/

#include "inc/ticTacToe.hpp"

void handleMouseClick(sf::Event& event, char board[3][3], char& currentPlayer,
                      bool& gameOver, char& winner, std::vector<std::pair<int, int>>& winCells)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
    {
        resetGame(board, currentPlayer, gameOver, winner, winCells);
        return;
    }

    if (event.type == sf::Event::MouseButtonPressed
            && event.mouseButton.button == sf::Mouse::Left)
    {
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;

        if (clickRestartButton(x, y))
        {
            resetGame(board, currentPlayer, gameOver, winner, winCells);
            return;
        }

        if (gameOver)
            return;

        int col = (x - GRID_PADDING) / CELL_SIZE;
        int row = (y - GRID_PADDING) / CELL_SIZE;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;
            winner = checkWinner(board, winCells);
            if (winner != ' ')
                gameOver = true;
            else
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

void resetGame(char board[3][3], char& currentPlayer, bool& gameOver,
               char& winner, std::vector<std::pair<int, int>>& winCells)
{
    resetBoard(board);
    currentPlayer = 'X';
    gameOver = false;
    winner = ' ';
    winCells.clear();
}

bool clickRestartButton(int x, int y)
{
	return (x >= 580 && x <= 730 && y >= 750 && y <= 790);
}
