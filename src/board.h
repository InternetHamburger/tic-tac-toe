#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

typedef struct {
    int squares[9];
    int num_moves;
    int x_to_move;
} Board;


void PrintBoard(Board *board);
void MakeMove(Board *board, int move);
void UndoMove(Board *board, int move);
int* GetMoves(const Board *board);
int isWin(const Board *board);

#endif //TIC_TAC_TOE_BOARD_H