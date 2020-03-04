#include "Flag.h"

Flag::Flag() {
	//Initialize cursor location
	gotoXY(matrix[3][3].x, matrix[3][3].y);
	cursor.x = 3;
	cursor.y = 3;
}
int Flag::get_char() {
	int x = whereX(); int y = whereY();
	char get_ch = '\n';
	get_ch = _getch();
	switch (get_ch) {
	case 'a':
		//Move cursor's index
		cursor.x--;
		gotoXY(x - 4, y);
		return 0;
		break;
	case 'd':
		cursor.x++;
		gotoXY(x + 4, y);
		return 0;
		break;
	case 'w':
		cursor.y--;
		gotoXY(x, y - 2);
		return 0;
		break;
	case 's':
		cursor.y++;
		gotoXY(x, y + 2);
		return 0;
		break;
	case 'x':
		//Assign tag 
		matrix[cursor.y][cursor.x].tag = 10;
		cout << "X";
		gotoXY(x, y);
		return 10;
		break;
	case 'o':
		matrix[cursor.y][cursor.x].tag = 20;
		cout << "O";
		gotoXY(x, y);
		return 20;
		break;
	}
}
void Flag::check_print_back_flag() {
	clrscr();
	cout << "Ok, now we will check our matrix.tag =  )))";
	Sleep(1000);
	clrscr();
	for (int i = 0; i < WIDTH_B; i++) {
		for (int j = 0; j < LENGTH_B; j++) {
			gotoXY(matrix[i][j].x, matrix[i][j].y);
			if (matrix[i][j].tag == 10) { cout << "X"; }
			else if (matrix[i][j].tag == 20) { cout << "O"; }
		}
	}
}
void Flag::win_treatment(int check_win) {
	if (check_win == 10) {
		gotoXY(10, 10);
		cout << "Yeahh, X win!";
	}
	else if (check_win == 20) {
		gotoXY(10, 10);
		cout << "Yeahh, O win!";
	}
}
int Flag::check_win(int get_ch) {
	if (get_ch != 0) { //Only implement check_win when input is 'X' or 'O'
		//int x = cursor.x, y = cursor.y;
		int tag = get_ch, continuous_count = 0;
		int interval_xy = cursor.x - cursor.y;
		int interval_xy_rigth = cursor.x - (WIDTH_B - 1 - cursor.y);
		//Check vertical
		for (int i = 0; i < WIDTH_B; i++) {
			if (matrix[i][cursor.x].tag == tag) {
				continuous_count++;
				if (continuous_count >= 5) { return tag; }
			}
			else {
				continuous_count = 0;
			}
		}
		//Check horizontal
		for (int i = 0; i < LENGTH_B; i++) {
			if (matrix[cursor.y][i].tag == tag) {
				continuous_count++;
				if (continuous_count >= 5) { return tag; }
			}
			else {
				continuous_count = 0;
			}
		}
		//Check cross left
		for (int i = 0; i < LENGTH_B; i++) {
			for (int j = 0; j < WIDTH_B; j++) {
				if ((i - (WIDTH_B - 1 - j)) == interval_xy_rigth) {
					if (matrix[j][i].tag == tag) {
						continuous_count++;
						if (continuous_count >= 5) { return tag; }
					}
					else {
						continuous_count = 0;
					}
				}
			}
		}
		//check cross right
		for (int i = 0; i < LENGTH_B; i++) {
			for (int j = 0; j < WIDTH_B; j++) {
				if (i - j == interval_xy) {
					if (matrix[j][i].tag == tag) {
						continuous_count++;
						if (continuous_count >= 5) { return tag; }
					}
					else {
						continuous_count = 0;
					}
				}
			}
		}
	}
}

/*

		//Check vertical
		for (int i = 0; i < LENGTH_B; i++) {
			for (int j = 0; j < WIDTH_B; j++) {
				if (i == cursor.x) {
					if (matrix[j][i].tag == tag)
				}
			}
		}
		for (int i = 0; i < WIDTH_B; i++) {
			if (matrix[i][cursor.x].tag == tag) {
				continuous_count++;
				if (continuous_count == 5) { return tag; }
			}
			else {
				continuous_count == 0;
			}
		}
		//Check horizontal
		for (int i = 0; i < LENGTH_B; i++) {
			if (matrix[cursor.y][i].tag == tag) {
				continuous_count++;
				if (continuous_count == 5) { return tag; }
			}
			else {
				continuous_count == 0;
			}
		}
		if (interval_xy >= 0) {
			//Check cross left
			for (int i = interval_xy; i < LENGTH_B; i++) {
				if (matrix[i - interval_xy][i].tag == tag) {
					continuous_count++;
					if (continuous_count == 5) { return tag; }
				}
				else {
					continuous_count == 0;
				}
			}
			//Check cross right
			for (int i = 0; i < LENGTH_B; i++) {
				for (int j = 0; j < WIDTH_B; j++) {
					if()
				}
				if (matrix[i - interval_xy][i].tag == tag) {
					continuous_count++;
					if (continuous_count == 5) { return tag; }
				}
				else {
					continuous_count == 0;
				}
			}
		}
		else { //interval_xy < 0


		}
*/

