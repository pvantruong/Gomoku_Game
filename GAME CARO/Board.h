#pragma once
#include "kmin_console.h"
#include <fstream>
#define LENGTH_B 12 //Length board
#define WIDTH_B 12 //Width board
//NOTE: Length board is the amount of square in length
//      Each square's dimension is 2*4
#define LEFT_MARGIN 2
#define UP_MARGIN 0
#define LENGTH_INS 31
#define WIDTH_INS 6

//Graphic for BOARD
#define BLOCK_CORNER (char)206
#define BLOCK_HORIZONTAL (char)205
#define BLOCK_VERTICAL (char)186
#define BLOCK_CORNER_U (char)203
#define BLOCK_CORNER_D (char)202
#define BLOCK_CORNER_L (char)204
#define BLOCK_CORNER_R (char)185
#define BLOCK_CORNER_U_L (char)201
#define BLOCK_CORNER_D_L (char)200
#define BLOCK_CORNER_U_R (char)187
#define BLOCK_CORNER_D_R (char)188

struct Matrix{
	int x, y;
	int tag = 0;
};
extern Matrix matrix[WIDTH_B][LENGTH_B];
extern Matrix array_saved_flag[WIDTH_B * LENGTH_B];

class Board{
private:

public:
	Board();
	void print_board();
	void print_rectangle(int x_u, int y_u, int x_d, int y_d);
	void print_ins_frame(int x_u, int y_u, int x_d, int y_d);
	void print_back_flag();
	void win_treatment(int check_win);
};

