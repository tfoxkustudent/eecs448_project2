#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <iostream>
#include <string>

using namespace std;

class Minesweeper
{
private:
  string** Uboard;
  string** Bboard;
  void setMine();
  bool RecCheck();
  int Check();

public:
  Minesweeper(int row, int col, int NumOfMines);
  ~Minesweeper();

  void Revealing(int row, int col);
  void Marking(int row, int col);

};
#endif
