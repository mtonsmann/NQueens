#include "vector.h"
#include "simpio.h"
#include "board.h"
#include "queen.h"
#include "set.h"

using namespace std;

int main(int argc, char* argv[]) {

  // prompt for n
  int n = getInteger("Chessboard size/number of queens (N)? ");
  int count = 0;

  Board board = Board(n);

  board.printContent();

  while (true)  {
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

    board.printContent();

    board.printHeat();

    while(!board.isDone()) {
      for(Queen q : queens) {

        if (board.isDone()) break;
        //TODO: maybe add an if (q.isMin) continue??

        int i = count % queens.size();

        queens[i] = q.move(board);
        board.resetHeat();
        for (Queen qu : queens) {
          qu.setHeat(board);
        }
        board.printContent();
        board.printHeat();
        count++;
        cout << "Steps made: " << to_string(count) << endl;
      }
    }
  }

  return 0;
}
