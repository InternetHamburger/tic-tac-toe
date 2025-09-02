#include <stdlib.h>
#include <stdio.h>
#include "board.h"

int perft(Board* board, int depth) {
    if (depth == 0) return 1;

    int* moves = GetMoves(board);

    int nodes = 0;
    for (int move = 0; move < board->num_moves; move++) {
        MakeMove(board, moves[move]);
        nodes += perft(board, depth - 1);
        UndoMove(board, moves[move]);
    }

    free(moves);
    return nodes;
}