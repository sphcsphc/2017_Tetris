#include"Tetris_define.h"
#include"Tetris_extern.h"
#include"Tetris_function.h"
#include"Tetris_include.h"

void GoToxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}