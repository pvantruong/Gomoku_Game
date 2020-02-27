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
	int n = 0;
	while (n != 30) {
		flag.get_char();
		n++;
	}
	flag.check_print_brack_flag();
	board.print_board();

}