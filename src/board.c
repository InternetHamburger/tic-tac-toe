#include "board.h"

#include <stdlib.h>


void MakeMove(Board* board, const int move) {
    board->squares[move] = board->x_to_move ? 1 : 2;
    board->x_to_move = !board->x_to_move;
    board->num_moves--;
}

void UndoMove(Board* board, const int move) {
    board->squares[move] = 0;
    board->x_to_move = !board->x_to_move;
    board->num_moves++;
}

int* GetMoves(const Board* board) {
    int* moves = malloc(sizeof(int) * board->num_moves);

    int move = 0;
    for (int i = 0; i < 9; i++) {
        if (!board->squares[i]) {
            moves[move++] = i;
        }
    }

    return moves;
}