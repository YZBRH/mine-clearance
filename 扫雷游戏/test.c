#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void mune()
{
	printf("**********************\n");
	printf("********ɨ����Ϸ******\n");
	printf("**********************\n");
	printf("*******1.��ʼ��Ϸ*****\n");
	printf("*******2.�˳���Ϸ*****\n");
	printf("**********************\n");
}//���˵�

int PlayAgain()
{
	int i = 0;
	printf("��Ҫ��������(����1��ȷ�ϣ�������������ȡ��:>>");
	scanf("%d", &i);
	if (i == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void game()
{
	char display[ROWS][COLS];//չʾ�����
	char reality[ROWS][COLS];//�洢�׵��������

	setboard(display, ROWS, COLS, '*' );
	setboard(reality, ROWS, COLS, '0');//���̳�ʼ��

	laymines(reality, ROW, COL);//����


	displayboard(reality, ROW, COL);//����ʹ��
	displayboard(display, ROW, COL);//չʾ����

	MineClearance(reality, display, MINE_COUNT);//ɨ��



}//��Ϸ����


int main()
{
	int mune_number = 0;
	int a = 0;//����ѭ��
	srand((unsigned int)time(NULL));//���������Ԥ��
	do
	{
		system("cls");
		mune();
		printf("���������ѡ��:>>");
		scanf("%d", &mune_number);
		system("cls");
	    switch (mune_number)
		{
			case 1:
			{
				game();
				a = PlayAgain();
				break;
			}
			case 2:
			{
				break;
			}
			default:
			{
				system("cls");
				printf("��Ч���룬������\n");
				a = 1;
				break;
			}
		}
		if (a == 1)
		{
			a = 0;
			continue;
		}
		printf("��Ϸ���˳����ڴ��������´����\n");
		break;
	} while (1);

	return 0;
}