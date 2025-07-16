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
# include <vector>
# include <utility> // for std::pair
# include <cmath>

const float CELL_SIZE = 235.0f;
const float GRID_PADDING = 20.0f;
const float GRID_THICKNESS = 5.0f;
const float SYMBOL_PADDING = 20.0f;
const float WIN_LINE_THICKNESS = 10.0f;

sf::RenderWindow* windowCreate();
void 			  drawGrid(sf::RenderWindow& window);
void 			  drawCircle(sf::RenderWindow& window, int row, int col);
void			  drawX(sf::RenderWindow& window, int row, int col);
void 			  drawBoard(sf::RenderWindow& window, char board[3][3]);
void 			  handleMouseClick(sf::Event& event, char board[3][3], char& currentPlayer,
                	bool& gameOver, char& winner, std::vector<std::pair<int, int>>& winCells);
char 			  checkWinner(char board[3][3], std::vector<std::pair<int, int>>& winCells);
void 			  drawWinningLine(sf::RenderWindow& window,
					const std::vector<std::pair<int, int>>& winCells);
void 			  resetBoard(char board[3][3]);
void 			  drawWinnerMessage(sf::RenderWindow& window, char winner);
void 			  drawRestartButton(sf::RenderWindow& window);
void 			  resetGame(char board[3][3], char& currentPlayer, bool& gameOver,
               		char& winner, std::vector<std::pair<int, int>>& winCells);
bool 			  clickRestartButton(int x, int y);

#endif