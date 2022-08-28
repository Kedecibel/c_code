#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("************************\n");
	printf("*******1.��ʼ��Ϸ*******\n");
	printf("*******0.�˳���Ϸ*******\n");
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
		//�������
		Playermove(board, ROW, COL);
		Printboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if ('C' != ret)
			break;
		//��������
		Computermove(board, ROW, COL);
		Printboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if ('C' != ret)
			break;
	}
	if ('*' == ret)
	{
		printf("���Ӯ��\n");
	}
	else if ('#' == ret)
	{
		printf("����Ӯ��\n");
	}
	else 
	{
		printf("ƽ��\n");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������\n");
			break;
		}
	} while (a);
}