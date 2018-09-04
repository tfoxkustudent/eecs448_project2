#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <iostream>
#include <string>

using namespace std;

class Minesweeper
{
private:
  int row;
  int col;
  int num;
  int remaining;
  string** Uboard;
  string** Bboard;
  void setMines(int NumOfMines);
  bool RecCheck();
  int Check();

public:
  Minesweeper(int Row, int Col, int NumOfMines);
  ~Minesweeper();

  void Revealing(int row, int col);
  void Marking(int row, int col);

};
#endif
