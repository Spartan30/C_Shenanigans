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