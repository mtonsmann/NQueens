#include "board.h"

Board::Board(int n) {

  // so that everything can use n
  ng = n;

  // Creates a n x n "chess board"
  for (int i = 0; i < n; i++) {
    Vector<char> temp;
    content.add(temp);
    for (int j = 0; j < n; j++) {
      content[i].add('_');
    }
  }

  // Creates an empty heat map (all 0s)
  for (int i = 0; i < n; i++) {
    Vector<int> temp;
    heat.add(temp);
    for (int j = 0; j < n; j++) {
      heat[i].add(0);
    }
  }
}

// Prints the board to the console
void Board::printContent() {
  for (int i = 0; i < content.size(); i++) {
    cout << content[i].toString() << endl;
  }
  cout << endl;
}

// Prints the heat board to console
void Board::printHeat() {
  for (int i = 0; i < heat.size(); i++) {
    cout << heat[i].toString() << endl;
  }
  cout << endl;
}

// Checks if all the queens can only be attacked
// by 1 (themselves)
bool Board::isDone() {
  int ones = 0;
  //the outer layer of the for loop, switches rows
  for(int y = 0; y < heat.size(); y++) {
    //inner layer, this one is for going to actual spaces
    for(int x = 0; x < heat[y].size(); x++) {
      //checks the heat map value
      if((heat[y][x] == 1) && (content[y][x] == 'Q')) {
        ones++;
      }
    }
  }
  return (ones == heat.size());
}

// Resets heat to all 0s so that it can be updated
void Board::resetHeat() {
  for (int i = 0; i < ng; i++) {
    for (int j = 0; j < ng; j++) {
      heat[i].set(j, 0);
    }
  }
}
