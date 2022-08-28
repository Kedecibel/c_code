#include "game.h"

void Intiboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}

void Printboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void Playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走>\n");
	printf("请输入坐标:\n");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x>=1 && x <= row && y>=1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标非法，请重新输入>:\n");
		}
		else
			printf("坐标非法，请重新输入>:\n");
	}
}

void Computermove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int i_more = row - 3;
	int j_more = col - 3;
	//判断行
	//行列数为3
	/*for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}*/
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	//判断列
	//行列数为3
	/*for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}*/
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row - 2; i++)
		{
			if (board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	//判断对角线
	for (i = 0; i <= i_more; i++)
	{
		for (j = 0; j <= j_more; j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] != ' ')
				return board[i][j];
			if (board[i][j + 2] == board[i + 1][j + 1] && board[i][j + 2] == board[i + 2][j] && board[i][j + 2] != ' ')
				return board[i][j + 2];
		}
	}
	//行列数为3
	/*if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[2][0] != ' ')
	{
		return board[0][2];
	}*/
	//判断平局
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (' ' == board[i][j])
				return 'C';
		}
	}
	return 'Q';

}