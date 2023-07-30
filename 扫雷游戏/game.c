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
}//��ʼ������


void displayboard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 1; i <= col; i++)
	{
		printf("����-");
	}
	printf("\n");//�ָ���

	printf("0  ");
	for (int i = 1; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("x\n");
	printf("\n");//��һ��

	for (int i = 1; i <= row; i++)
	{
		printf("%d  ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}//��Ϸ����

	printf("y\n");

	for (int i = 1; i <= col; i++)
	{
		printf("����-");
	}
	printf("\n");//�ָ���

}//չʾ����


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
}//����

int GetMineCount(char reality[ROWS][COLS], int x, int y)
{
	return  (reality[y - 1][x - 1] + reality[y - 1][x] + reality[y - 1][x + 1] + reality[y][x - 1] + reality[y][x + 1] + reality[y + 1][x - 1] + reality[y + 1][x] + reality[y + 1][x + 1] - 8 * '0');
}

void MineClearance(char reality[ROWS][COLS],char display[ROWS][COLS],int count)
{
	printf("��ʼ���ף�\n");
	int x = 0;
	int y = 0;
	int i = 0;//��¼����
	int win = 0;
	count = MINE_COUNT;
	do
	{
		printf("�����������ף�x y��:>>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= COL && y >= 1 && y <= ROW)
		{
			i++;
			if (reality[y][x] == '1')
			{
				system("cls");
				printf("�ȵ����ˣ���սʧ�ܣ�\n");
				reality[y][x] = 'P';
				break;
			}
			else
			{
				display[y][x] = GetMineCount(reality, x, y) + '0';
				system("cls");
				//displayboard(reality, ROW, COL);//����ʹ��
				displayboard(display, ROW, COL);//չʾ����
				win++;
			}
		}
		else
		{
			printf("�Ƿ����룬�����ԣ�\n");
		}
		if (ROW * COL - MINE_COUNT == win)
		{
			system("cls");
			printf("���׳ɹ�������\n");
			break;
		}
		} while (1);
	displayboard(reality, ROW, COL);
	printf("��һ��������%d��\n", i);
}