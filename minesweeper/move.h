//
// Created by Bi Nguyen on 7/29/2018.
//

#ifndef MINESWEEPER_MOVE_H
#define MINESWEEPER_MOVE_H
#include <stdbool.h>
typedef struct Move_struct{
  int numRows, numCols, action;
}Move;


struct Board_struct;


Move getValidMove(struct Board_struct* board);


bool isValidMove(Move move,  struct Board_struct* board, int numArgsRead, int numArgsNeeded);

void action(Move move, struct Board_struct* board, struct Board_struct* hiddenBoard);// not sure what to put, action wants to return update board


void to_reveal(int numRows, int numCols, struct Board_struct* board, struct Board_struct* hiddenBoard); // not sure what




#endif //MINESWEEPER_MOVE_H
