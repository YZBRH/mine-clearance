#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void mune()
{
	printf("**********************\n");
	printf("********扫雷游戏******\n");
	printf("**********************\n");
	printf("*******1.开始游戏*****\n");
	printf("*******2.退出游戏*****\n");
	printf("**********************\n");
}//主菜单

int PlayAgain()
{
	int i = 0;
	printf("还要继续玩吗？(输入1以确认，输入其他数字取消:>>");
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
	char display[ROWS][COLS];//展示给玩家
	char reality[ROWS][COLS];//存储雷的相关数据

	setboard(display, ROWS, COLS, '*' );
	setboard(reality, ROWS, COLS, '0');//棋盘初始化

	laymines(reality, ROW, COL);//埋雷


	displayboard(reality, ROW, COL);//测试使用
	displayboard(display, ROW, COL);//展示棋盘

	MineClearance(reality, display, MINE_COUNT);//扫雷



}//游戏主体


int main()
{
	int mune_number = 0;
	int a = 0;//控制循环
	srand((unsigned int)time(NULL));//随机数生成预备
	do
	{
		system("cls");
		mune();
		printf("请做出你的选择:>>");
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
				printf("无效输入，请重试\n");
				a = 1;
				break;
			}
		}
		if (a == 1)
		{
			a = 0;
			continue;
		}
		printf("游戏已退出，期待与您的下次相逢\n");
		break;
	} while (1);

	return 0;
}