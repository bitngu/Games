//
// Created by Bi Nguyen on 2/4/19.
//
#ifndef NCURSESCONNECTN_MOVE_H
#define NCURSESCONNECTN_MOVE_H
#include "trackWinCursor.h"
#include "Board.h"
typedef struct Move_struct{
  int row, col;
  char marker;
}Move;

struct Board_struct;

typedef enum {Player1 = 0, Player2 = 1} PlayerTurn;
Move getValidMove(struct Board_struct * board, PlayerTurn playerTurn,trackCursorWin * win, FILE * fp);
bool isColFull(struct Board_struct * board,trackCursorWin * win);
void dropPieces(Board*board, trackCursorWin * win, Move move);
void moveWithChar(trackCursorWin * win, Move move);
void delMove(trackCursorWin * win);
trackCursorWin displayEndBoard(trackCursorWin*win, Board board);
void printLogfile(trackCursorWin * win, FILE * fp);


#endif //NCURSESCONNECTN_MOVE_H

