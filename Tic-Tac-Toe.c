#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void displayBoard(char board[]);
void firstpage();
void secondpage();
int rangeCorrect(int cell);
int cellIsEmpty(int cell, char board[]);
int three(char turn, char board[]);
int threeInARow(char turn, char board[]);
int threeInAColumn(char turn, char board[]);
int threeInADiagonal(char turn, char board[]);
int check(char board[]);

struct NODE
{
   int moveNumber;
   char board[9];
   struct NODE *nextPtr;
};

typedef struct NODE Node;
void displayList( Node *head);
int second=0,first=0,d,e=1,f[9],y,w=0;
char a[20],b[20],name[20];

int main()
{
    int a1=0,a2=0;
    while(e==1)
	{
	    char board[9];
        for(int i = 0; i < 9; i++)
            board[i] = ' ';

        Node *head = NULL;
        Node *tempPtr;
        int moveNumber = 0;
        char turn='X';
        int cell ;
        if(first==0)
            firstpage();
        if(second==0)
            secondpage();
        displayBoard(board);
        while(moveNumber < 9)
        {
            displayList(head);
            printf("           Move number: %d\n",moveNumber);
            printf("     *************************");
            printf("\n\n");
            printf( "TURN: %s(%c) make your move(1 to 9): \n",name,turn);

            if(d==1)
            scanf("%d",&cell);
            else
            {
                if(turn=='X')
                    scanf("%d",&cell);
                else
                {
                    int a=check(board);
                    if(a!=9)
                        cell=a+1;
                    else
                    {
                        int i,j;
                        srand(time(0));
                        for(i=0;i<5;i++)
                        {
                            label2:cell=rand()%9+1;
                            goto label1;
                        }
                    }
                }
            }
            label1:if(rangeCorrect(cell))
            {
                if(cellIsEmpty(cell-1, board))
                {
                    board[cell-1] = turn;
                    if(three(turn, board))
                    {
                        displayBoard(board);
                        printf("Congratulations player %s(%c) You win!!\n",name,turn);
                        if(turn=='X')
                            a1++;
                        else
                            a2++;
                        printf("        SCORES==>     %s(X)=%d \n                      %s(O)=%d\n",a,a1,b,a2);
                        strcpy(name,a);
                        goto label;
                    }
                    Node *tempptr;
                    tempPtr = (Node*)malloc(sizeof(Node));
                    tempPtr->moveNumber = moveNumber;
                    for(int i=0;i<9;i++)
					tempPtr->board[i]=board[i];
                    tempPtr->nextPtr = head;
                    head = tempPtr;
                    moveNumber++;
                    if(turn == 'X')
                    {
                        turn = 'O';
                        strcpy(name,b);
                    }
                    else
                    {
                        turn = 'X';
                        strcpy(name,a);
                    }
                }
                else
                    if(d==2&&turn=='O')
                        goto label2;
                    else
                    printf( "Sorry...cell %d has already been used, try again:\n ", cell);
            }
            else
                printf( "Sorry...cell %d is outside the range 1-9, try again: \n",cell);
        }
        displayBoard(board);
        printf("Game Ended: No Winners\n");
        label:printf("Want to play again(1/0)\n");
              scanf("%d",&e);
              system("cls");
	}
    return 1;
}

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
    scanf("%d",&d);
    system("cls");
    first=1;
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
    scanf("%s",a);
    if(d==2)
    {
        printf("Player 2(O)\nComputer\n");
        strcpy(b,"Computer");
    }
    else
    {
        printf("Enter name of player 2(O): \n");
        scanf("%s",b);
    }
    strcpy(name,a);
    second=1;
}
void displayList( Node *head)
{
    Node *tempPtr = head;
    if(tempPtr != NULL)
        displayBoard(tempPtr->board);
    printf("\n");
}

void displayBoard(char board[])
{
	printf("       _____   _____   _____ \n");
	printf("      |     | |     | |     | \n");
	printf("      |  %c  | |  %c  | |  %c  |\n",board[0],board[1],board[2]);
    printf("      |_____| |_____| |_____| \n");
	printf("       _____   _____   _____ \n");
	printf("      |     | |     | |     | \n");
	printf("      |  %c  | |  %c  | |  %c  |\n",board[3],board[4],board[5]);
	printf("      |_____| |_____| |_____| \n");
	printf("       _____   _____   _____ \n");
	printf("      |     | |     | |     | \n");
	printf("      |  %c  | |  %c  | |  %c  |\n",board[6],board[7],board[8]);
	printf("      |_____| |_____| |_____| \n");
}

int rangeCorrect(int cell)
{
    if( cell <= 9 &&cell >= 1)
		return 1;
	else
		return 0;
}

int cellIsEmpty(int cell, char  board[])
{
	if(board[cell]!=' ')
		return 0;
	else
		return 1;
}

int three(char turn, char board[])
{
	if(threeInARow(turn, board) || threeInAColumn(turn,board) || threeInADiagonal(turn,board))
		return 1;
	else
		return 0;
}

int threeInARow(char turn, char board[])
{
	if((board[0] == turn && board[1] == turn && board[2] == turn) ||
	   (board[3] == turn && board[4] == turn && board[5] == turn) ||
	   (board[6] == turn && board[7] == turn && board[8] == turn))
	   return 1;
	else
		return 0;
}

int threeInAColumn(char turn, char board[])
{
	if((board[0] == turn && board[3] == turn && board[6] == turn) ||
	   (board[1] == turn && board[4] == turn && board[7] == turn) ||
	   (board[2] == turn && board[5] == turn && board[8] == turn))
	   return 1;
	else
		return 0;
}

int threeInADiagonal(char turn, char board[])
{
	if((board[0]==turn && board[4]==turn && board[8] == turn) ||(board[2] == turn && board[4] == turn && board[6] == turn))
	   return 1;
	else
		return 0;
}
int check(char board[])
{
    int flag[9],z=0;

    if(board[0]=='X' &&board[1]=='X' )
        {flag[z]=2;z++;}
    else if(board[1]=='X' &&board[2]=='X')
        {flag[z]=0;z++;}
    else if(board[0]=='X' &&board[2]=='X')
        {flag[z]=1;z++;}
    else if(board[3]=='X' &&board[4]=='X')
        {flag[z]=5;z++;}
    else if(board[4]=='X' &&board[5]=='X')
        {flag[z]=3;z++;}
    else if(board[3]=='X' &&board[5]=='X')
        {flag[z]=4;z++;}
    else if(board[6]=='X' &&board[7]=='X')
        {flag[z]=8;z++;}
    else if(board[7]=='X' &&board[8]=='X')
        {flag[z]=6;z++;}
    else if(board[6]=='X' &&board[8]=='X')
        {flag[z]=7;z++;}
    else if(board[0]=='X' &&board[3]=='X')
        {flag[z]=6;z++;}
    else if(board[3]=='X' &&board[6]=='X')
        {flag[z]=0;z++;}
    else if(board[0]=='X' &&board[6]=='X')
        {flag[z]=3;z++;}
    else if(board[1]=='X' &&board[4]=='X')
        {flag[z]=7;z++;}
    else if(board[4]=='X' &&board[7]=='X')
        {flag[z]=1;z++;}
    else if(board[1]=='X' &&board[7]=='X')
        {flag[z]=4;z++;}
    else if(board[2]=='X' &&board[5]=='X')
        {flag[z]=8;z++;}
    else if(board[5]=='X' &&board[8]=='X')
        {flag[z]=2;z++;}
    else if(board[2]=='X' &&board[8]=='X')
        {flag[z]=5;z++;}
    else if(board[0]=='X' &&board[4]=='X')
        {flag[z]=8;z++;}
    else if(board[4]=='X' &&board[8]=='X')
        {flag[z]=0;z++;}
    else if(board[0]=='X' &&board[8]=='X')
        {flag[z]=4;z++;}
    else if(board[2]=='X' &&board[4]=='X')
        {flag[z]=6;z++;}
    else if(board[4]=='X'&&board[6]=='X')
        {flag[z]=2;z++;}
    else if(board[2]=='X'&&board[6]=='X')
        {flag[z]=4;z++;
        if(y!=0)
        {f[w]=y;w++;}
        for(int i=0;i<z;i++)
        {
            for(int j=0;j<z;j++)
            {
                if(flag[i]!=f[j])
                {
                    y=flag[i];
                    return y;
                }
            }
        }

        }
    else
        return 9;
}
