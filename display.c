#include <stdio.h>
#include "display.h"

void displayBoard(char board[])
{
    printf("       _____   _____   _____ \n");
    printf("      |     | |     | |     | \n");
    printf("      |  %c  | |  %c  | |  %c  |\n", board[0], board[1], board[2]);
    printf("      |_____| |_____| |_____| \n");
    printf("       _____   _____   _____ \n");
    printf("      |     | |     | |     | \n");
    printf("      |  %c  | |  %c  | |  %c  |\n", board[3], board[4], board[5]);
    printf("      |_____| |_____| |_____| \n");
    printf("       _____   _____   _____ \n");
    printf("      |     | |     | |     | \n");
    printf("      |  %c  | |  %c  | |  %c  |\n", board[6], board[7], board[8]);
    printf("      |_____| |_____| |_____| \n");
}

void displayList(struct NODE *head)
{
    struct NODE *tempPtr = head;
    if (tempPtr != NULL)
        displayBoard(tempPtr->board);
    printf("\n");
}