#include "Minesweeper.h"

Minesweeper:: Minesweeper(int Row, int Col, int NumOfMines)
{
  m_row = Row;
  m_col = Col;
  num = NumOfMines;
  remaining = num;

  Uboard = new string* [m_row];
  for (int i = 0; i < row; i++)
  {
    Uboard[i] = new string [m_col];
  }

  Bboard = new string*[m_row];
  for (int i = 0; i < row; i++)
  {
    Bboard[i] = new string*[m_col];
  }

  setMines(int num);
}

Minesweeper:: ~Minesweeper()
{
  for (int i = 0; i < m_row; i++)
  {
    delete[] Uboard[i];
  }
  delete[] Uboard;

  for (int i = 0; i < m_row; i++)
  {
    delete[] Bboard[i];
  }
  delete[] Bboard;
}
