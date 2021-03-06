#define _CRT_SECURE_NO_WARNINGS 

#include "game.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}

}


void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void Setmine(char arr[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;//(雷的个数)

	while (count)
	{
		int x = rand() % row+1;
		int y = rand() % col+1;//+1

		if (arr[x][y] = '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}


void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row * col - EASY_COUNT)
	{
		printf("请输入坐标——>:\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1&& y <= col)
		{
			if (mine[x][y] == '1')//== 一定记得
			{
				printf("很遗憾，你被炸死了！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = Getminecount(mine,x,y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;

			}
		}
		else
		{
			printf("输入有误，请重新输入——>:\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
	}
}


int  Getminecount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';

}

