#include "Minesweeper.h"

Minesweeper:: Minesweeper(int Row, int Col, int NumOfMines)
{
  m_row = Row;
  m_col = Col;
  num = NumOfMines;
  remaining = num;

  Uboard = new string* [m_row];
  for (int i = 0; i < Row; i++)
  {
    Uboard[i] = new string [m_col];
  }

  Bboard = new string*[m_row];
  for (int i = 0; i < Row; i++)
  {
    Bboard[i] = new string[m_col];
  }

  setMines(NumOfMines);
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
bool Minesweeper::Marking(int Row, int Col)
{
  if(Row < m_row && Col < m_col && Row >= 0 && Col >= 0)
  {
    Uboard[Row][Col] = "Flag";
    return(true);
  }
  else
  {
    return(false);
  }
}
bool Minesweeper::Revealing(int Row, int Col)
{
  if(Bboard[Row][Col]!="Mine")
  {
    if(Row < m_row && Col < m_col && Row >= 0 && Col >= 0)
    {
      RecCheck(Row, Col);
      return(true);
    }
  }
  else
  {
    return(false);
  }  
}
