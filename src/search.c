#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "board.h"

#define NEG_INFINITY (-1)
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int negamax(Board *board) {
    if (board->num_moves == 0) {
        if (isWin(board)) {
            return -1;
        }
        return 0;
    }
    if (isWin(board)) return -1;

    int* moves = GetMoves(board);

    int bestScore = NEG_INFINITY;
    for (int move = 0; move < board->num_moves; move++) {
        MakeMove(board, moves[move]);
        bestScore = MAX(-negamax(board), bestScore);
        UndoMove(board, moves[move]);
    }

    free(moves);
    return bestScore;
}



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