#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "move.h"
#include "inputValidation.h"
#include "win.h"

int main(int argc, char** argv) {
  int numRows, numCols, numMines, seed= 0;
  if(argc < 4) {
    printf("Not enough arguments. Usage:\n"
           "./mine_sweeper.out num_rows num_cols num_mines [seed])");
    exit(0);
  }
  else if (argc > 5){
    printf("Too many arguments. Usage:\n"
           "./mine_sweeper.out num_rows num_cols num_mines [seed])");
    exit(0);
  }
 if (argc == 4){
    sscanf(argv[1], "%d", &numRows);
    sscanf(argv[2], "%d", &numCols);
    sscanf(argv[3], "%d", &numMines);
  }
  else if (argc == 5){
   sscanf(argv[1], "%d", &numRows);
   sscanf(argv[2], "%d", &numCols);
   sscanf(argv[3], "%d", &numMines);
   sscanf(argv[4], "%d", &seed);
  }

  Board board = makeBoard(numRows, numCols, '#', numMines);
  Board hiddenBoard = hideBoard(numRows, numCols, '#', numMines, seed);
  placeMine(&hiddenBoard); // get the random mines and place it on hidden board
  placeValues(&hiddenBoard);// place all values on the hidden board to compare later
  printf("There are %d mines left\n", board.numMines);
  while (!isGameOver(board,hiddenBoard)) {
    printBoard(board);
    Move move = getValidMove(&board);
    action(move, &board, &hiddenBoard);
    printf("Action: ");
    if (!isGameOver(board,hiddenBoard)){
      printf("There are %d mines left\n", board.numMines);
    }
    else{
      break;
    }
  }
  printBoard(hiddenBoard);
  declareWinner(board);

  cleanUpboard(&board);
  cleanUpboard(&hiddenBoard);
}