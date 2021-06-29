//
// Created by Bi Nguyen on 7/29/2018.
//

#ifndef MINESWEEPER_INPUTVALIDATION_H
#define MINESWEEPER_INPUTVALIDATION_H

#include <stdbool.h>
bool isValidFormat(const int numArgsRead, const int numArgsNeed);
bool isInRange(int value, int lowerBound, int upperBound);
bool isInBound(int mine_row, int mine_col, int numRows, int numCols);
#endif //MINESWEEPER_INPUTVALIDATION_H