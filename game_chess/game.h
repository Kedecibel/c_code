#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//��������
#define ROW 3
#define COL 3

//��������
//��ʼ������
void Intiboard(char board[ROW][COL], int row, int col);
//��ӡ����
void Printboard(char board[ROW][COL], int row, int col);
//�����
void Playermove(char board[ROW][COL], int row, int col);
//������
void Computermove(char board[ROW][COL], int row, int col);
//�ж���Ӯ
char Iswin(char board[ROW][COL], int row, int col);