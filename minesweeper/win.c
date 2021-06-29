//
// Created by Bi Nguyen on 7/29/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "win.h"
#include "board.h"


// or can do win where i compare each board but instead of a mine, it would be a mark
bool isGameOver(Board board, struct Board_struct hideBoard) {
  return lose(board) || win(board, hideBoard);
}

bool lose(Board board) {
  for (int i = 0; i < board.numRows; ++i) {
    for (int j = 0; j < board.numCols; ++j) {
      if (board.theBoard[i][j] == '*') {
        return true;
      }
    }
  }
  return false;
}

bool win(Board board, struct Board_struct hideBoard) {
  int count = 0, digit =0;
  for (int i = 0; i < board.numRows; ++i) {
    for (int j = 0; j < board.numCols; ++j) {
      if (board.theBoard[i][j] == '!' && hideBoard.theBoard[i][j] == '*') {
        ++count;
      }
      if (isdigit(board.theBoard[i][j])){
        ++digit;
      }
    }
  }
  return count== hideBoard.numMines && digit == (board.numCols*board.numRows) - hideBoard.numMines ;
}

void declareWinner(Board board) {
  for (int i = 0; i < board.numRows; ++i) {
    for (int j = 0; j < board.numCols; ++j) {
      if (board.theBoard[i][j] == '*') {
        printf("You Lost :(\n");
        return;
      }
    }
  }
  printf("You Won!!\n");
  return;
}



