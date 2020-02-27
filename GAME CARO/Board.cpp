#include "Board.h"
Matrix matrix[WIDTH_B][LENGTH_B];

Board::Board() {
	for (int i = 0; i < WIDTH_B; i++) {
		for (int j = 0; j < LENGTH_B; j++) {
			matrix[i][j].x = LEFT_MARGIN + 2 + j * 4;
			matrix[i][j].y = UP_MARGIN + 1 + i * 2;
		}
	}
}
void Board::print_board() {
	for (int i = 0; i < WIDTH_B; i++) {
		for (int j = 0; j < LENGTH_B; j++) {
			gotoXY(matrix[i][j].x - 1, matrix[i][j].y - 1);
			cout << BLOCK_HORIZONTAL << BLOCK_HORIZONTAL << BLOCK_HORIZONTAL;
			gotoXY(matrix[i][j].x - 2, matrix[i][j].y);
			cout << BLOCK_VERTICAL;
			
			gotoXY(matrix[i][j].x - 2, matrix[i][j].y - 1);
			if (i == 0) {
				cout << BLOCK_CORNER_U;
			}
			else {
				cout << BLOCK_CORNER;
			}
			if (j == 0) {
				gotoXY(matrix[i][j].x - 2, matrix[i][j].y - 1);
				cout << BLOCK_CORNER_L;
			}
			if (j == LENGTH_B - 1) {
				gotoXY(matrix[i][j].x + 2, matrix[i][j].y - 1);
				cout << BLOCK_CORNER_R;
				gotoXY(matrix[i][j].x + 2, matrix[i][j].y);
				cout << BLOCK_VERTICAL;
			}
			if (i == WIDTH_B - 1) {
				gotoXY(matrix[i][j].x - 2, matrix[i][j].y + 1);
				cout << BLOCK_CORNER_D;
				gotoXY(matrix[i][j].x - 1, matrix[i][j].y + 1);
				cout << BLOCK_HORIZONTAL << BLOCK_HORIZONTAL << BLOCK_HORIZONTAL;
			}
			if (i == 0 && j == 0) {
				gotoXY(matrix[i][j].x - 2, matrix[i][j].y - 1);
				cout << BLOCK_CORNER_U_L;
			}
			if (i == 0 && j == LENGTH_B - 1) {
				gotoXY(matrix[i][j].x + 2, matrix[i][j].y - 1);
				cout << BLOCK_CORNER_U_R;
			}
			if (i == WIDTH_B - 1 && j == 0) {
				gotoXY(matrix[i][j].x - 2, matrix[i][j].y + 1);
				cout << BLOCK_CORNER_D_L;
			}
			if (i == WIDTH_B - 1 && j == LENGTH_B - 1) {
				gotoXY(matrix[i][j].x + 2, matrix[i][j].y + 1);
				cout << BLOCK_CORNER_D_R;
			}
		}
	}
}

