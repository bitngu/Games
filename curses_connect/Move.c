//
// Created by Bi Nguyen on 2/4/19.
//

#include "Move.h"
#include "trackWinCursor.h"
#include "Board.h"

Move getValidMove(struct Board_struct * board, PlayerTurn playerTurn, trackCursorWin * win, FILE * fp) {
  Move move;
  move.marker = "XO"[playerTurn];
  while (true) {
    moveWithChar(win, move);
    wmove(win->cursorWin, win->cursorRow, win->cursorCol);
    char input = wgetch(win->cursorWin);
    printLogfile(win, fp);
    if (input == 'a' || input == 'j') {
      delMove(win);
      if (win->cursorCol > 0) {
        win->cursorCol -= 1;
      }
      else{
        win->cursorCol = board->numCols - 1;
      }
      moveWithChar(win,move);
    }
    else if (input == 's' || input == 'k') {
      delMove(win);
      if (win->cursorCol < board->numCols - 1) {
        win->cursorCol += 1;
      }
      else{
        //if out of bound, wrap around
        win->cursorCol = 0;
      }
      moveWithChar(win,move);

    }
    else if ((input == ' ' || input == '\n') && !(isColFull(board, win))){
      move.marker = "XO"[playerTurn];
      dropPieces(board,win,move);
      return move;
    }
    wrefresh(win->cursorWin);
  }
}

void dropPieces(Board * board, trackCursorWin * win, Move move) {
  int curRow = win->cursorRow;
  for (int i = board->numRows-1; i >= 0; --i) {
    if (board->the_board[i][win->cursorCol] == board->pieces) {
      board->the_board[i][win->cursorCol] = move.marker;
      mvwaddch(win->cursorWin, i+1, win->cursorCol, move.marker);
      wmove(win->cursorWin,curRow,win->cursorCol);
      return;
    }
  }
}
bool isColFull(struct Board_struct * board, trackCursorWin * win) {
  for (int i = board->numRows - 1;i >= 0; --i){
    if (board->the_board[i][win->cursorCol] == board->pieces){
      return FALSE;
    }
  }
  return TRUE;
}

void moveWithChar(trackCursorWin * win, Move move) {
  mvwaddch(win->cursorWin, win->cursorRow, win->cursorCol, move.marker);
}
void delMove(trackCursorWin * win) {
  mvwdelch(win->cursorWin, win->cursorRow, win->cursorCol);


}

trackCursorWin displayEndBoard(trackCursorWin * win, Board board) {
  trackCursorWin endWin;
  endWin.cursorWin = newwin(getNumRows(win), getNumCols(win)+15, 0,0); // need to have enough to print win
  endWin.cursorRow = win->cursorRow;
  endWin.cursorCol = win->cursorCol;
  for (int i = 0; i < board.numRows; ++i){
    for (int j = 0; j < board.numCols; ++j){
      mvwaddch(endWin.cursorWin, i+1, j, board.the_board[i][j]);
    }
    wmove(endWin.cursorWin, endWin.cursorRow, endWin.cursorCol);
  }
  return endWin;
}


void printLogfile(trackCursorWin * win, FILE * fp) {
  int curRow = win->cursorRow, curCol = win->cursorCol;
  for (int i = 0; i < getNumRows(win); ++i) {
    for (int j = 0; j < getNumCols(win); ++j){
      chtype winChar = mvwinch(win->cursorWin, i, j);
      char theChar = winChar & A_CHARTEXT;
      fprintf(fp, "%c", theChar);
    }
    fprintf(fp,"\n");
  }
  fprintf(fp,"\n");
  wmove(win->cursorWin, curCol,curRow);
}