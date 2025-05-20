#ifndef NODE_H
#define NODE_H

typedef struct NODE
{
    int moveNumber;
    char board[9];
    struct NODE *nextPtr;
} Node;

#endif
