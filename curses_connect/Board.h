//
// Created by Bi Nguyen on 2/3/19.
//

#include "trackWinCursor.h"
#ifndef NCURSESCONNECTN_BOARD_H
#define NCURSESCONNECTN_BOARD_H

typedef struct Board_struct{
  int numRows, numCols, numWin;
  char pieces;
  char **the_board;
}Board;

Board makeBoard(int row, int col, int numWin, char pieces);

void freeBoard(Board * board);

#endif //NCURSESCONNECTN_BOARD_H
