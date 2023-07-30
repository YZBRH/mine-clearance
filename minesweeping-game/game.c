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
}//������Χ����


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
}//����̽��

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
}//�ж��Ƿ��ʤ


void MineClearance(char reality[ROWS][COLS],char display[ROWS][COLS],int count)
{
	printf("��ʼ���ף�������Ϸ����%d���ף�\n", MINE_COUNT);
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
				chain(display,reality, ROW, COL);//����
				displayboard(reality, ROW, COL);//����ʹ��
				displayboard(display, ROW, COL);//չʾ����
			}
		}
		else
		{
			printf("�Ƿ����룬�����ԣ�\n");
		}

		win = victory(display, ROW, COL);
		if (win == 1)
		{
			system("cls");
			printf("���׳ɹ�������\n");
			break;
		}
		else
		{
			win = 0;
		}
		} while (1);
	displayboard(reality, ROW, COL);
	printf("��һ��������%d��\n", i);
}
