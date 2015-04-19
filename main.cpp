#include "vector.h"
#include "simpio.h"
#include "board.h"
#include "queen.h"
#include "set.h"

using namespace std;

int main(int argc, char* argv[]) {

  // prompt for n
  int n = getInteger("Chessboard size/number of queens (N)? ");

  Board board = Board(n);

  board.printContent();

  // populate board with queens
  vector<Queen> queens;
  Set<int> used;
  for (int i = 0; i < n; i++) {
    int y = rand() % (n);
    while(used.contains(y)) y = rand() % (n);
    Queen temp = Queen(board, i, y);
    queens.push_back(temp);
    used.add(y);
  }

  board.printContent();

  board.printHeat();

  return 0;
}
