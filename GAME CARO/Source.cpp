#include "Board.h"

using namespace std;
void main() {
	/*for (int i = 0; i < 256; i++) {
		cout << i << ": " << (char)i << endl;
	}*/
	Board board;
	board.initialize();
	board.print_board();
}