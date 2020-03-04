#pragma once
#include "Board.h"
class Flag {
private: 
	Matrix cursor;
public:
	Flag();
	int get_char();
	void check_print_back_flag();
	int check_win(int get_ch);
	void win_treatment(int check_win);
};


