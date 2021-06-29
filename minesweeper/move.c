//
// Created by Bi Nguyen on 7/29/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "move.h"
#include "board.h"
#include "inputValidation.h"


bool isRevealed(int row, int col, struct Board_struct* board){
  if (isdigit(board->theBoard[row][col])){
    return true;
  }
  else{
    return false;
  }
}

bool isMark(int row, int col, struct Board_struct* board){
  if (board->theBoard[row][col] == '!'){
    return true;
  }
  else{
    return false;
  }
}
bool isQuestion(int row, int col, struct Board_struct* board){
  if (board->theBoard[row][col] == '?'){
    return true;
  }
  else{
    return false;
  }
}



Move getValidMove(struct Board_struct* board) {
  Move move;
  int numArgsRead, action1;
  move.numRows =0;
  move.numCols =0;
  bool isNotSucces = true;

  // get
  while (isNotSucces) {
    //get valid rows and cols
    do {
      printf("Enter row a row between 0-%d and a column between 0-%d: ", board->numRows - 1, board->numCols - 1);
      numArgsRead = scanf("%d %d", &move.numRows, &move.numCols);

    } while (!isValidMove(move, board, numArgsRead, 2));

    //upon success check if is revealed, ask for rows and cols again
    if (isRevealed(move.numRows, move.numCols, board)) {
      printf("This tile is already revealed.\n");
      printBoard(*board);
    }
      // if it's marked, ask for rows and cols again
    else if (isMark(move.numRows, move.numCols, board)) {
      printf("Enter Action\n0. UnMark\n1. Cancel\n");
      scanf("%d", &action1);
      if (isInRange(action1, 0, 2) && action1 == 0) {
        ++(board->numMines);
        board->theBoard[move.numRows][move.numCols] = '#';
        printf("Action: There are %d mines left\n", board->numMines);
        printBoard(*board);

      }
      else{
        printf("Action: ");
      }
    }
      //if it's a question, ask for rows and cols again
    else if (isQuestion(move.numRows, move.numCols, board)) {
      printf("Enter Action\n0. UnQuestion\n1. Cancel\n");
      scanf("%d", &action1);
      if (isInRange(action1, 0, 2) && action1 == 0) {
        board->theBoard[move.numRows][move.numCols] = '#';
        printf("Action: There are %d mines left\n", board->numMines);
        printBoard(*board);
      }
      else{
        printf("Action: ");
      }
    }

    else{
      isNotSucces = false;

    }
  }


  return move;
}

bool isValidMove(Move move, struct Board_struct* board, int numArgsRead, int numArgsNeeded) {
  return isValidFormat(numArgsRead, numArgsNeeded) &&
      isInRange(move.numRows, 0, board->numRows ) &&
      isInRange(move.numCols, 0, board->numCols );
}


void action(Move move, struct Board_struct* board, struct Board_struct* hiddenBoard) {
  int numArgsRead, action1;
  bool isNotSucces = true;
  bool isNotSuccess2 = true;
  while (isNotSuccess2 == true) {
    printf("Enter Action\n0. Reveal\n1. Question\n2. Mark\n3. Cancel\n"); // here, it reaveals. if  the position is already on top of a '?' or '!';
    scanf("%d", &move.action);
    if (!isInRange(move.action, 0, 4)) {
      isNotSucces = true;
    } else {
      isNotSucces = false;
    }

    if (move.action == 0) {
      to_reveal(move.numRows, move.numCols, board, hiddenBoard);
      isNotSucces = false;
      isNotSuccess2= false;
    } else if (move.action == 1) {// is questioned
      if (board->theBoard[move.numRows][move.numCols] == '#') {
        board->theBoard[move.numRows][move.numCols] = '?';
        isNotSucces = false;
        isNotSuccess2= false;
      } else {
        isNotSucces = true;
      }
    } else if (move.action == 2) { // to mark
      if (board->theBoard[move.numRows][move.numCols] == '#') {
        --(board->numMines);
        board->theBoard[move.numRows][move.numCols] = '!';
        isNotSucces = false;
        isNotSuccess2 = false;

      } else {
        isNotSucces = true; //
      }

    } else if (move.action == 3) {
      printf("Action: ");
      isNotSucces = false;
      isNotSuccess2=false;
    }

    while (isNotSucces == true) {
      //get valid rows and cols
      do {
        printf("Action: Enter row a row between 0-%d and a column between 0-%d: ",
               board->numRows - 1,
               board->numCols - 1);
        numArgsRead = scanf("%d %d", &move.numRows, &move.numCols);

      } while (!isValidMove(move, board, numArgsRead, 2));

      //upon success check if is revealed;
      if (isRevealed(move.numRows, move.numCols, board)) {
        printf("This tile is already revealed.\n");
        isNotSucces = true;
      }
        // if it's marked
      else if (isMark(move.numRows, move.numCols, board)) {
        printf("Enter Action\n0. UnMark\n1. Cancel\n");
        scanf("%d", &action1);
        if (isInRange(action1, 0, 2) && action1 == 0) {
          ++(board->numMines);
          board->theBoard[move.numRows][move.numCols] = '#';
          printf("Action: There are %d mines left\n", board->numMines);
          printBoard(*board);
          isNotSucces = false;
        } else {
          printf("Action: ");
          isNotSucces = true; //

        }
      }
        //if it's a question
      else if (isQuestion(move.numRows, move.numCols, board)) {
        printf("Enter Action\n0. UnQuestion\n1. Cancel\n");
        scanf("%d", &action1);
        if (isInRange(action1, 0, 2) && action1 == 0) {
          board->theBoard[move.numRows][move.numCols] = '#';
          printf("Action: There are %d mines left\n", board->numMines);
          printBoard(*board);
          isNotSucces = false;
        } else {
          printf("Action: ");
          isNotSucces = true;
        }
      } else if (board->theBoard[move.numRows][move.numCols] == '#') {
        isNotSuccess2 = true;
        isNotSucces = false;
      }
      else{
        printf("Action: ");
        isNotSucces = true;
        isNotSuccess2= false;

      }
    }

  }
}

void to_reveal(int numRows, int numCol, struct Board_struct* board, struct Board_struct* hiddenBoard) {
  if (!isInBound(numRows, numCol, board->numRows, board->numCols)) {
    return;
  } else if (board->theBoard[numRows][numCol] != '#') { //revealed and not 0;
    return;
  } else if (hiddenBoard->theBoard[numRows][numCol] == '*') {
    board->theBoard[numRows][numCol] = '*';
    return;

  } else if (hiddenBoard->theBoard[numRows][numCol] != '0') {
    board->theBoard[numRows][numCol] = hiddenBoard->theBoard[numRows][numCol];
    return;
  } else {
    board->theBoard[numRows][numCol] = hiddenBoard->theBoard[numRows][numCol];
    to_reveal(numRows+1 ,numCol, board, hiddenBoard);// up 1
    to_reveal(numRows, numCol-1, board, hiddenBoard); // left 1
    to_reveal(numRows,numCol+1, board, hiddenBoard);// right 1
    to_reveal(numRows+1,numCol-1, board, hiddenBoard);// up  left
    to_reveal(numRows+1,numCol+1, board, hiddenBoard);//up right
    to_reveal(numRows-1, numCol, board, hiddenBoard);// down 1
    to_reveal(numRows-1,numCol-1, board, hiddenBoard); //down left
    to_reveal(numRows, numCol+1, board, hiddenBoard);//down right
  }
}
