#include"Tetris_define.h"
#include"Tetris_extern.h"
#include"Tetris_function.h"
#include"Tetris_include.h"

void KBHit(int k)
{
	Tetris t_ = player;

	switch (k)
	{
	case UP:
		t_.rotation = (t_.rotation + 1) % 4;
		if (Collision_Check(t_) == 0)
		{
			Remove_CurrentBlock(player);
			player.rotation = t_.rotation;
			Show_GameBoard(player);
		}
		break;

	case DOWN:
		player.gameover = Move_Block(&player);
		if (player.gameover == 0)
			Show_GameBoard(player);
		else if (player.gameover == 1)
			player.gameover = 0;
		break;

	case LEFT:
		if (player.cur_x > 0)
		{
			Remove_CurrentBlock(player);
			player.cur_x--;
			if (Collision_Check(player) == 1)
			{
				player.cur_x++;
			}
			Show_GameBoard(player);
		}
		break;

	case RIGHT:
		if (player.cur_x < WIDTH)
		{
			Remove_CurrentBlock(player);
			player.cur_x++;
			if (Collision_Check(player) == 1)
			{
				player.cur_x--;
			}
			Show_GameBoard(player);
		}
		break;
	}
	if (k == SPACEBAR)
	{
		while (player.gameover == 0)
		{
			player.gameover = Move_Block(&player);
		}
		if (player.gameover == 1)
		{
			player.gameover = 0;
		}
	}
}

int Move_Block(Tetris*t)
{
	Remove_CurrentBlock(*t);
	t->cur_y++;
	
	if (Collision_Check(*t) == 1)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (t->cur_y <= 1 && tetris_gameboard[t->cur_y + y][t->cur_x + x] == 1)
				{
					t->cur_y--;
					Show_GameBoard(*t);
					return GAMEOVER;
				}
			}
		}
		t->cur_y--;
		Set_Block(t);
		Show_NextBlock(t);
		Show_GameBoard(*t);
		return 1;
	}

	return 0;
}

void Remove_CurrentBlock(Tetris t)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (tetris_blocks[t.current_block][t.rotation][y][x] == 1)
			{
				GoToxy((x + t.cur_x) * 2, y + t.cur_y);
				printf("  ");
			}
		}
	}
}

void Set_Block(Tetris*t)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if(tetris_blocks[t->current_block][t->rotation][y][x] == 1)
				tetris_gameboard[t->cur_y + y][t->cur_x + x] = tetris_blocks[t->current_block][t->rotation][y][x];
		}
	}
	Show_GameBoard(*t);
	(t->score) += Line_Check();
	if ((t->score) >= 50 && (t->score) < 100)
	{
		(t->stage) = 2;
		speed = 900;
	}
	else if ((t->score) >= 100 && (t->score) < 150)
	{
		(t->stage) = 3;
		speed = 800;
	}
	else if ((t->score) >= 150 && (t->score) < 200)
	{
		(t->stage) = 4;
		speed = 700;
	}
	else if ((t->score) >= 200 && (t->score) < 250)
	{
		(t->stage) = 5;
		speed = 600;
	}
	else if ((t->score) >= 250)
	{
		(t->stage) = 6;
		speed = 500;
	}
}