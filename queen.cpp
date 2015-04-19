#include "queen.h"
#include "board.h"

Queen::Queen(Board &board, int x, int y) {
  x = x_cord;
  y = y_cord;
  board.content[y].set(x, 'Q');

  for (int x = 0; x < board.content.size(); x++){
    for (int y = 0; y < board.content[x].size(); y++) {
      if (canMoveTest(x, y)) {
        //canMoveTo.add(to_string(x) + "," + to_string(y));
        board.heat[y].set(x, (board.heat[y].get(x) + 1));
      }
    }
  }
}

bool Queen::canMoveTest(int x, int y) {
  if (x == x_cord) return true;
  if (y == y_cord) return true;
  if (abs (x - x_cord) == abs (y - y_cord)) return true;
}
