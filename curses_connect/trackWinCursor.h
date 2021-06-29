//
// Created by Bi Nguyen on 2/3/19.
//
#include <curses.h>
#ifndef NCURSESCONNECTN_WINDOW_H
#define NCURSESCONNECTN_WINDOW_H
typedef struct trackCursorWin_struct{
  WINDOW* cursorWin;
  int cursorRow, cursorCol;
}trackCursorWin;

trackCursorWin newCursorTrackWin(int row, int col, int rowStart, int colStart);

void fillWindow(trackCursorWin* win, char pieces );

int getNumRows(trackCursorWin* win);

int getNumCols(trackCursorWin* win);

#endif //NCURSESCONNECTN_WINDOW_H
