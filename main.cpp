/* ******************************************************************************/
/*                                                                              */
/*  File:       main.cpp                                       /\_/\            */
/*  Author:     Daniela Padilha                               ( o.o )           */
/*  Created:    2025/07/13 01:26:43                            > ^ <            */
/*  Updated:    2025/07/16 15:44:10                                             */
/*                                                                              */
/* ******************************************************************************/

#include "inc/ticTacToe.hpp"

int main(void)
{
    sf::RenderWindow* window = windowCreate();

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char currentPlayer = 'X';
    char winner = ' ';
    bool gameOver = false;
    std::vector<std::pair<int, int>> winCells;

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window->close();
            else
                handleMouseClick(event, board, currentPlayer, gameOver, winner, winCells);
        }
        window->clear(sf::Color::Black);
        drawGrid(*window);
        drawBoard(*window, board);
        if (winner != ' ')
        {
            drawWinningLine(*window, winCells);
            drawWinnerMessage(*window, winner);
        }
        drawRestartButton(*window);
        window->display();
    }
    delete window;
    return 0;
}

