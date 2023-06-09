#include "TicTacToe.h"
#include <stdio.h>
#include <string.h>

/*
* Param: char value
* Takes in a char and returns the game value, primarily used for printing the board to the screen
* Return: char
* '0' = ' '
* '1' = 'X'
* '2' = 'O'
*/
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

/*
* Param: char *board
* Prints the board
* Return: void
*/
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
* Param: char *board, char value, int position
* Position should be value from 1 - 9
* Subtract 1 from position to convert to array position
* Updates a game board by setting the position in the char array to the value provided
* Return: void
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

/*
* Param: char *board
* Checks if there are any moves possible
* Return: int
*/
int checkPossibleMove(char *board) {
    for(int i = 0; i < strlen(board); i++) {
        if(board[i] == '0') {
            return 1;
        }
    }

    return 0;
}

/*
* Param: char *board
* Checks who the current winner is
* Return: char
* '0' - draw/no winner  yet
* '1' - X wins
* '2' - O wins
*/
char checkWinner(char *board) {

    for(int i = 0; i < 3; i++) {
        int rowStart = i * 3;
        if(board[rowStart] == board[rowStart + 1] && board[rowStart] == board[rowStart + 2]) {
            if(board[0] != '0') {
                return board[rowStart];
            }
        }

        if(board[i] == board[i + 3] && board[i] == board[i + 6]) {
            if(board[i] != '0') {
                return board[i];
            }
        }

    }

    if(board[0] == board[4] && board[0] == board[8]) {
        if(board[0] != '0') {
            return board[0];
        }
    }

    if(board[2] == board[4] && board[2] == board[6]) {
        if(board[2] != '0') {
            return board[2];
        }
    }

    return '0';
}

/*
* Param: char *board, int turn
* Prints who's turn it is and the available options for the user
* Return: void
*/
void printOptions(char *board, int turn) {

    if(turn % 2 == 0) {
        printf("It is X's turn\n");
    }
    else {
        printf("It is O's turn\n");
    }

    printf("Enter a number between 1-9 to place your piece\n");
    printf("Available options are:");

    for(int i = 0; i < strlen(board); i++) {
        if(board[i] == '0') {
            printf(" %d", (i+1));
        }
    }

    printf("\n");

}

/*
* Param: char *board, int position
* Determines if a move is valid
* Return: int
* 0 - invalid move
* 1 - valid move
*/
int isValidMove(char *board, int position) {
    if(position < 1 || position > 9) {
        return 0;
    }

    if(board[position - 1] != '0') {
        return 0;
    }

    return 1;
}

/*
* Param: struct Results *results
* Prints out the results (values in struct)
* Return: void
*/
void printResults(struct Results *results) {
    printf("\n");
    printf("There were %d draws\n", results->draws);
    printf("X won %d game(s)\n", results->xWins);
    printf("O won %d game(s)\n", results->oWins);
    printf("\n");
}

/*
* Param: struct Results *results
* Play the game of tic tac toe and record the winner
* Return: void
*/
void play(struct Results *results) {
    char board[10] = "000000000";
    char currPlayer;
    char winner;
    int turn = 0;
    int position;

    while(checkPossibleMove(board) == 1 && checkWinner(board) == '0') {
        printf("\n");
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

    printf("\n");
    printBoard(board);

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