#ifndef TICTACTOE_H
#define TICTACTOE_H

char getChar(char);
void printBoard(char*);
void updateBoard(char*, char, int);
int checkPossibleMove(char*);
char checkWinner(char*);
void printOptions(char*, int);

#endif