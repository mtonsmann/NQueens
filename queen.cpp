#include "queen.h"
#include "board.h"

Queen::Queen(Board &board, int x, int y) {
  x_cord = x;
  y_cord = y;
  board.content[y].set(x, 'Q');

  setHeat(board);
}

// Creates heat board of how many queens can move to each
// position. Can be viewed by adding board.printHeat() to main
void Queen::setHeat(Board &board) {
  for (int y = 0; y < board.content.size(); y++){
    for (int x = 0; x < board.content[y].size(); x++) {
      if (canMoveTest(x, y)) {
        board.heat[y].set(x, (board.heat[y].get(x) + 1));
      }
    }
  }
}

// Tests if current queen object can move to a given position
bool Queen::canMoveTest(int x, int y) {
  if (x == x_cord) return true;
  else if (y == y_cord) return true;
  else if (abs (x - x_cord) == abs (y - y_cord)) return true;
  else return false;
}

// Moves queen to position in row where least number of queens
// can attack it. If mulitple spots, chooses one at random
Queen Queen::move(Board &board)
{
  // Minumum value
  int min = board.heat[y_cord][0];
  // X coordinate of min value
  int x_min = 0;
  srand(time(NULL));

  for(int i = 1; i < board.heat[y_cord].size(); i++) {
    if(board.heat[y_cord][i] < min) {
      min = board.heat[y_cord][i];
      x_min = i;
    }
    else if(board.heat[y_cord][i] == min) {
      if(rand() % 2 == 1) {
        min = board.heat[y_cord][i];
        x_min = i;
      }
    }
  }
  board.content[y_cord].set(x_cord, '_');
  x_cord = x_min;
  board.content[y_cord].set(x_cord, 'Q');

  // returns new queen object to replace if the
  // std::vector of queens
  return Queen(board, x_cord, y_cord);
}
