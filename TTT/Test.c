#include "TicTacToe.h"
#include <stdio.h>

int main() {

    char board[9] = "012102210";

    printf("%c\n", getChar('0'));
    printf("%c\n", getChar('1'));
    printf("%c\n", getChar('2'));
    printf("%c\n", getChar('A'));


    printBoard("BAD");
    printBoard(board);

    return 0;
}