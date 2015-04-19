#ifndef BOARD_H
#define BOARD_H

#include "vector.h"

class Board {
public:
  Board(int n);
  Vector<Vector<char> > content;
  void printContent();

private:

};

#endif
