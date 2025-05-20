#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pages.h"

extern int d, first, second;
extern char a[], b[], name[];

void firstpage()
{
    printf("            !!!WELCOME TO TIC TAC TOE!!!\n\n");
    printf("             ___________________________\n");
    printf("            |                           |\n");
    printf("            |       1.MULTIPLAYER       |\n");
    printf("            |___________________________|\n");
    printf("             ___________________________\n");
    printf("            |                           |\n");
    printf("            |       2.SINGLEPLAYER      |\n");
    printf("            |___________________________|\n\n");
    printf("Enter your choice: \n");
    scanf("%d", &d);
    system("cls");
    first = 1;
}

void secondpage()
{
    printf("            !!!WELCOME TO TIC TAC TOE!!!\n\n\n");
    printf("                   !!INSTRUCTION!!\n  ");
    printf("    The goal of the game is to connect number symbols \n");
    printf("            indicated on the upper panel\n");
    printf("                    _____ _____ _____\n");
    printf("                   |     |     |     |\n");
    printf("                   |  X  |  X  |  X  |\n");
    printf("                   |_____|_____|_____|\n");
    printf("You can connect symbols in any direction row, column or diagonal\n");
    printf("     _____ _____ _____               _____ _____ _____\n");
    printf("    |     |     |     |             |     |     |     |\n");
    printf("    |  X  |     |  X  |             |  X  |  O  |  X  |\n");
    printf("    |_____|_____|_____|             |_____|_____|_____|\n");
    printf("     _____ _____ _____               _____ _____ _____\n");
    printf("    |     |     |     |             |     |     |     |\n");
    printf("    |  O  |  O  |  O  |             |     |  O  |     |\n");
    printf("    |_____|_____|_____|             |_____|_____|_____|\n");
    printf("     _____ _____ _____               _____ _____ _____\n");
    printf("    |     |     |     |             |     |     |     |\n");
    printf("    |     |     |     |             |     |  O  |     |\n");
    printf("    |_____|_____|_____|             |_____|_____|_____|\n\n\n");
    printf("     _____ _____ _____               _____ _____ _____\n");
    printf("    |     |     |     |             |     |     |     |\n");
    printf("    |  O  |     |  X  |             |     |     |  O  |\n");
    printf("    |_____|_____|_____|             |_____|_____|_____|\n");
    printf("     _____ _____ _____               _____ _____ _____\n");
    printf("    |     |     |     |             |     |     |     |\n");
    printf("    |     |  O  |     |             |     |  O  |     |\n");
    printf("    |_____|_____|_____|             |_____|_____|_____|\n");
    printf("     _____ _____ _____               _____ _____ _____\n");
    printf("    |     |     |     |             |     |     |     |\n");
    printf("    |  X  |     |  O  |             |  O  |  X  |  X  |\n");
    printf("    |_____|_____|_____|             |_____|_____|_____|\n");
    system("pause");
    system("cls");
    printf("            !!!WELCOME TO TIC TAC TOE!!!\n\n\n");
    printf("Enter name of player 1(X): \n");
    scanf("%s", a);
    if (d == 2)
    {
        printf("Player 2(O)\nComputer\n");
        strcpy(b, "Computer");
    }
    else
    {
        printf("Enter name of player 2(O): \n");
        scanf("%s", b);
    }
    strcpy(name, a);
    second = 1;
}
