#include "board.h"

Board::Board(int n) {
  for (int i = 0; i < n; i++) {
    Vector<char> temp;
    content.add(temp);
    for (int j = 0; j < n; j++) {
      content[i].add('#');
    }
  }
}

void Board::printContent() {
  for (int i = 0; i < content.size(); i++) {
    cout << content[i].toString() << endl;
  }
  cout << endl;
}
