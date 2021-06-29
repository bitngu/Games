//
// Created by Bi Nguyen on 2/3/19.
//

#include "win.h"
#include "stdbool.h"

bool isGameOver(Board board) {
  return iswin(board) || isTie(board);
}
bool horizWin(Board board) {
  bool win = 0;
  int x_count, o_count;
  for (int i = 0; i < board.numRows; ++i){
    x_count = 0;
    o_count = 0;
    for(int j = 0; j < board.numCols; ++j){
      if (board.the_board[i][j] == 'X') {
        ++x_count;
        o_count = 0;
        if (x_count == board.numWin) {
          win = 1;
          return win;
        }
      }
      else if (board.the_board[i][j] == 'O'){
        ++o_count;
        x_count = 0;
        if(o_count == board.numWin){
          win = 1;
          return win;
          }
        }
        else{
          x_count = 0;
          o_count = 0;
        }
    }
  }
  return win;
}
bool vertWin(Board board) {
  bool win = 0;
  int x_count = 0, o_count = 0;
  for (int j = 0; j < board.numCols; ++j) {
    x_count = 0;
    o_count = 0;
    for (int i = 0; i < board.numRows ; ++i) {
      if (board.the_board[i][j] == 'X'){
        ++x_count;
        o_count = 0;
        if (x_count == board.numWin) {
          win = 1;
          return win;
        }
      }
      else if (board.the_board[i][j] == 'O'){
        ++o_count;
        x_count = 0;
        if(o_count == board.numWin){
          win = 1;
          return win;
        }
      }

      else{
        x_count = 0;
        o_count = 0;
      }
    }
  }
  return win;
}
bool leftDiagWin(Board board) {
  bool win = 0;
  int x_count=0, o_count=0;
  for (int rowStart = board.numRows-1; rowStart >= board.numWin - 1; --rowStart) {
    x_count = 0;
    o_count = 0;
    for (int colStart = 0; colStart <= board.numCols - board.numWin ; ++colStart) {
      x_count = 0;
      o_count = 0;
      for (int i = rowStart, j = colStart; j < board.numCols && i >= 0; ++j, --i) {
        if (board.the_board[i][j] == 'X') {
          ++x_count;
          o_count = 0;
          if (x_count == board.numWin) {
            win = 1;
            return win;
          }
        } else if (board.the_board[i][j] == 'O') {
          ++o_count;
          x_count = 0;
          if (o_count == board.numWin) {
            win = 1;
            return win;
          }
        } else {
          x_count = 0;
          o_count = 0;
        }
      }
    }
  }
    return win;
  }
bool rightDiag(Board board) {
  bool win = 0;
  int x_count = 0, o_count = 0;
  for (int rowStart = board.numRows - board.numWin; rowStart >= 0; --rowStart){
    x_count = 0;
    o_count = 0;
    for (int colStart = 0; colStart <= board.numCols - board.numWin; ++colStart){
      x_count = 0;
      o_count = 0;
      for (int i = rowStart, j = colStart; i < board.numRows && j < board.numCols; ++i, ++j){
        if (board.the_board[i][j] == 'X'){
          ++x_count;
          o_count = 0;
          if (x_count == board.numWin) {
            win = 1;
            return win;
          }
        }
        else if (board.the_board[i][j] == 'O'){
          ++o_count;
          x_count = 0;
          if (o_count == board.numWin) {
            win = 1;
            return win;
          }
        }
        else {
          x_count = 0;
          o_count = 0;
        }
      }
    }
  }
  return win;
}
void declareWinner(Board board, trackCursorWin * endWin, PlayerTurn playerTurn) {
  int curRow, curCol;
  curRow = endWin->cursorRow;
  curCol = endWin->cursorCol;
  if(iswin (board)){
    int winner = playerTurn == Player1 ? Player2 : Player1;
    winner++;
    mvwprintw(endWin->cursorWin,getNumRows(endWin) - 1, 0,"Player %d won!", winner);
  }else{
    mvwprintw(endWin->cursorWin,getNumRows(endWin) - 1, 0,"Tie Game");
  }
  char* x;
  if (playerTurn == Player1){
    x = "O";
  }
  else{
    x = "X";
  }
  mvwprintw(endWin->cursorWin,curRow,curCol, x);
  wmove(endWin->cursorWin,curRow,curCol);
}

bool iswin(Board board) {
  return leftDiagWin(board)||rightDiag(board)||horizWin(board)||vertWin(board);
}

bool isTie(Board board){
  for (int i = 0; i < board.numRows; ++i){
    for (int j = 0; j < board.numCols; ++j)
      if (board.the_board[i][j] == board.pieces){
        return FALSE;
      }
  }
  return TRUE;
}
