#include "Flag.h"
Flag::Flag() {
	gotoXY(matrix[3][3].x, matrix[3][3].y);
	cursor.x = 3;
	cursor.y = 3;
}
void Flag::get_char() {
	int x = whereX(); int y = whereY();
	char get_ch = '\n';
	get_ch = _getch();
	switch (get_ch) {
	case 'a':
		cursor.x--;
		gotoXY(x - 4, y);
		break;
	case 'd':
		cursor.x++;
		gotoXY(x + 4, y);
		break;
	case 'w':
		cursor.y--;
		gotoXY(x, y - 2);
		break;
	case 's':
		cursor.y++;
		gotoXY(x, y + 2);
		break;
	case 'x':
		matrix[cursor.y][cursor.x].tag = 10;
		cout << "X";
		gotoXY(x, y);
		break;
	case 'o':
		matrix[cursor.y][cursor.x].tag = 20;
		cout << "O";
		gotoXY(x, y);
		break;
	}
}
void Flag::check_print_brack_flag() {
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

