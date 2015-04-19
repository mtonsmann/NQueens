#include "board.h"

Board::Board(int n) {

  ng = n;

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

//the code for the function isDone
bool Board::isDone()
{
  //the outer layer of the for loop, switches rows
  for(int i = 0; i < heat.size(); i++)
  {
    //inner layer, this one is for going to actual spaces
    for(int j = 0; j < heat[i].size(); j++)
    {
      //checks the heat map value
      if(heat[i][j] != 1){return false;}
    }
  }
  return true;
}

void Board::resetHeat() {
  for (int i = 0; i < ng; i++) {
    for (int j = 0; j < ng; j++) {
      heat[i].set(j, 0);
    }
  }
}
