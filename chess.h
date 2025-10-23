#ifndef CHESS_H
#define CHESS_H
#include <stdbool.h>

typedef struct {
    char column;
    int row;
} ChessField;

bool canQueenMove(ChessField from, ChessField to);

#endif
