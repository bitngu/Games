//
// Created by Bi Nguyen on 2/3/19.
//
#include "stdbool.h"
#include "Board.h"
#include "Move.h"
#include "trackWinCursor.h"
#ifndef NCURSESCONNECTN_WIN_H
#define NCURSESCONNECTN_WIN_H

bool isGameOver(Board board);
bool horizWin(Board board);
bool vertWin(Board board);
bool leftDiagWin(Board board);
bool rightDiag(Board board);
bool iswin(Board board);
bool isTie(Board board);
void declareWinner(Board board, trackCursorWin *endWin, PlayerTurn playerTurn);
#endif //NCURSESCONNECTN_WIN_H
