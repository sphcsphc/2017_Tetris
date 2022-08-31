#include"Tetris_define.h"
#include"Tetris_extern.h"
#include"Tetris_function.h"
#include"Tetris_include.h"

int Collision_Check(Tetris t)
{
	int collision = 0;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (((t.cur_x + x) == 0) || ((t.cur_x + x) == WIDTH - 1) || ((t.cur_y + y) == HEIGHT - 1))
				collision = 1;
			else
				collision = tetris_gameboard[t.cur_y + y][t.cur_x + x];
			if ((tetris_blocks[t.current_block][t.rotation][y][x] == 1) && (collision == 1))
				return 1;
		}
	}
	return 0;
}

int Line_Check()
{
	int x = 0, y = 0, score = 0;

	for (y = 0; y < HEIGHT - 1; y++)
	{
		for (x = 1; x < WIDTH - 1; x++)
		{
			if (tetris_gameboard[y][x] == 0)
			{
				break;
			}
		}

		if (x == WIDTH - 1)
		{
			score += 10;

			GoToxy(6, y + 1);
			for (int i = 1; i < WIDTH - 1; i++)
			{
				printf("бр");
				Sleep(20);
			}
			GoToxy(6, y + 1);
			for (int i = 1; i < WIDTH - 1; i++)
			{
				printf("  ");
				Sleep(20);
			}

			for (int i = y; i > 0; i--)
			{
				for (int j = 1; j < WIDTH - 1; j++)
				{
					tetris_gameboard[i][j] = tetris_gameboard[i - 1][j];
				}
			}

			for (int i = 1; i < WIDTH - 1; i++)
			{
				tetris_gameboard[0][i] = 0;
			}
		}
	}
	return score;
}