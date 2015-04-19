#include "queen.h"
#include "board.h"

Queen::Queen(Board &board, int x, int y) {
  x_cord = x;
  y_cord = y;
  board.content[y].set(x, 'Q');

  setHeat(board);
}

void Queen::setHeat(Board &board) {
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
  else return false;
}

void Queen::move(Board &board)
{
  int min = board.heat[y_cord][0];
  srand(time(NULL));
  for(int i = 1; i < board.heat[y_cord].size(); i++)
  {
    if(board.heat[y_cord][i] < min)
    {
      min = board.heat[y_cord][i];
      board.content[y_cord].set(i, '#');
    }
    if(board.heat[y_cord][i] == min)
    {
      if(rand() % 1 == 1)
      {
        min = board.heat[y_cord][i];
        board.content[y_cord].set(i, '#');
      }
    }
  }
  x_cord = min;
  board.content[y_cord].set(x_cord, 'Q');
}
