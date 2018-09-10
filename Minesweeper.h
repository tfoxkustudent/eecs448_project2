#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <iostream>
#include <string>

using namespace std;

class Minesweeper
{
private:
  int m_row;
  int m_col;
  int num;
  int remaining;
  string** Uboard;
  string** Bboard;
  void setMines(std::string **arr, int row, int col, int mimes, std::string mineSignal);
  bool RecCheck();
  int Check();

public:
  Minesweeper(int Row, int Col, int NumOfMines);
  ~Minesweeper();

  void Revealing(int Row, int Col);
  void Marking(int Row, int Col);

};
#endif
