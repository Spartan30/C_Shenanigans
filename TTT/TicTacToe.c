#include "TicTacToe.h"
#include <stdio.h>
#include <string.h>

char getChar(char value) {
    switch(value) {
        case '0':
            return ' ';
        case '1':
            return 'X';
        case '2':
            return 'O';
        default:
            return '?';
    }
}

void printBoard(char *board) {
    if(strlen(board) != 9) {
        printf("INVALID BOARD\n");
        return;
    }

    printf("%c|%c|%c\n", getChar(board[0]), getChar(board[1]), getChar(board[2]));
    printf("-----\n");
    printf("%c|%c|%c\n", getChar(board[3]), getChar(board[4]), getChar(board[5]));
    printf("-----\n");
    printf("%c|%c|%c\n", getChar(board[6]), getChar(board[7]), getChar(board[8]));
}