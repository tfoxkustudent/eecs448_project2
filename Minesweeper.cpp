#include "Minesweeper.h"
using namespace std;
Minesweeper:: Minesweeper(int Row, int Col, int NumOfMines)
{
  m_row = Row;
  m_col = Col;
  m_mines = NumOfMines;
  //remaining = num;

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
void Minesweeper::setMines(int mines)
{

  int count; //use to set the number of mines
  while(count < mines)
  {
    for(int i =0; i<m_row; i++)
    {
      for(int j; j<m_col; j++)
        {
          int tempRow = rand() % (m_row-1);
          int tempCol = rand() % (m_col-1);
          //set the mine is the block is blank, otherwise keep looping
          if(Bboard[tempRow][tempCol] == "")
          {
            Bboard[tempRow][tempCol] = "Mine";
            count++;
          }
        }
        //keep looping if the number of mine is not enough
    }
  }
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