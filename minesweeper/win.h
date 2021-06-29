//
// Created by Bi Nguyen on 7/29/2018.
//

#ifndef MINESWEEPER_WIN_H
#define MINESWEEPER_WIN_H
#include "board.h"
bool isGameOver(Board board,struct Board_struct hideBoard);
void declareWinner(Board board);
bool lose(Board board);
bool win(Board board,struct Board_struct hideBoard);
#endif //MINESWEEPER_WIN_H
