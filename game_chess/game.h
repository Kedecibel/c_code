#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//定义行列
#define ROW 3
#define COL 3

//函数声明
//初始化棋盘
void Intiboard(char board[ROW][COL], int row, int col);
//打印棋盘
void Printboard(char board[ROW][COL], int row, int col);
//玩家走
void Playermove(char board[ROW][COL], int row, int col);
//电脑走
void Computermove(char board[ROW][COL], int row, int col);
//判断输赢
char Iswin(char board[ROW][COL], int row, int col);