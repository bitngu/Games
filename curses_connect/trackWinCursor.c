//
// Created by Bi Nguyen on 2/3/19.
//

#include "trackWinCursor.h"

trackCursorWin newCursorTrackWin(int row, int col, int rowStart, int colStart) {
  trackCursorWin window;
  window.cursorWin = newwin(row,col,rowStart,colStart);
  window.cursorCol = 0;
  window.cursorRow = 0;
  return window;
}
void fillWindow(trackCursorWin * win, char pieces) {
  int curRow = win->cursorRow, curCol = win->cursorCol;
  for (int i = 1; i < getNumRows(win) - 1; ++i) {
    for (int j = 0; j < getNumCols(win); ++j){
      mvwaddch(win->cursorWin, i,j, pieces);
    }
  }
  wmove(win->cursorWin, curCol,curRow);
}

int getNumRows(trackCursorWin * win) {
  return getmaxy(win->cursorWin);
}
int getNumCols(trackCursorWin * win) {
  return getmaxx(win->cursorWin);
}


