//
// Created by Bi Nguyen on 2/3/19.
//
#include <stdio.h>
#include "Board.h"
#include "stdlib.h"
Board makeBoard(int row, int col, int numWin, char pieces) {
  Board board;
  board.numRows = row;
  board.numCols = col;
  board.pieces = pieces;
  board.numWin = numWin;
  board.the_board = (char**)malloc(board.numRows* sizeof(char*));
  for (int i = 0; i < board.numRows; ++i){
    board.the_board[i] = (char*)malloc(board.numCols * sizeof(char));
    for (int j =0 ; j < board.numCols; ++j){
      board.the_board[i][j] = pieces;
    }
  }
  return board;
}

void freeBoard(Board * board) {
  for (int i = 0; i < board->numRows ; ++i) {
    free(board->the_board[i]);
  }
  free(board->the_board);
  board->the_board = NULL;

}


