#include <stdio.h>

int main() {
    int firstNum;
    int secondNum;
    int result;

    printf("Please enter the first number ");
    scanf("%d", &firstNum);

    printf("Please enter the second number ");
    scanf("%d", &secondNum);

    result = firstNum + secondNum;

    printf("%d + %d = %d\n", firstNum, secondNum, result);

    return 0;
}