#include "game.h"


void Menu()
{
	printf("------------------------------\n");
	printf("--------- 1.Begin ------------\n");
	printf("--------- 0.Logout------------\n");
	printf("------------------------------\n");
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------Mine Clearance----------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------Mine Clearance----------\n");
}

void CreateMine(char board[ROWS][COLS], int row, int col)
{
	int count = NUMBER_MINES;
	while(count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

static int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
 }


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	// give the coordinate of your choice
	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row*col - NUMBER_MINES)
	{
		printf("please give your coordinate of your choice:");
		scanf("%d %d", &x, &y);

		//judge the legitimacy of the coordinate
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//judge the coordinate whether have the mine
			//yes, game over; no, give the information about the mines
			if (mine[x][y] == '1')
			{
				printf("unfortunately, you meet the mine and game is over.\n");
				PrintBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int ret = GetMineCount(mine, x, y);
				show[x][y] = ret + '0';
				PrintBoard(show, ROW, COL);
				win++;
			}

		}
		else
		{
			printf("the coordinate is illegal!\n");
		}
	}
	if (win = row * col - NUMBER_MINES)
	{
		printf("Victory!\n");
		PrintBoard(mine, ROW, COL);
	}
}