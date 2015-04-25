#include "vector.h"
#include "simpio.h"
#include "board.h"
#include "queen.h"
#include "set.h"

using namespace std;

// Global variables
int c = 0;
int total = 0;
bool solved = false;

// method declarations
void solve(int n, int r);

int main(int argc, char* argv[]) {

  // prompt for n
  int n = getInteger("Chessboard size/number of queens (N)? ");
  int r = getInteger("How often would you like to restart (n*?): ");

  // For timing
  clock_t startTime = clock();

  // Main loop, to protect against bad seeds
  while(!solved) {
    solve(n, r);
    c = 0;
    if (!solved) {
      cout << "*************RESTART***************" << endl;
    }
  }
  cout << "SOLVED IN: " << endl;
  cout << to_string(total) << " Total steps" << endl;
  cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC << " seconds." << endl;

  return 0;
}

void solve(int n, int r) {

  Board board = Board(n);

  board.printContent();

  // populate board with queens
  // random, but with no queens able to attack
  // horizontally or vertical
  vector<Queen> queens;
  Set<int> used;
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    int x = rand() % (n);
    while(used.contains(x)) x = rand() % (n);
    Queen temp = Queen(board, x, i);
    queens.push_back(temp);
    used.add(x);
  }

  // Solving loop
  while(!board.isDone()) {

    if (c > n*r) break;

    // moves queens, by row, to safest spot
    for(Queen q : queens) {

      // r code if on bad seed
      // and taking too long
      if (board.isDone()) {
        solved = true;
        break;
      } else if (c > n*r) break;

      int i = c % queens.size();

      // actually moves queen and updates board
      queens[i] = q.move(board);
      board.resetHeat();
      for (Queen qu : queens) {
        qu.setHeat(board);
      }
      c++;
      total++;
    }
  }
  board.printContent();
}
