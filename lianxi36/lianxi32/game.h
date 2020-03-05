#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#define  ROW  9
#define  COL  9
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define  EASY_COUNT  10

#define  ROWS  ROW+2
#define  COLS  COL+2

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char arr[ROWS][COLS], int row, int col);
void Setmine(char arr[ROWS][COLS], int row, int col);
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int  Getminecount(char mine[ROWS][COLS], int x,int y);
#endif // _GAME_H_
