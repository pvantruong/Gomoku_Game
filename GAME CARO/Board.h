#pragma once
#include "kmin_console.h"
#define LENGTH_B 12
#define WIDTH_B 12
#define LEFT_MARGIN 3
#define UP_MARGIN 2
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
struct Matrix {
	int x, y;
	int tag = 0;
};
extern Matrix matrix[WIDTH_B][LENGTH_B];
class Board {
private:
	
public:
	Board();
	void print_board();
};

