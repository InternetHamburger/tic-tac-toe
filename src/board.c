#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintBoard(const Board *board) {

    char squares[9];

    for (int i = 0; i < 9; i++) {
        if (board->x_bitboard & (1 << i)) squares[i] = 'X';
        else if (board->o_bitboard & (1 << i)) squares[i] = 'O';
        else squares[i] = ' ';
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
    if (board->x_to_move) {
        board->x_bitboard |= 1 << move;
    } else {
        board->o_bitboard |= 1 << move;
    }
    board->x_to_move = !board->x_to_move;
    board->num_moves--;
}

void UndoMove(Board* board, const int move) {
    if (board->x_to_move) {
        board->o_bitboard &= ~(1 << move);
    } else {
        board->x_bitboard &= ~(1 << move);
    }
    board->x_to_move = !board->x_to_move;
    board->num_moves++;
}

int* GetMoves(const Board* board) {

    int* moves = malloc(sizeof(int) * board->num_moves);
    int move = 0;

    const int occupation = board->x_bitboard | board->o_bitboard;

    for (int i = 0; i < 9; i++) {
        if (!(occupation & 1 << i)) {
            moves[move++] = i;
        }
    }
    return moves;
}

int isWin(const Board* board) {
    const int bitboard = board->x_to_move ? board->o_bitboard : board->x_bitboard;

    if ((~bitboard & 0b111) == 0) return 1;
    if ((~bitboard & 0b111000) == 0) return 1;
    if ((~bitboard & 0b111000000) == 0) return 1;

    if ((~bitboard & 0b1001001) == 0) return 1;
    if ((~bitboard & 0b10010010) == 0) return 1;
    if ((~bitboard & 0b100100100) == 0) return 1;

    if ((~bitboard & 0b100010001) == 0) return 1;
    if ((~bitboard & 0b001010100) == 0) return 1;

    return 0;
}