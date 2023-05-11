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
    printOptions(board, 0);

    printf("\n");

    updateBoard(board, '1', 1);
    printBoard(board);
    printf("%d\n", checkPossibleMove(board));
    printOptions(board, 1);

    printf("\n");

    updateBoard(board, '2', 5);
    updateBoard(board, '2', 9);
    printBoard(board);
    printf("%d\n", checkPossibleMove(board));
    printf("%c\n", checkWinner(board));

    printf("\n");

    printf("%c\n", checkWinner("111000000")); // row - 1
    printf("%c\n", checkWinner("201200210")); // col - 2
    printf("%c\n", checkWinner("201020012")); // NW to SE - 2
    printf("%c\n", checkWinner("221010120")); // NE to SW - 1

    return 0;
}