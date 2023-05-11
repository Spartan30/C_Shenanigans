#include "TicTacToe.h"
#include <stdio.h>


int main() {

    char board[10] = "000000000";
    int turn = 0;
    char currPlayer;
    int position;
    char winner;

    while(checkPossibleMove(board) == 1 && checkWinner(board) == '0') {

        printBoard(board);
        printOptions(board, turn);
        scanf("%d", &position);

        if(isValidMove(board, position) != 1) {
            printf("INVALID MOVE\n");
            continue;
        }

        if(turn % 2 == 0) {
            currPlayer = '1';
        }
        else {
            currPlayer = '2';
        }

        updateBoard(board, currPlayer, position);
        printf("\n");
        turn++;
    }

    winner = checkWinner(board);

    switch(winner) {
        case '0':
            printf("It's a draw!\n");
            break;
        case '1':
            printf("X wins!\n");
            break;
        case '2':
            printf("O wins!\n");
            break;
        default:
            printf("Something went wrong :(\n");
            break;
    }

    return 0;
}