#include"Tetris_define.h"
#include"Tetris_extern.h"
#include"Tetris_function.h"
#include"Tetris_include.h"

void Show_GameBoard(Tetris t)
{
	Show_Stage();
	Show_Score();
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			GoToxy((2 + j) * 2, i + 1);
			if (tetris_gameboard[i][j] == 0)
			{
				printf("  ");
			}
			else if (tetris_gameboard[i][j] == 1)
			{
				printf("■");
			}
			else if (tetris_gameboard[i][j] == 3)
			{
				printf("▣");
			}
			GoToxy(0, 0);
			printf("                                                 ");
		}
	}

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			GoToxy((x + t.cur_x) * 2 + 4, y + t.cur_y + 1);
			if (tetris_blocks[t.current_block][t.rotation][y][x] == 1)
			{
				printf("■");
			}
			GoToxy(0, 0);
			printf("                                                 ");
		}
	}
}

void Show_NextBlock(Tetris*t)
{
	Blocks(t);

	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			GoToxy((19 + x) * 2, y + 1);
			if ((x == 0) || (x == 6 - 1) || (y == 0) || (y == 6 - 1))
				printf("▣");
			else
				printf("  ");
			GoToxy(0, 0);
			printf("                                                 ");
		}
	}
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			GoToxy((20 + x) * 2, y + 2);
			if (tetris_blocks[t->next_block][0][y][x] == 0)
				printf("  ");
			else if (tetris_blocks[t->next_block][0][y][x] == 1)
				printf("■");
			GoToxy(0, 0);
			printf("                                                 ");
		}
	}
}

void Show_Stage()
{
	GoToxy(38, 13);
	printf("단계 : %2d", player.stage);
	GoToxy(0, 0);
	printf("                                                 ");
}

void Show_Score()
{
	GoToxy(38, 15);
	printf("점수 : %06d", player.score);
	GoToxy(0, 0);
	printf("                                                 ");
}