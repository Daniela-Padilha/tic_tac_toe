/* ******************************************************************************/
/*                                                                              */
/*  File:       events.cpp                                     /\_/\            */
/*  Author:     Daniela Padilha                               ( o.o )           */
/*  Created:    2025/07/15 12:54:35                            > ^ <            */
/*  Updated:    2025/07/15 15:18:32                                             */
/*                                                                              */
/* ******************************************************************************/

#include "inc/ticTacToe.hpp"

void handleMouseClick(sf::Event& event, char board[3][3], char& currentPlayer) 
{
    if (event.mouseButton.button == sf::Mouse::Left &&
        event.mouseButton.button == sf::Mouse::Left)
	{
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;

        int col = x / 200;
        int row = y / 200;

        std::cout << "Clicked on cell: (" << row << ", " << col << ")\n";
		
		if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') 
		{
   			board[row][col] = currentPlayer;

    		if (currentPlayer == 'X') 
       			currentPlayer = 'O';
			else 
        		currentPlayer = 'X';
		}
    }
}
