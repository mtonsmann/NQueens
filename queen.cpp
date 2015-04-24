#include "queen.h"
#include "board.h"

Queen::Queen(Board &board, int x, int y) {
  x_cord = x;
  y_cord = y;
  board.content[y].set(x, 'Q');

  setHeat(board);
}

void Queen::setHeat(Board &board) {
  for (int y = 0; y < board.content.size(); y++){
    for (int x = 0; x < board.content[y].size(); x++) {
      if (canMoveTest(x, y)) {
        //canMoveTo.add(to_string(x) + "," + to_string(y));
        board.heat[y].set(x, (board.heat[y].get(x) + 1));
      }
    }
  }
  //cout << "setHeat x_cord: " << to_string(x_cord) << endl << endl;
}

bool Queen::canMoveTest(int x, int y) {
  if (x == x_cord) return true;
  else if (y == y_cord) return true;
  else if (abs (x - x_cord) == abs (y - y_cord)) return true;
  else return false;
}

Queen Queen::move(Board &board)
{
  int min = board.heat[y_cord][0];
  int x_min = 0;
  srand(time(NULL));

  //for testing:
  //cout << "initial min location : " << to_string(x_min) << endl;

  for(int i = 1; i < board.heat[y_cord].size(); i++) {

    if(board.heat[y_cord][i] < min) {
      min = board.heat[y_cord][i];
      x_min = i;
    }
    if(board.heat[y_cord][i] == min) {
      if(rand() % 2 == 1) {
        min = board.heat[y_cord][i];
        x_min = i;
      }
    }
  }
  board.content[y_cord].set(x_cord, '#');
  x_cord = x_min;
  // for testing:
  //cout << "final min: " << to_string(x_min) << endl;
  //cout << "new x_cord: " << to_string(x_cord) << endl << endl;
  board.content[y_cord].set(x_cord, 'Q');

  return Queen(board, x_cord, y_cord);
}
