#ifndef TIC_TAC_TOE_SEARCH_H
#define TIC_TAC_TOE_SEARCH_H
#include "board.h"

int negamax(Board *board);

int perft(Board *board, int depth);

#endif //TIC_TAC_TOE_SEARCH_H