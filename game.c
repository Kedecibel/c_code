#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitBoard(char(* p)[COLS], int row, int col, char a)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			*(*(p + i) + j )= a;
		}
	}
}

void PrintBoard(char(* p)[COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----------扫雷游戏-----------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= col; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= row; j++)
		{
			printf("%c ", *(*(p + i) + j));
		}
		printf("\n");
	}
	printf("-----------扫雷游戏-----------\n");
}

void SetMine(char(* p)[COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = Easy_count;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (*(*(p+x)+y) == '0')
		{
			*(*(p + x) + y) = '1';
			count--;
		}
	}
}

static int MineNum(char(*mine)[COLS], int x, int y)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (*(*(mine + x+i ) + y+j ) == '1')
				count++;
		}
	}
	return count;
}
void FindMine(char(* mine)[COLS], char(* show)[COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count =0;
	while (count< ROW * COL - Easy_count)
	{
		printf("请输入坐标：\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (*(*(mine + x) + y) == '1')
			{
				printf("BOOM! GAME OVER！\n");
				break;
			}
			else if (*(*(mine + x) + y) == '0')
			{
				int count= MineNum(mine, x, y);
				*(*(show + x) + y) = '0' + count;
				count++;
				PrintBoard(show, row, col);
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}
	if (count == ROW * COL - Easy_count)
	{
		printf("恭喜你，扫雷成功\n");
	}
}