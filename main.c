#include <stdio.h>
#include "src/search.h"
#include "src/board.h"

int main(void) {
    Board board = {
        .squares = {0, 0, 0, 0, 0, 0, 0, 0, 0},
        .num_moves = 9,
        .x_to_move = 1
    };

    printf("%d\n", perft(&board, 5));
    return 0;
}