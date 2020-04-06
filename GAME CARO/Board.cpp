#include "Board.h"
Matrix matrix[WIDTH_B][LENGTH_B];
Matrix array_saved_flag[WIDTH_B * LENGTH_B];


Board::Board() {
	for (int i = 0; i < WIDTH_B; i++) {
		for (int j = 0; j < LENGTH_B; j++) {
			matrix[i][j].x = LEFT_MARGIN + 2 + j * 4;
			matrix[i][j].y = UP_MARGIN + 1 + i * 2;
			matrix[i][j].tag = 0;
		}
	}
}
void Board::print_board() {	
	//PRINT INS FRAME
	print_ins_frame(LENGTH_B * 4 + 1 + LEFT_MARGIN, UP_MARGIN, LENGTH_B * 4 + 1 + LEFT_MARGIN + LENGTH_INS, UP_MARGIN + WIDTH_INS);
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
void Board::print_rectangle(int x_u, int y_u, int x_d, int y_d) {
	gotoXY(x_u, y_u);
	for (int i = x_u; i <= x_d; i++) {
		if (i == x_u) cout << BLOCK_CORNER_U_L;
		else if (i == x_d) cout << BLOCK_CORNER_U_R;
		else cout << BLOCK_HORIZONTAL;
	}
	gotoXY(x_u, y_d);
	for (int i = x_u; i <= x_d; i++) {
		if (i == x_u) cout << BLOCK_CORNER_D_L;
		else if (i == x_d) cout << BLOCK_CORNER_D_R;
		else cout << BLOCK_HORIZONTAL;
	}
	for (int i = y_u + 1; i < y_d; i++) {
		gotoXY(x_u, i);
		cout << BLOCK_VERTICAL;
	}
	for (int i = y_u + 1; i < y_d; i++) {
		gotoXY(x_d, i);
		cout << BLOCK_VERTICAL;
	}

}
void Board::print_ins_frame(int x_u, int y_u, int x_d, int y_d) {
	print_rectangle(x_u, y_u, x_d, y_d);
	gotoXY(x_u + 1, y_u + 1);
	cout << "- Enter A,W,S,D to move cursor";
	gotoXY(x_u + 1, y_u + 2);
	cout << "      and R to return.";
	gotoXY(x_u + 1, y_u + 3);
	cout << "- X play first!";


}
void Board::print_back_flag() {

	for (int i = 0; i < WIDTH_B; i++) {
		for (int j = 0; j < LENGTH_B; j++) {
			gotoXY(matrix[i][j].x, matrix[i][j].y);
			if (matrix[i][j].tag == 1) { cout << "X"; }
			else if (matrix[i][j].tag == 2) { cout << "O"; }
		}
	}
}
void Board::win_treatment(int check_win) {
	if (check_win != 0) {
		clrscr();
		print_board();
		print_back_flag();
		int x_u = LEFT_MARGIN + LENGTH_B / 2 * 4 - 10;
		int x_d = LEFT_MARGIN + LENGTH_B / 2 * 4 + 10;
		int y_u = UP_MARGIN + WIDTH_B / 2 - 1;
		int y_d = UP_MARGIN + WIDTH_B / 2 + 2;
		print_rectangle(x_u, y_u, x_d, y_d);
		gotoXY(x_u + 1, y_u + 1);
		if (check_win == 1) cout << " Congrats, X win!!";
		else cout << " Congrats, O win!!";
		gotoXY(x_u + 1, y_u + 2);
		cout <<      "Enter R to restart!";
	\
	}
}
