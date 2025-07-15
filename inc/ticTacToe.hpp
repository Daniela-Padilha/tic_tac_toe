/* ******************************************************************************/
/*                                                                              */
/*  File:       ticTacToe.hpp                                  /\_/\            */
/*  Author:     Daniela Padilha                               ( o.o )           */
/*  Created:    2025/07/14 23:15:59                            > ^ <            */
/*  Updated:    2025/07/14 23:15:59                                             */
/*                                                                              */
/* ******************************************************************************/

#ifndef TICTACTOE_HPP
# define TICTACTOE_HPP

# include <SFML/Graphics.hpp>
# include <iostream>

sf::RenderWindow* windowCreate();
void 			  drawGrid(sf::RenderWindow& window);
void 			  drawCircle(sf::RenderWindow& window, int row, int col);
void			  drawX(sf::RenderWindow& window, int row, int col);
void 			  drawBoard(sf::RenderWindow& window, char board[3][3]);
void 			  handleMouseClick(sf::Event& event, char board[3][3], char& currentPlayer);

#endif