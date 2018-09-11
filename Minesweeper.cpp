#include "Minesweeper.h"
#include <string>
using namespace std;
Minesweeper:: Minesweeper(int Row, int Col, int NumOfMines)
{
  m_row = Row;
  m_col = Col;
  m_mines = NumOfMines;
  //cout<<m_mines<<"M\n";
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
  for(int i=0;i<m_row;i++)
  {
    for(int j=0;j<m_col;j++)
    {
      Uboard[i][j]="■";
      Bboard[i][j]="■";
    }
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

  int count=0; //use to set the number of mines
  while(count < mines)
  {
    int tempRow = rand() % (m_row-1);
    int tempCol = rand() % (m_col-1);
    cout<<tempRow<<tempCol<<endl;
    //set the mine is the block is blank, otherwise keep looping
    if(Bboard[tempRow][tempCol] == "■")
    {
      Bboard[tempRow][tempCol] = "M";
      count++;
    }
  }
}
bool Minesweeper::Marking(int Row, int Col, int option)
{
  if(option==1 && Uboard[Row][Col]==" ")
  {
    Uboard[Row][Col] = "Flag";
    if(Bboard[Row][Col]=="M")
    {
      NumOfFlag++;
      if(NumOfFlag==m_mines)
      {
      return(true);//Condition1:set all the flags on the correct mines. 
      }
      else
      {
      return(false);// Condetion2:set one flag on the correct position.
      }
    }
    else
    {
      return(false);//Condition3:set one flag on the wrong position.
    }
  }
  else//unflag function
  {
    Uboard[Row][Col] = " ";
    if(Bboard[Row][Col]=="M")
    {
      NumOfFlag--;
    }
    return(false);
  }
}
bool Minesweeper::Revealing(int Row, int Col)
{
  if(Bboard[Row][Col]=="M")
  {
    return(false);
  }
  else
  {
    RecCheck(Row, Col);
    return(true);
  }  
}


int Minesweeper::Check(int Row, int Col)
{
	int count=0;
	for(int i=0;i<Row;i++)
	{
		for(int j=0; j<Col; j++)
		{
      if(Row-1<m_row)
      {
        if
      }
		}
	}
return(count);
}


void Minesweeper::RecCheck(int Row, int Col)
{
  cout<<Check(Row,Col)<<endl;
	if(Check(Row,Col)==0)
	{
		Uboard[Row][Col]="[]";
		RecCheck(Row-1,Col-1);
		RecCheck(Row+1,Col+1);
		RecCheck(Row+1,Col-1);
		RecCheck(Row-1,Col+1);
		RecCheck(Row,Col+1);
		RecCheck(Row+1,Col);
		RecCheck(Row,Col-1);
		RecCheck(Row-1,Col);
	}
	else
	{
		Uboard[Row][Col]=to_string(Check(Row,Col));
	}
}


void Minesweeper::print()
{
	cout<<" ";
	for(int k=0;k<m_row; k++)
	{
		cout<<k;
	}
	cout<<endl;
	for(int i=0; i<m_row; i++)
	{
		cout<<i;
	
		for(int j=0; j<m_col; j++)
		{
			cout<<Uboard[i][j];
		}
		cout<<"\n";
	}
}

