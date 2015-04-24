#include "vector.h"
#include "simpio.h"
#include "board.h"
#include "queen.h"
#include "set.h"

using namespace std;

int c = 0;
int total = 0;
bool solved = false;

void solve(int n);

int main(int argc, char* argv[]) {

  // prompt for n
  int n = getInteger("Chessboard size/number of queens (N)? ");

  clock_t startTime = clock();
  while(!solved) {
    solve(n);
    c = 0;
    cout << "*************RESTART***************" << endl;
  }
  cout << "Total steps made: " << to_string(total) << endl;
  cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC << " seconds." << endl;

  return 0;
}

void solve(int n) {
  Board board = Board(n);

  board.printContent();

    // populate board with queens
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

    //board.printContent();

    //board.printHeat();

    while(!board.isDone()) {
      if (c > n*10) break;

      for(Queen q : queens) {

        if (board.isDone()) {
          solved = true;
          break;
        } else if (c > n*10) break;
        //TODO: maybe add an if (q.isMin) continue??

        int i = c % queens.size();

        queens[i] = q.move(board);
        board.resetHeat();
        for (Queen qu : queens) {
          qu.setHeat(board);
        }
        //board.printContent();
        //board.printHeat();
        c++;
        total++;
        //cout << "Total steps made: " << to_string(total) << endl;
      }

  }
}
