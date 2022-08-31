#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACEBAR 32

#define WIDTH 16
#define HEIGHT 22

#define GAMEOVER 4

typedef struct tetris
{
	int gameover;
	int stage;
	int score;
	int rotation;
	int abs_x, abs_y;
	int cur_x, cur_y;
	int current_block;
	int next_block;
}Tetris;