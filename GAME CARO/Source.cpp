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
		m = flag.check_win(n);
		flag.win_treatment(m);

		
	}
}