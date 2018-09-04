#include "Minesweeper.h"

Minesweeper:: Minesweeper(int row, int col, int NumOfMines)
{
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

  setMines(int NumOfMines);
}
