#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MINE_COUNT 10


void setboard(char board[ROWS][COLS], int rows, int cols, char set);//��ʼ������

void displayboard(char board[ROWS][COLS], int row, int col);//չʾ����

void laymines(char reality[ROWS][COLS], int row, int col);//����

void MineClearance(char reality[ROWS][COLS], char display[ROWS][COLS], int count);//ɨ��