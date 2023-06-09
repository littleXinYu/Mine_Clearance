#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS   ROW+2
#define COLS   COL+2

#define NUMBER_MINES 10

void Menu();

void InitBoard( char board[ROWS][COLS] , int rows , int cols  );

void PrintBoard(char board[ROWS][COLS], int row, int col);

void CreateMine(char board[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);