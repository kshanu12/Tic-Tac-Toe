#ifndef CHECKS_H
#define CHECKS_H

int rangeCorrect(int cell);
int cellIsEmpty(int cell, char board[]);
int three(char turn, char board[]);
int threeInARow(char turn, char board[]);
int threeInAColumn(char turn, char board[]);
int threeInADiagonal(char turn, char board[]);
int check(char board[]);

#endif
