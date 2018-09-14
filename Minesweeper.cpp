#include "Minesweeper.h"
#include <string>
#include <exception>
using namespace std;
Minesweeper:: Minesweeper(int Row, int Col, int NumOfMines)
{
  m_row = Row;
  m_col = Col;
  m_mines = NumOfMines;
  NumOfFlag=0;
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
  setMines();
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
void Minesweeper::setMines()
{

  int count=0; //use to set the number of mines
  while(count < m_mines)
  {
    int tempRow = rand() % (m_row-1);
    int tempCol = rand() % (m_col-1);
    //cout<<tempRow<<tempCol<<"\n";
    //set the mine is the block is blank, otherwise keep looping
    if(Bboard[tempRow][tempCol] == "■")
    {
      Bboard[tempRow][tempCol] = "M";
      count++;
    }
  }
}
bool Minesweeper::Marking(int Row, int Col, int option) throw(std::runtime_error)
{
  if(option==1)
  {
    if(Uboard[Row][Col]!="■")
    {
      throw(std::runtime_error("Cannot flag on non-blank block.\n"));
    }
    else
    {  
      Uboard[Row][Col] = "F";
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
  }
  else//unflag function
  {
    Uboard[Row][Col] = "U";
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
      if(Row<m_row && Col+1 < m_col && Row>=0 && Col+1>=0)
      {
        if(Bboard[Row][Col+1]=="M")
        {
          count++;
        }
      }
     if(Row<m_row && Col-1 < m_col && Row>=0 && Col-1>=0)
     {
      if(Bboard[Row][Col-1]=="M")
      {
        count++;
      }
     }
     if(Row+1<m_row && Col< m_col && Row+1>=0 && Col>=0)
     {
      if(Bboard[Row+1][Col]=="M")
      {
        count++;
      }
     }
     if(Row-1<m_row && Col<m_col && Row-1>=0 && Col>=0)
     {
      if(Bboard[Row-1][Col]=="M")
      {
        count++;
      }
     }
     if(Row+1<m_row && Col+1 < m_col && Row+1>=0 && Col+1>=0)
     {
        if(Bboard[Row+1][Col+1]=="M")
      {
        count++;
      }
     }
     if(Row+1<m_row && Col-1 < m_col && Row+1>=0 && Col-1>=0)
     {
        if(Bboard[Row+1][Col-1]=="M")
      {
        count++;
      }
     }
     if(Row-1<m_row && Col+1 < m_col&& Row-1>=0 && Col+1>=0)
     {
      if(Bboard[Row-1][Col+1]=="M")
      {
        count++;
      }
     }
     if(Row-1<m_row && Col-1 <m_col&& Row-1>=0 && Col-1>=0)
     {
      if(Bboard[Row-1][Col-1]=="M")
      {
        count++;
      }
  }
  return(count);
}


void Minesweeper::RecCheck(int Row, int Col)
{
  if(Check(Row,Col)==0 && Uboard[Row][Col]=="■")//Condition 1: There are no mines adjacent to the input position and this spot is in defalt status.
  {
    Uboard[Row][Col]="□";
    if(Row-1<m_row && Col-1 < m_col && Row-1>=0 && Col-1>=0)//Begin to check the 8 directions of the input position
    {
      Uboard[Row][Col]="□";
      RecCheck(Row-1,Col-1);
      
    }
    if(Row+1<m_row && Col+1 < m_col && Row+1>=0 && Col+1>=0)
    {
      Uboard[Row][Col]="□";
      RecCheck(Row+1,Col+1);
      
    }
    if(Row+1<m_row && Col-1 < m_col&& Row+1>=0 && Col-1>=0)
    {
      Uboard[Row][Col]="□";
      RecCheck(Row+1,Col-1);
      
    }
    if(Row-1<m_row && Col+1 < m_col&& Row-1>=0 && Col+1>=0)
    {
      Uboard[Row][Col]="□";
      RecCheck(Row-1,Col+1);
      
    }
    if(Row<m_row && Col+1 < m_col&& Row>=0 && Col+1>=0)
    {
      Uboard[Row][Col]="□";
      RecCheck(Row,Col+1);
      
    }
    if(Row+1<m_row && Col < m_col && Row+1>=0 && Col>=0)
    {
      Uboard[Row][Col]="□";
      RecCheck(Row+1,Col);
      
    }
    if(Row<m_row && Col-1 < m_col&& Row>=0 && Col-1>=0)
    {
      Uboard[Row][Col]="□";
      RecCheck(Row,Col-1);
      
    }
    if(Row-1<m_row && Col <m_col&& Row-1>=0 && Col>=0)
    {
      Uboard[Row][Col]="□";
      RecCheck(Row-1,Col);
     
    }
  }
  else//Condition 2: There are mines adjacent to the input position.
  {
    if(Check(Row,Col)==0)//This was set to prevent the situation the 0 will show on the board.
    {
      Uboard[Row][Col]="□";
    }
    else
    {
      Uboard[Row][Col]=to_string(Check(Row,Col));//set the spot to the number of the mines those are adjacent to it.
    }
  }
}


void Minesweeper::print(int option)
{
  cout<<"------------------------------------------\n";
	cout<<"    ";
	for(int k=0;k<m_col; k++)
	{
		if(k<9)
    {
      cout<<k<<"   ";
    }
    else if(k==9) 
    {
      cout<<k<<"   ";
    }
    else
    {
      cout<<k<<"  ";
    }
	}
	cout<<endl;
	for(int i=0; i<m_row; i++)
	{
    if(i<10)
    {
      cout<<i<<"   ";
    }
    else 
    {
      cout<<i<<"  ";
    }
		for(int j=0; j<m_col; j++)
		{
      if(option==2&&Bboard[i][j]=="M")
			{
        cout<<"M"<<"   ";
      }
      else
      {
        cout<<Uboard[i][j]<<"   ";
      }   
		}
		cout<<"\n";
	}
  cout<<"------------------------------------------\n";
}
void Minesweeper::Reset()
{
  for(int i=0;i<m_row;i++)
  {
    for(int j=0;j<m_col;j++)
    {
      Uboard[i][j]="■";
      Bboard[i][j]="■";
    }
  }
  setMines();
}

