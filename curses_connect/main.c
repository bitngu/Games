#include <stdio.h>
#include <ncurses.h>
#include "Board.h"
#include "win.h"
#include "trackWinCursor.h"
#include "Move.h"

int main(int argc, char** argv) {
  int num_row, num_col, num_win;
  initscr();
  noecho();
  cbreak();
  FILE * logfile = NULL;
  sscanf(argv[1], "%d", &num_row);
  sscanf(argv[2], "%d", &num_col);
  sscanf(argv[3], "%d", &num_win);
  logfile = fopen(argv[4], "w");
  trackCursorWin boardWin = newCursorTrackWin(num_row+2,num_col,0,0); //Need to add 2 to the row when creating the window board
  fillWindow(&boardWin, '*');
  wrefresh(boardWin.cursorWin);
  PlayerTurn playerTurn = Player1;
  Board board = makeBoard(num_row,num_col,num_win, '*');

  while (!isGameOver(board)){
    getValidMove(&board, playerTurn, &boardWin,logfile);
    playerTurn = playerTurn == Player1 ? Player2 : Player1;
  }
  trackCursorWin endWin = displayEndBoard(&boardWin, board);
  declareWinner(board,&endWin, playerTurn);
  wrefresh(endWin.cursorWin);
  printLogfile(&endWin, logfile);
  freeBoard(&board);
  delwin(endWin.cursorWin);
  delwin(boardWin.cursorWin);
  endwin();
  return 0;
}

