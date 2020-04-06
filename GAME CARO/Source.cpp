#include "Board.h"
#include "Flag.h"
using namespace std;
void main() {
	/*for (int i = 0; i < 256; i++) {
		cout << i << ": " << (char)i << endl;
	}*/
	Board board;
	board.print_board();
	Flag flag; 
	int get_ch, check_win = 0;
	while (1) {
		get_ch = flag.get_char();
		flag.display_flag(get_ch);
		check_win = flag.check_win(get_ch);
		//flag.win_treatment(check_win);
		board.win_treatment(check_win);
	}
}