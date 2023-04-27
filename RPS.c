#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int getRandPick();
void listOptions();
char* convertChoiceToString(int);
int getWinner(int, int);

int main() {

    bool quit = false;
    int aiPickInt = 0;
    int userPickInt = 0;
    int winner = 0;
    char *userPickString;
    char *aiPickString;
    char playAgain = 'y';

    while(!quit) {

        listOptions();
        scanf("%d", &userPickInt);

        if(userPickInt < 1 || userPickInt > 3){
            printf("INVALID OPTION\n");
            continue;
        }

        aiPickInt = getRandPick();
        winner = getWinner(userPickInt, aiPickInt);

        userPickString = convertChoiceToString(userPickInt);
        aiPickString = convertChoiceToString(aiPickInt);

        printf("\n");
        printf("You chose %s\n", userPickString);
        printf("AI chose %s\n", aiPickString);

        switch(winner) {
            case 0:
                printf("It's a draw!\n");
                break;

            case 1:
                printf("You win!\n");
                break;

            case 2:
                printf("You lose.\n");
                break;
            default:
                printf("Something went wrong :(\n");
                break;
        }

        printf("\n");
        printf("Do you want to play again? (y/n) ");
        do {
            scanf("%c", &playAgain);
        } while(playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N');



        free(userPickString);
        free(aiPickString);

        switch(playAgain) {
            case 'y':
            case 'Y':
                quit = false;
                break;
            case 'n':
            case 'N':
                quit = true;
                break;
            default:
                break;
        }
    }

    return 0;
}

int getRandPick() {

    srand(time(0));

    return (rand() % 3) + 1;
}

void listOptions() {
    printf("\n");
    printf("Choose one of the below options and press [ENTER]\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
}

char* convertChoiceToString(int choice) {
    char *word;
    switch(choice) {
        case 1:
            word = (char*)malloc(sizeof(char) * 5);
            strncpy(word, "Rock\0", 5);
            break;
        case 2:
            word = (char*)malloc(sizeof(char) * 6);
            strncpy(word, "Paper\0", 6);
            break;
        case 3:
            word = (char*)malloc(sizeof(char) * 9);
            strncpy(word, "Scissors\0", 9);
            break;
        default:
            break;

        return word;
    }
}

/*
* 0 = draw
* 1 = user wins
* 2 = ai wins
*/
int getWinner(int userChoice, int aiChoice) {

    if(userChoice == aiChoice) {
        return 0;
    }

    if(userChoice == 1 && aiChoice == 3) {
        //User chose Rock, AI choise Scissors
        return 1;
    }
    else if(userChoice == 2 && aiChoice == 1) {
        //User chose Paper, AI chose Rock
        return 1;
    }
    else if(userChoice == 3 && aiChoice == 2) {
        //User chose Scissors, AI chose Paper
        return 1;
    }

    return 2;
}