#include "Minesweeper.h"
using namespace std;
Minesweeper:: Minesweeper(int Row, int Col, int NumOfMines)
{
  m_row = Row;
  m_col = Col;
  num = NumOfMines;
  remaining = num;

  Uboard = new string* [m_row];
  for (int i = 0; i < m_row; i++)
  {
    Uboard[i] = new string [m_col];
  }

  Bboard = new string*[m_row];
  for (int i = 0; i < m_row; i++)
  {
    Bboard[i] = new string[m_col];
  }

  setMines(Bboard, m_row, m_col, num, "Mine");
}


/*------------------------------------------------------------------------------*/


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

/*------------------------------------------------------------------------------*/



void Minesweeper::setMines(std::string **arr, int row, int col, int mimes, std::string mineSignal)
{

  int count; //use to set the number of mines
  while(count < mines)
  {
    for(int i =0; i<row; i++)
    {
      for(int j; j<col; j++)
        {
          int tempRow = rand() % (row-1);
          int tempCol = rand() % (col-1);
          //set the mine is the block is blank, otherwise keep looping
          if(Bboard[tempRow][tempCol] == "")
          {
            Bboard[tempRow][tempCol] = mineSignal;
            count++;
          }
        }
        //keep looping if the number of mine is not enough
    }
  }
}
}
