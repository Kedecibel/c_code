#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("***********************************\n");
	printf("*********** 1.��ʼ��Ϸ ************\n");
	printf("*********** 0.�˳���Ϸ ************\n");
	printf("***********************************\n");
}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');
	//PrintBoard(mine, ROW, COL);
	InitBoard(show, ROWS, COLS, '*');
	//PrintBoard(show, ROW, COL);
	SetMine(mine, ROW, COL);
	PrintBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
	PrintBoard(mine, ROW, COL);
}
int main()
{
	int function = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("�����룺\n");
		scanf("%d", &function);
		switch (function)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("���������룺\n");
			break;
		}
	} while (function);

	return 0;
}