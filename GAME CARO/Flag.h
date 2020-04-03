#pragma once
#include "Board.h"
class Flag {
private: 
	Matrix cursor;
	int check_turn = 1;
	int count_turn = 0;
public:
	Flag();
	int get_char();
	void check_print_back_flag();
	void display_flag(int get_ch);
	int check_win(int get_ch);
	void win_treatment(int check_win);
	void save_flag(int get_ch);
	void load_flag_from_file(int get_ch);
	//void return_flag(int get_ch);
};


