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
	int n, m = 0;
	while (1) {
		n = flag.get_char();
		flag.display_flag(n);
		m = flag.check_win(n);
		flag.win_treatment(m);
		//board.save_flag_to_file(n);
		//flag.save_flag(n);
		//flag.load_flag_from_file(n);
	}
}