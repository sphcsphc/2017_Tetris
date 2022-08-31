
//Tetris_Blocks.c
void Blocks(Tetris*t);
void GameBoard();

//Tetris_Control.c
void KBHit(int k);
int Move_Block(Tetris*t);
void Remove_CurrentBlock(Tetris t);
void Set_Block(Tetris*t);

//Tetris_Check.c
int Collision_Check(Tetris t);
int Line_Check();

//Tetris_GoToxy.c
void GoToxy(int x, int y);

//Tetris_Show.c
void Show_GameBoard(Tetris t);
void Show_NextBlock(Tetris*t);
void Show_Stage();
void Show_Score();