//
// Created by Bi Nguyen on 7/29/2018.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "board.h"
#include "inputValidation.h"

Board makeBoard(int numRows, int numCols, char blankChar, int numMines) {
  Board board; // created a variable udner the board struct, that's called board
  // in this Board board, board has access to the Board's parameters
  board.theBoard = (char**)malloc(numRows*sizeof(char*));
  for (int i = 0 ; i < numRows; ++i){
    board.theBoard[i] = (char*)malloc(numCols* sizeof(char));
    for (int j = 0; j < numCols; ++j){
      board.theBoard[i][j] = blankChar;
    }
  }
  board.numRows = numRows;
  board.numCols = numCols;
  board.blankChar = blankChar;
  board.numMines = numMines;
  return board;
}
void printBoard(Board board) {
  for (int i = board.numRows - 1; i >= 0 ; --i ){
    printf("%d ", i);
    for (int j = 0; j < board.numCols; ++j){
      printf("%c ", board.theBoard[i][j]);
    }
    printf("\n");
  }
  printf("  ");
  for (int j = 0; j < board.numCols ; ++j){
    printf("%d ", j);
  }
  printf("\n");
}
void cleanUpboard(Board* board) {
  for (int row = 0; row < board->numRows; ++row) {
    free(board->theBoard[row]);
  }
  free(board->theBoard);
  board->theBoard = NULL;
  board->numRows = 0;
  board->numCols = 0;
  board->numMines =0;
  board->seed =0;


}

Board hideBoard(int numRows, int numCols, char blankChar, int numMines, int seed){
  Board hiddenBoard;
  hiddenBoard.theBoard = (char**)malloc(numRows*sizeof(char*));
  for (int i = 0 ; i < numRows; ++i){
    hiddenBoard.theBoard[i] = (char*)malloc(numCols* sizeof(char));
    for (int j = 0; j < numCols; ++j){
      hiddenBoard.theBoard[i][j] = blankChar;
    }
  }
  hiddenBoard.numRows = numRows;
  hiddenBoard.numCols = numCols;
  hiddenBoard.blankChar = blankChar;
  hiddenBoard.numMines = numMines;
  hiddenBoard.seed = seed;
  return hiddenBoard;
}
// PLACE MINE FOR HIDDEN BOARD
void placeMine(struct Board_struct* hiddenBoard) {
    int x,y;
    if (hiddenBoard->seed == 0){
      srand(time(NULL));
      for(int i = 0; i < hiddenBoard->numMines; ++i){
        x = rand()%hiddenBoard->numRows;
        y = rand()%hiddenBoard->numCols;
        printf("Placing Mines at %d, %d", x,y);
        hiddenBoard->theBoard[x][y] = '*';
      }
    }
    else{
      srand(hiddenBoard->seed);
      for(int i = 0; i < hiddenBoard->numMines; ++i){
        x = rand()%hiddenBoard->numRows;
        y = rand()%hiddenBoard->numCols;
        printf("Placing mine at %d, %d\n", x,y);
        hiddenBoard->theBoard[x][y] = '*';
      }
    }
}
void placeValues(struct Board_struct* hiddenBoard) {
  for (int i = 0; i < hiddenBoard->numRows; ++i) {
    for (int j = 0; j < hiddenBoard->numCols; ++j) {
      if (hiddenBoard->theBoard[i][j] == '*') {
        for (int row = i - 1; row <= i + 1; ++row) {
          for (int col = j - 1; col <= j + 1; ++col) {
            if (row == i && col == j) {
              continue;
            } else if (isInBound(row, col, hiddenBoard->numRows, hiddenBoard->numCols)) {
              if (hiddenBoard->theBoard[row][col] == '#') {
                hiddenBoard->theBoard[row][col] = '1';
              } else if (hiddenBoard->theBoard[row][col] == '*') {
                continue;
              } else {
                ++hiddenBoard->theBoard[row][col];
              }
            }
          }
        }
      }
    }
  }
  for (int i =0; i <hiddenBoard->numRows; ++i){
    for (int j = 0; j < hiddenBoard->numCols; ++j) {
      if (hiddenBoard->theBoard[i][j] == '#'){
        hiddenBoard->theBoard[i][j] = '0';
      }
    }
  }
}

