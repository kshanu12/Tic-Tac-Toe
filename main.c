#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int second = 0, first = 0, d, e = 1, f[9], y, w = 0;
char a[20], b[20], name[20];

#include "display.h"
#include "pages.h"
#include "checks.h"
#include "node.h"

int main()
{
    int a1 = 0, a2 = 0;
    while (e == 1)
    {
        char board[9];
        for (int i = 0; i < 9; i++)
            board[i] = ' ';

        Node *head = NULL;
        Node *tempPtr;
        int moveNumber = 0;
        char turn = 'X';
        int cell;

        if (first == 0)
            firstpage();
        if (second == 0)
            secondpage();
        displayBoard(board);
        while (moveNumber < 9)
        {
            displayList(head);
            printf("           Move number: %d\n", moveNumber);
            printf("     *************************");
            printf("\n\n");
            printf("TURN: %s(%c) make your move(1 to 9): \n", name, turn);

            if (d == 1)
                scanf("%d", &cell);
            else
            {
                if (turn == 'X')
                    scanf("%d", &cell);
                else
                {
                    int a = check(board);
                    if (a != 9)
                        cell = a + 1;
                    else
                    {
                        int i, j;
                        srand(time(0));
                        for (i = 0; i < 5; i++)
                        {
                        label2:
                            cell = rand() % 9 + 1;
                            goto label1;
                        }
                    }
                }
            }
        label1:
            if (rangeCorrect(cell))
            {
                if (cellIsEmpty(cell - 1, board))
                {
                    board[cell - 1] = turn;
                    if (three(turn, board))
                    {
                        displayBoard(board);
                        printf("Congratulations player %s(%c) You win!!\n", name, turn);
                        if (turn == 'X')
                            a1++;
                        else
                            a2++;
                        printf("        SCORES==>     %s(X)=%d \n                      %s(O)=%d\n", a, a1, b, a2);
                        strcpy(name, a);
                        goto label;
                    }
                    Node *tempptr;
                    tempPtr = (Node *)malloc(sizeof(Node));
                    tempPtr->moveNumber = moveNumber;
                    for (int i = 0; i < 9; i++)
                        tempPtr->board[i] = board[i];
                    tempPtr->nextPtr = head;
                    head = tempPtr;
                    moveNumber++;
                    if (turn == 'X')
                    {
                        turn = 'O';
                        strcpy(name, b);
                    }
                    else
                    {
                        turn = 'X';
                        strcpy(name, a);
                    }
                }
                else if (d == 2 && turn == 'O')
                    goto label2;
                else
                    printf("Sorry...cell %d has already been used, try again:\n ", cell);
            }
            else
                printf("Sorry...cell %d is outside the range 1-9, try again: \n", cell);
        }
        displayBoard(board);
        printf("Game Ended: No Winners\n");
    label:
        printf("Want to play again(1/0)\n");
        scanf("%d", &e);
        system("cls");
    }
    return 1;
}
