#include "TicTacToe.h"
#include <stdio.h>

int main() {

    char board[10] = "012102210";

    printf("%c\n", getChar('0'));
    printf("%c\n", getChar('1'));
    printf("%c\n", getChar('2'));
    printf("%c\n", getChar('A'));


    printBoard("BAD");
    printBoard(board);
    printf("%d\n", checkPossibleMove(board));

    printf("\n");

    updateBoard(board, '1', 1);
    printBoard(board);
    printf("%d\n", checkPossibleMove(board));

    printf("\n");

    updateBoard(board, '2', 5);
    updateBoard(board, '2', 9);
    printBoard(board);
    printf("%d\n", checkPossibleMove(board));

    printf("\n");

    return 0;
}