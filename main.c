#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;

int checkForWin();
void displayBoard();
void markBoard(char mark);

int main()
{
    int gameStatus;

    char mark;

    player = 1;

    do
    {
        displayBoard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        markBoard(mark);

        gameStatus = checkForWin();

        player++;

    } while (gameStatus == -1);

    if (gameStatus == 1)
        printf("==>\aPlayer %d wins ", --player);
    else
        printf("==>\aGame draw");

    return 0;
}

/************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
0 FOR GAME IS OVER AND NO RESULT
************************************/
int checkForWin()
{
    int returnValue = 0;

    if (square[1] == square[2] && square[2] == square[3])
        returnValue = 1;
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;
    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;
    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;
    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;
    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;
    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;
    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' &&
        square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}


/********************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
**********************************************************/
void displayBoard()
{
    system("clear");

    printf("\n\tTic Tac Toe Game\n\n");

    printf("Player 1 (X)   -   Player 2 (O)\n\n\n");

    printf("_______|______|______\n");
    printf("       |      |       \n");
    printf("    %c  |   %c  |   %c  \n", square[1],square[2],square[3]);

    printf("_______|______|______\n");

    printf("    %c  |   %c  |   %c  \n", square[4],square[5],square[6]);

    printf("_______|______|______\n");

    printf("    %c  |   %c  |   %c  \n", square[7],square[8],square[9]);

    printf("       |      |       \n");
    printf("_______|______|______\n");
}

/********************************************
set the board with the correct character,
X or O in the correct spot in the array.
*********************************************/
void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;
    else if (choice == 2 && square[2] == '2')
        square[2] = mark;
    else if (choice == 3 && square[3] == '3')
        square[3] = mark;
    else if (choice == 4 && square[4] == '4')
        square[4] = mark;
    else if (choice == 5 && square[5] == '5')
        square[5] = mark;
    else if (choice == 6 && square[6] == '6')
        square[6] = mark;
    else if (choice == 7 && square[7] == '7')
        square[7] = mark;
    else if (choice == 8 && square[8] == '8')
        square[8] = mark;
    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("wrong move");

        player--;
        //getch();
    }
}
