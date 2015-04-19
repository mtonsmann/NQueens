#include "board.h"
#include "set.h"

class Queen {
public:
  Queen(Board &board, int x, int y);
  bool canMoveTest(int x, int y);
  //a function to move a queen
  void move(Board &board);
  void setHeat(Board &board);

  Set<string> canMoveTo;
  int x_cord;
  int y_cord;

};
