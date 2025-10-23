#include <stdio.h>
#include <stdbool.h>
#include "chess.h"

bool canQueenMove(ChessField from, ChessField to) {
    int colDiff = from.column - to.column;
    int rowDiff = from.row - to.row;

    if (colDiff == 0 || rowDiff == 0)
        return true;
    if (colDiff < 0) colDiff = -colDiff;
    if (rowDiff < 0) rowDiff = -rowDiff;
    if (colDiff == rowDiff)
        return true;
    return false;
}

int main() {
    ChessField start, end;
    scanf(" %c%d", &start.column, &start.row);
    scanf(" %c%d", &end.column, &end.row);

    if (canQueenMove(start, end))
        printf("Ферзь може перейти\n");
    else
        printf("Ферзь не може перейти\n");

    return 0;
}
