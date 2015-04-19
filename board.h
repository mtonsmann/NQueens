#ifndef BOARD_H
#define BOARD_H

#include "vector.h"

class Board {
public:
  Board(int n);
  void printContent();
  void printHeat();

  Vector<Vector<char> > content;
  Vector<Vector<int> > heat;

private:

};

#endif
