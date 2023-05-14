#ifndef TICTACTOE_H
#define TICTACTOE_H

struct Results {
    int draws;
    int xWins;
    int oWins;
};

char getChar(char);
void printBoard(char*);
void updateBoard(char*, char, int);
int checkPossibleMove(char*);
char checkWinner(char*);
void printOptions(char*, int);
int isValidMove(char*, int);
void printResults(struct Results*);

#endif