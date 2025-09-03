#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void PrintBoard(Board *board) {

    char squares[9];

    for (int i = 0; i < 9; i++) {
        squares[i] = board->squares[i] == 0 ? ' ' : board->squares[i] == 1 ? 'X' : 'O';
    }
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", squares[0], squares[1], squares[2]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", squares[3], squares[4], squares[5]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", squares[6], squares[7], squares[8]);
    printf("+---+---+---+\n");
}


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
        if (board->squares[i] == 0) {
            moves[move++] = i;
        }
    }
    return moves;
}

int isWin(const Board* board) {
    if (board->squares[0] == board->squares[1] && board->squares[1] == board->squares[2] && board->squares[0] != 0) return 1;
    if (board->squares[3] == board->squares[4] && board->squares[4] == board->squares[5] && board->squares[3] != 0) return 1;
    if (board->squares[6] == board->squares[7] && board->squares[7] == board->squares[8] && board->squares[6] != 0) return 1;

    if (board->squares[0] == board->squares[3] && board->squares[3] == board->squares[6] && board->squares[0] != 0) return 1;
    if (board->squares[1] == board->squares[4] && board->squares[4] == board->squares[7] && board->squares[1] != 0) return 1;
    if (board->squares[2] == board->squares[5] && board->squares[5] == board->squares[8] && board->squares[2] != 0) return 1;

    if (board->squares[0] == board->squares[4] && board->squares[4] == board->squares[8] && board->squares[0] != 0) return 1;
    if (board->squares[2] == board->squares[4] && board->squares[4] == board->squares[6] && board->squares[2] != 0) return 1;
    return 0;
}