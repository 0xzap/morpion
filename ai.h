#ifndef AI_H
#define AI_H

#include "board.h"

struct Move {
    int row, col;
};

struct Move findBestMove();
int minimax(int depth, int isMax);

#endif
