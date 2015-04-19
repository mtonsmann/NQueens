#include "queen.h"
#include "board.h"

Queen::Queen(Board &board, int x, int y) {
  board.content[y].set(x, 'Q');
}
