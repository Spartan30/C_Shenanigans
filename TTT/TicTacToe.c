#include "TicTacToe.h"
#include <stdio.h>
#include <string.h>

void printBoard(char *board) {
    if(strlen(board) != 9) {
        printf("INVALID BOARD\n");
        return;
    }

    printf("Valid Board\n");
}