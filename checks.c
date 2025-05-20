#include "checks.h"

int rangeCorrect(int cell)
{
    if (cell <= 9 && cell >= 1)
        return 1;
    else
        return 0;
}

int cellIsEmpty(int cell, char board[])
{
    if (board[cell] != ' ')
        return 0;
    else
        return 1;
}

int three(char turn, char board[])
{
    if (threeInARow(turn, board) || threeInAColumn(turn, board) || threeInADiagonal(turn, board))
        return 1;
    else
        return 0;
}

int threeInARow(char turn, char board[])
{
    if ((board[0] == turn && board[1] == turn && board[2] == turn) ||
        (board[3] == turn && board[4] == turn && board[5] == turn) ||
        (board[6] == turn && board[7] == turn && board[8] == turn))
        return 1;
    else
        return 0;
}

int threeInAColumn(char turn, char board[])
{
    if ((board[0] == turn && board[3] == turn && board[6] == turn) ||
        (board[1] == turn && board[4] == turn && board[7] == turn) ||
        (board[2] == turn && board[5] == turn && board[8] == turn))
        return 1;
    else
        return 0;
}

int threeInADiagonal(char turn, char board[])
{
    if ((board[0] == turn && board[4] == turn && board[8] == turn) || (board[2] == turn && board[4] == turn && board[6] == turn))
        return 1;
    else
        return 0;
}

int check(char board[])
{
    int flag[9], z = 0;

    if (board[0] == 'X' && board[1] == 'X')
    {
        flag[z] = 2;
        z++;
    }
    else if (board[1] == 'X' && board[2] == 'X')
    {
        flag[z] = 0;
        z++;
    }
    else if (board[0] == 'X' && board[2] == 'X')
    {
        flag[z] = 1;
        z++;
    }
    else if (board[3] == 'X' && board[4] == 'X')
    {
        flag[z] = 5;
        z++;
    }
    else if (board[4] == 'X' && board[5] == 'X')
    {
        flag[z] = 3;
        z++;
    }
    else if (board[3] == 'X' && board[5] == 'X')
    {
        flag[z] = 4;
        z++;
    }
    else if (board[6] == 'X' && board[7] == 'X')
    {
        flag[z] = 8;
        z++;
    }
    else if (board[7] == 'X' && board[8] == 'X')
    {
        flag[z] = 6;
        z++;
    }
    else if (board[6] == 'X' && board[8] == 'X')
    {
        flag[z] = 7;
        z++;
    }
    else if (board[0] == 'X' && board[3] == 'X')
    {
        flag[z] = 6;
        z++;
    }
    else if (board[3] == 'X' && board[6] == 'X')
    {
        flag[z] = 0;
        z++;
    }
    else if (board[0] == 'X' && board[6] == 'X')
    {
        flag[z] = 3;
        z++;
    }
    else if (board[1] == 'X' && board[4] == 'X')
    {
        flag[z] = 7;
        z++;
    }
    else if (board[4] == 'X' && board[7] == 'X')
    {
        flag[z] = 1;
        z++;
    }
    else if (board[1] == 'X' && board[7] == 'X')
    {
        flag[z] = 4;
        z++;
    }
    else if (board[2] == 'X' && board[5] == 'X')
    {
        flag[z] = 8;
        z++;
    }
    else if (board[5] == 'X' && board[8] == 'X')
    {
        flag[z] = 2;
        z++;
    }
    else if (board[2] == 'X' && board[8] == 'X')
    {
        flag[z] = 5;
        z++;
    }
    else if (board[0] == 'X' && board[4] == 'X')
    {
        flag[z] = 8;
        z++;
    }
    else if (board[4] == 'X' && board[8] == 'X')
    {
        flag[z] = 0;
        z++;
    }
    else if (board[0] == 'X' && board[8] == 'X')
    {
        flag[z] = 4;
        z++;
    }
    else if (board[2] == 'X' && board[4] == 'X')
    {
        flag[z] = 6;
        z++;
    }
    else if (board[4] == 'X' && board[6] == 'X')
    {
        flag[z] = 2;
        z++;
    }
    else if (board[2] == 'X' && board[6] == 'X')
    {
        flag[z] = 4;
        z++;
    }

    if (z != 0)
        return flag[0];
    else
        return 9;
}
