#include "TicTacToe.h"
#include <stdio.h>
#include <stdlib.h>

void play(struct Results*);

int main() {
    struct Results *results = (struct Results *)malloc(sizeof(struct Results));
    char playAgain = ' ';

    results->draws = 0;
    results->xWins = 0;
    results->oWins = 0;

    do {

        play(results);

        printf("Do you want to play again? (y/n)\n");
        do {
            scanf("%c", &playAgain);
        }while(playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N');

    }while(playAgain == 'y' || playAgain == 'Y');

    printResults(results);

    free(results);

    return 0;
}

void play(struct Results *results) {
    char board[10] = "000000000";
    char currPlayer;
    char winner;
    int turn = 0;
    int position;

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
            results->draws++;
            break;
        case '1':
            printf("X wins!\n");
            results->xWins++;
            break;
        case '2':
            printf("O wins!\n");
            results->oWins++;
            break;
        default:
            printf("Something went wrong :(\n");
            break;
    }
}