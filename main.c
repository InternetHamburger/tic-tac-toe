#include <stdio.h>
#include "src/board.h"
#include "src/ugi.h"

int main(void) {
    Board board = {
        .x_bitboard = 0b0,
        .o_bitboard = 0b0,
        .num_moves = 9,
        .x_to_move = 1
    };


    Match(&board);
    int a;
    scanf("%d", &a);
    return 0;
}