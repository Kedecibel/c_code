#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("************************\n");
	printf("*******1.开始游戏*******\n");
	printf("*******0.退出游戏*******\n");
	printf("************************\n");

}

void game_chess()
{
	char board[ROW][COL];
	Intiboard(board, ROW, COL);
	Printboard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//玩家下棋
		Playermove(board, ROW, COL);
		Printboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if ('C' != ret)
			break;
		//电脑下棋
		Computermove(board, ROW, COL);
		Printboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if ('C' != ret)
			break;
	}
	if ('*' == ret)
	{
		printf("玩家赢了\n");
	}
	else if ('#' == ret)
	{
		printf("电脑赢了\n");
	}
	else 
	{
		printf("平局\n");
	}
	Printboard(board, ROW, COL);
}

int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game_chess();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	} while (a);
}