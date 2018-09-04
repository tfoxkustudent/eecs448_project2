#include "Minesweeper.h"

Minesweeper:: Minesweeper(int Row, int Col, int NumOfMines)
{
  row = Row;
  col = Col;
  num = NumOfMines;
  remaining = num;

  Uboard = new string* [row];
  for (int i = 0; i < row; i++)
  {
    Uboard[i] = new string [col];
  }

  Bboard = new string*[row];
  for (int i = 0; i < row; i++)
  {
    Bboard[i] = new string*[col];
  }

  setMines(int num);
}

Minesweeper:: ~Minesweeper()
{
  for (int i = 0; i < row; i++)
  {
    delete[] Uboard[i];
  }
  delete[] Uboard;

  for (int i = 0; i < row; i++)
  {
    delete[] Bboard[i];
  }
  delete[] Bboard;
}
