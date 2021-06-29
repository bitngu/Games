//
// Created by Bi Nguyen on 7/29/2018.
//

#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H
#include <stdbool.h>
#include "move.h"

typedef struct Board_struct{
  char** theBoard;
  int numRows, numCols, numMines, seed;
  char blankChar;
}Board;

Board makeBoard(int numRows, int numCols, char blankChar, int numMines);
Board hideBoard(int numRows, int numCols, char blankChar, int numMines, int seed);
void placeMine(struct Board_struct* hiddenBoard);
void placeValues(struct Board_struct* hiddenBoard);
void printBoard(Board board);
void cleanUpboard(Board* board);

#endif //MINESWEEPER_BOARD_H


