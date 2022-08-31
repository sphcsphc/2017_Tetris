#include"Tetris_define.h"
#include"Tetris_function.h"
#include"Tetris_include.h"
#include"Tetris_variable.h"

unsigned _stdcall move(void*arg)
{
	while (player.gameover != GAMEOVER)
	{
		Show_GameBoard(player);
		Sleep(speed);
		player.gameover = Move_Block(&player);
	}
	return 0;
}

int main()
{
	srand((unsigned)time(NULL));
	while (1)
	{
		system("cls");
		player.gameover = 0;
		player.stage = 1;	player.score = 0;
		player.current_block = -1;
		GameBoard();
		Show_GameBoard(player);
		Show_NextBlock(&player);
		Show_Stage();
		Show_Score();
		speed = 1000;
		_beginthreadex(NULL, 0, move, 0, 0, NULL);

		while (player.gameover != GAMEOVER)
		{
			key = getch();
			KBHit(key);
		}
		Sleep(500);
		system("cls");
		GoToxy(3, 2);
		printf("G");	Sleep(20);	printf("A");	Sleep(20);	printf("M");	Sleep(20);	printf("E");	Sleep(20);
		printf(" ");	Sleep(20);
		printf("O");	Sleep(20);	printf("V");	Sleep(20);	printf("E");	Sleep(20);	printf("R");	Sleep(20);
		GoToxy(3, 4);
		printf("%d", (player.stage) / 10);	Sleep(20);	printf("%d", (player.stage) % 10);	Sleep(20);
		printf(" ");	Sleep(20);
		printf("단");	Sleep(20);	printf("계");	Sleep(20);	printf("까");	Sleep(20);	printf("지");	Sleep(20);
		printf(" ");	Sleep(20);
		printf("오");	Sleep(20);	printf("셨");	Sleep(20);	printf("습");	Sleep(20);	printf("니");	Sleep(20);	printf("다");	Sleep(20);	printf(".");	Sleep(120);
		GoToxy(3, 6);
		printf("점");	Sleep(20); printf("수");	Sleep(20);	printf("는");	Sleep(20);
		printf(" ");	Sleep(20);
		printf("%d", (player.score) / 1000);	Sleep(20);	printf("%d", ((player.score) % 1000) / 100);	Sleep(20);	printf("%d", ((player.score) % 100) / 10);	Sleep(20);	printf("%d", (player.score) % 10);	Sleep(20);
		printf(" ");	Sleep(20);
		printf("입");	Sleep(20);	printf("니");	Sleep(20);	printf("다");	Sleep(20); printf(".");	Sleep(100);
		GoToxy(3, 8);
		printf("다");	Sleep(20);	printf("시");	Sleep(20);
		printf(" ");	Sleep(20);
		printf("하");	Sleep(20);	printf("겠");	Sleep(20);	printf("습");	Sleep(20);	printf("니");	Sleep(20);	printf("까");	Sleep(20);	printf("?");	Sleep(100);
		GoToxy(5, 10);
		printf("z : 예,	x : 아니요");
		while (key != 'z' && key != 'x')
			key = getch();
		if (key == 'z')
			continue;
		else if (key == 'x')
			break;
	}
	GoToxy(3, 12);
	return 0;
}