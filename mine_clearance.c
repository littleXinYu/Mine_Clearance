#include "game.h"

void game()
{
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	//initialize the board
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//print the board
	//PrintBoard(mine, ROW, COL);
	PrintBoard(show, ROW, COL);

	//creat mines in the board
	CreateMine(mine, ROW, COL);

	//print the mineboard
	//PrintBoard(mine, ROW, COL);
	//PrintBoard(show, ROW, COL);

	//find the Mine
	FindMine(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));

	do
	{
		Menu();
		printf("please give your choice:");
		scanf("%d" , &input);
		switch (input)
		{
		case 1:
			//printf("game is ready\n");
			game();
			break;
		case 0:
			break;
		default:
			printf("something goes wrong, please give your choice again!\n");
		}
	} while (input);

	printf("logout successfully\n");

	return 0;
}