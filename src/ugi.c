#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "search.h"

int GetBestMove(Board *board) {
    int best_move;

    negamax(board, 1, &best_move);
    return best_move;
}

int IsLegalMove(const Board *board, const int *move) {
    const int occupation = board->x_bitboard | board->o_bitboard;

    return !(occupation & (1 << *move)) && *move >= 0 && *move <= 8;
}

void Match(Board *board) {
    printf("Would you like to start y/n ");

    char input;
    scanf("%c", &input);
    int move;
    if (input == 'y') {
        printf("Your move: ");
        scanf("%d", &move);

        MakeMove(board, move);

        while (!isWin(board) && board->num_moves > 0) {

            negamax(board, 1, &move);
            MakeMove(board, move);
            PrintBoard(board);
            printf("Your move: ");
            scanf("%d", &move);
            if (!IsLegalMove(board, &move)) {
                printf("Illegal move");
                exit(-1);
            }
            MakeMove(board, move);

        }
        if (board->num_moves == 0 && !isWin(board)) {
            printf("Draw");
        }
        else if (!board->x_to_move) {
            printf("You won");
        }
        else {
            printf("Computer won");
        }
    }
    else {
        negamax(board, 1, &move);
        MakeMove(board, move);
        PrintBoard(board);
        while (!isWin(board) && board->num_moves > 0) {

            printf("Your move: ");
            scanf("%d", &move);
            if (!IsLegalMove(board, &move)) {
                printf("Illegal move");
                exit(-1);
            }
            MakeMove(board, move);

            negamax(board, 1, &move);
            MakeMove(board, move);
            PrintBoard(board);

        }

        if (board->num_moves == 0 && !isWin(board)) {
            printf("Draw");
        }
        else if (!board->x_to_move) {
            printf("Computer won");
        }
        else {
            printf("You won");
        }
    }
}