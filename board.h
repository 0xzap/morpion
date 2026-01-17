#ifndef BOARD_H
#define BOARD_H

#define PLAYER 'X'
#define AI 'O'

extern char board[3][3];

void initBoard();
void printBoard();
int isMovesLeft();
int evaluate();

#endif
