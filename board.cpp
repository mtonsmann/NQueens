#include "board.h"

Board::Board(int n) {
  for (int i = 0; i < n; i++) {
    Vector<char> temp;
    content.add(temp);
    for (int j = 0; j < n; j++) {
      content[i].add('#');
    }
  }

  for (int i = 0; i < n; i++) {
    Vector<int> temp;
    heat.add(temp);
    for (int j = 0; j < n; j++) {
      heat[i].add(0);
    }
  }
}

void Board::printContent() {
  for (int i = 0; i < content.size(); i++) {
    cout << content[i].toString() << endl;
  }
  cout << endl;
}

void Board::printHeat() {
  for (int i = 0; i < heat.size(); i++) {
    cout << heat[i].toString() << endl;
  }
  cout << endl;
}
