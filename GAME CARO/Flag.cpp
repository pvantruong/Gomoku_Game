#include "Flag.h"
#include <string>

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
		return 1;
		break;
	case 'o':
		return 2;
		break;
	case 'r':
		return 3;
		break;
	}
}
void Flag::display_flag(int get_ch) {
	int x = whereX(); int y = whereY();
	switch (get_ch) {
	case 1:
		//Assign tag 
		if (matrix[cursor.y][cursor.x].tag == 0 && check_turn == 1) {
			matrix[cursor.y][cursor.x].tag = 1;
			//Save date into array_saved_flag
			array_saved_flag[count_turn] = cursor;
			array_saved_flag[count_turn].tag = 1;
			//
			cout << "X";
			count_turn++;
			check_turn = 2;
			gotoXY(x, y);
		}
		break;
	case 2:
		if (matrix[cursor.y][cursor.x].tag == 0 && check_turn == 2) {
			matrix[cursor.y][cursor.x].tag = 2;
			//Save date into array_saved_flag
			array_saved_flag[count_turn] = cursor;
			array_saved_flag[count_turn].tag = 2;
			//
			cout << "O";
			count_turn++;
			check_turn = 1;
			gotoXY(x, y);
		}
		break;
	case 3: //Case return
		gotoXY(matrix[array_saved_flag[count_turn - 1].y][array_saved_flag[count_turn - 1].x].x, matrix[array_saved_flag[count_turn - 1].y][array_saved_flag[count_turn - 1].x].y);
		matrix[array_saved_flag[count_turn - 1].y][array_saved_flag[count_turn - 1].x].tag = 0;
		//Edit cursor
		cursor = array_saved_flag[count_turn - 1];
		//Edit check_turn
		if (count_turn % 2 == 0) {
			check_turn = 2;
		}
		else check_turn = 1;
		x = whereX(); y = whereY();
		cout << " ";
		gotoXY(x, y);
		count_turn--;
		break;
	}
}
//Dont use

//
void Flag::win_treatment(int check_win) {
	if (check_win == 1) {
		clrscr();

	}
	else if (check_win == 2) {
		gotoXY(10, 10);
		cout << "Yeahh, O win!";
	}
}
int Flag::check_win(int get_ch) { // get_ch is the value return from int get_ch()
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
	return 0;
}
//

void Flag::save_flag(int get_ch) {
	fstream save_flag("save_flag.txt", ios::app);
	if (get_ch == 1 || get_ch == 2) { //Only implement this action when get_ch is 1 or 2
		save_flag << count_turn << "," << cursor.y << "," << cursor.x << "," << matrix[cursor.y][cursor.x].tag << ",";
	}
	save_flag.close();
}
void Flag::load_flag_from_file(int get_ch) {
	fstream load_flag("save_flag.txt");
	if (get_ch == 1 || get_ch == 2) { //Only implement this action when get_ch is 1 or 2
		string str_count, str_x, str_y, str_tag;
		int int_count = 0, int_x, int_y, int_tag;
		do {
			getline(load_flag, str_count, ',');
			int_count = stoi(str_count);
		} while (int_count != count_turn);
		getline(load_flag, str_y, ',');
		getline(load_flag, str_x, ',');
		getline(load_flag, str_tag, ',');
		//CHECK
		int x = whereX(), y = whereY();
		gotoXY(2, WIDTH_B*2 + count_turn - 1000);
		cout << "str_x = " << stoi(str_x);
		cout << "str_y = " << stoi(str_y);
		cout << "str_tag = " << stoi(str_tag);
		gotoXY(x, y);
		//END CHECK


		array_saved_flag[count_turn - 1001].x = stoi(str_x); 
		array_saved_flag[count_turn - 1001].y = stoi(str_y); 
		array_saved_flag[count_turn - 1001].tag = stoi(str_tag);
		
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

