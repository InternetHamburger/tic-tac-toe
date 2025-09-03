#include <stdio.h>
#include "src/board.h"
#include "src/search.h"

int main(void) {
    Board board = {
        .squares = {0, 0, 0, 0, 0, 0, 0, 0, 0},
        .num_moves = 9,
        .x_to_move = 1
    };

    printf("%d\n", negamax(&board));
    return 0;
}