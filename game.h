#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//定义常量
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define Easy_count 10

//函数定义
//初始化
void InitBoard(char(* p)[COLS], int row, int col, char a);
//打印
void PrintBoard(char(* p)[COLS], int row, int col);
//布置地雷
void SetMine(char(* p)[COLS], int row, int col);
//排雷
void FindMine(char(*mine)[COLS], char(*show)[COLS], int row, int col);