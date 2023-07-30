#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void setboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}//初始化棋盘


void displayboard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 1; i <= col; i++)
	{
		printf("——-");
	}
	printf("\n");//分割线

	printf("0  ");
	for (int i = 1; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("x\n");
	printf("\n");//空一行

	for (int i = 1; i <= row; i++)
	{
		printf("%d  ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}//游戏区域

	printf("y\n");

	for (int i = 1; i <= col; i++)
	{
		printf("——-");
	}
	printf("\n");//分割线

}//展示棋盘


void laymines(char reality[ROWS][COLS], int row, int col)
{
	int count = MINE_COUNT;
	while (count)
	{
		int x = rand() % col + 1;
		int y = rand() % row + 1;
		if (reality[y][x] == '0')
		{
			reality[y][x] = '1';
			count--;
		}
	}
}//埋雷

int GetMineCount(char reality[ROWS][COLS], int x, int y)
{
	return  (reality[y - 1][x - 1] + reality[y - 1][x] + reality[y - 1][x + 1] + reality[y][x - 1] + reality[y][x + 1] + reality[y + 1][x - 1] + reality[y + 1][x] + reality[y + 1][x + 1] - 8 * '0');
}//计算周围雷数


void chain(char display[ROWS][COLS],char reality[ROWS][COLS] ,int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (display[i][j] == '0')
			{
				display[i-1][j-1] = GetMineCount(reality, j-1, i-1) + '0';
				display[i-1][j] = GetMineCount(reality, j, i-1) + '0';
				display[i-1][j+1] = GetMineCount(reality, j+1, i-1) + '0';
				display[i][j-1] = GetMineCount(reality, j-1, i) + '0';
				display[i][j+1] = GetMineCount(reality, j+1, i) + '0';
				display[i+1][j-1] = GetMineCount(reality, j-1, i+1) + '0';
				display[i+1][j] = GetMineCount(reality, j, i+1) + '0';
				display[i+1][j+1] = GetMineCount(reality, j+1, i+1) + '0';
			}
		}
	}
}//连锁探雷

int victory(char display[ROWS][COLS], int row,int col)
{
	int win = 0;
	for (int i = 1; i <= row; i++)
	{
		for(int j = 1;j <= col;j++)
			if (display[i][j] == '*' || display[i][j] == '#')
			{
				win++;
			}
	}
	if (win == MINE_COUNT)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}//判断是否获胜


void MineClearance(char reality[ROWS][COLS],char display[ROWS][COLS],int count)
{
	printf("开始排雷！本轮游戏共有%d个雷！\n", MINE_COUNT);
	int x = 0;
	int y = 0;
	int i = 0;//记录次数
	int win = 0;
	count = MINE_COUNT;
	do
	{
		printf("输入坐标排雷（x y）:>>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= COL && y >= 1 && y <= ROW)
		{
			i++;
			if (reality[y][x] == '1')
			{
				system("cls");
				printf("踩到雷了！挑战失败！\n");
				reality[y][x] = 'P';
				break;
			}
			else
			{
				display[y][x] = GetMineCount(reality, x, y) + '0';
				system("cls");
				chain(display,reality, ROW, COL);//连锁
				displayboard(reality, ROW, COL);//测试使用
				displayboard(display, ROW, COL);//展示棋盘
			}
		}
		else
		{
			printf("非法输入，请重试！\n");
		}

		win = victory(display, ROW, COL);
		if (win == 1)
		{
			system("cls");
			printf("排雷成功！！！\n");
			break;
		}
		else
		{
			win = 0;
		}
		} while (1);
	displayboard(reality, ROW, COL);
	printf("你一共尝试了%d次\n", i);
}
