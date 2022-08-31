#include"Tetris_define.h"
#include"Tetris_extern.h"
#include"Tetris_function.h"
#include"Tetris_include.h"

void Blocks(Tetris*t)
{
	int block = rand() % 7;
	t->cur_x = t->abs_x;
	t->cur_y = t->abs_y;
	t->rotation = 0;

	if (t->current_block != -1)
	{
		t->current_block = t->next_block;
		t->next_block = block;
	}
	else
	{
		t->current_block = block;
		block = rand() % 7;
		t->next_block = block;
	}
}

void GameBoard()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if ((x == 0) || (x == WIDTH - 1))
				tetris_gameboard[y][x] = 3;
			else if (y == HEIGHT - 1)
				tetris_gameboard[y][x] = 3;
			else
				tetris_gameboard[y][x] = 0;
		}
	}
}