//
// Created by Bi Nguyen on 7/29/2018.
//

#include <ctype.h>
#include <stdio.h>
#include "inputValidation.h"
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character= 'c';
  do{
    scanf("%c", &character);
    if(!isspace(character)){
      formatIsGood = false;
    }
  }while(character != '\n');
  return formatIsGood;

}
bool isInRange(int value, int lowerBound, int upperBound) {
  return (value >= lowerBound) && (value < upperBound);// double check if this make sense
}
bool isInBound(int mine_row, int mine_col, int numRows, int numCols) {
  return (mine_row >=0 && mine_row < numRows) && (mine_col>=0 && mine_col < numCols);
}


