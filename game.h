//Difinition
#define ROW 3
#define COL 3//Easy to modify the size of the chessboard
#define COLOR_BLUE "\033[34m"//Blue font

#include<stdio.h>
#include<stdlib.h>//rand function call
#include<time.h>//time function call

//Initialize the chessboard
void InitBoard(char board[ROW][COL], int row, int col);

//Print chessboard
void DisplayBoard(char board[ROW][COL], int row, int col);

//Player plays chess
void PlayerMove(char board[ROW][COL], int row, int col);

//Computer plays chess
void ComputerMove(char board[ROW][COL], int row, int col);

//Judge winning or losing
//Player wins--*
//Computer wins--#
//Continue----C
//Draw----Q
char IsWin(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);
