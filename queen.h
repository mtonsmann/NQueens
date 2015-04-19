#include "board.h"
#include "set.h"

class Queen {
public:
  Queen(Board &board, int x, int y);
  bool canMoveTest(int x, int y);

  Set<string> canMoveTo;
  int x_cord;
  int y_cord;

};
