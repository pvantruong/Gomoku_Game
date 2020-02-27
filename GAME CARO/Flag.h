#pragma once
#include "Board.h"
class Flag {
private: 
	Matrix cursor;
public:
	Flag();
	void get_char();
	void check_print_brack_flag();
};


