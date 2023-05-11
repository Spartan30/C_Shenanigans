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

/*
* Position should be value from 1 - 9
* Subtract 1 from position to convert to array position
*/
void updateBoard(char *board, char value, int position) {
    if(strlen(board) != 9) {
        printf("INVALID BOARD\n");
        return;
    }

    if(position < 1 || position > 9) {
        printf("INVALID MOVE - OUT OF RANGE\n");
        return;
    }

    if( board[position-1] != '0') {
        printf("INVALID MOVE - POSITION TAKEN\n");
        return;
    }

    if(value != '1' && value != '2') {
        printf("INVALID VALUE\n");
        return;
    }

    board[position-1] = value;
}

int checkPossibleMove(char* board) {
    for(int i = 0; i < strlen(board); i++) {
        if(board[i] == '0') {
            return 1;
        }
    }

    return 0;
}