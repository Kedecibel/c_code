#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//���峣��
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define Easy_count 10

//��������
//��ʼ��
void InitBoard(char(* p)[COLS], int row, int col, char a);
//��ӡ
void PrintBoard(char(* p)[COLS], int row, int col);
//���õ���
void SetMine(char(* p)[COLS], int row, int col);
//����
void FindMine(char(*mine)[COLS], char(*show)[COLS], int row, int col);