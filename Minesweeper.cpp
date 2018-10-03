/** 
 * @author Team FourFour8
 * @file Minesweeper.cpp
 * @date September 2018
 * @brief Minesweeper implementation file
**/



#include "Minesweeper.h"
#include <string>
#include <exception>
#include <sstream>
using namespace std;




/*-------------------------------------------------------------------------------------------------Constructor-----------------------------------------------------------------------------------*/
Minesweeper:: Minesweeper(int Row, int Col, int NumOfMines)
{
  m_row = Row;
  m_col = Col;
  m_mines = NumOfMines;
  NumOfFlag=0;//
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
//end constructor


/*-------------------------------------------------------------------------------------------------Destructor-----------------------------------------------------------------------------------*/
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

//end Destructor



/*-------------------------------------------------------------------------------------------------setMines-----------------------------------------------------------------------------------*/

void Minesweeper::setMines()
{
  int count=0; //use to set the number of mines

  srand (time(NULL));
  while(count < m_mines)
  {
    int tempRow = rand() % (m_row);
    int tempCol = rand() % (m_col);
    //cout<<tempRow<<tempCol<<"\n";
    //set the mine is the block is blank, otherwise keep looping
    if(Bboard[tempRow][tempCol] != "M")
    {
      Bboard[tempRow][tempCol] = "M";
      count++;
	  for (int i = -1; i <= 1; i++) {
		  for (int j = -1; j <= 1; j++) {
			  if (tempRow+i >= 0 && tempRow+i < m_row && tempCol+j >= 0 && tempCol+j < m_col && Bboard[tempRow+i][tempCol+j] != "M") {
				  if (Bboard[tempRow+i][tempCol+j] == "■") {
					  Bboard[tempRow+i][tempCol+j] = "1";
				  }
				  else {
					  stringstream strmIN(Bboard[tempRow+i][tempCol+j]);
					  stringstream strmOUT;
					  int bombCnt;
					  strmIN >> bombCnt;
					  bombCnt++;
					  strmOUT << bombCnt;
					  Bboard[tempRow+i][tempCol+j] = strmOUT.str();
				  }
			  }
		  }
	  }
    }
  }
}
//end set
/*-------------------------------------------------------------------------------------------------Marking-----------------------------------------------------------------------------------*/
bool Minesweeper::Marking(int Row, int Col)
{
    if(Uboard[Row][Col]!="■")
    {
      throw(runtime_error("\n-----Cannot flag on non-blank block.-----\n"));
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
//end Marking 



/*-------------------------------------------------------------------------------------------------unMarking-----------------------------------------------------------------------------------*/
void Minesweeper::unMarking(int Row,int Col)
{
  if(Uboard[Row][Col]!="F")
  {
    throw(runtime_error("\n-----Cannot unflag the spot without flag.-----\n"));
  }
  else
  {
    if(Bboard[Row][Col]=="M")
    {
      NumOfFlag--;
    }
    Uboard[Row][Col]="■";
  }
}
//end unMarking



/*-------------------------------------------------------------------------------------------------Revealing-----------------------------------------------------------------------------------*/
bool Minesweeper::Revealing(int Row, int Col)
{
  if(Uboard[Row][Col]!="■")
  {
    throw(runtime_error("\n-----Cannot reveal this spot.-----\n"));
  }
  else
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
}
//end Revealing



/*-------------------------------------------------------------------------------------------------Check-----------------------------------------------------------------------------------*/
int Minesweeper::Check(int Row, int Col)
{

  int count=0;
  //case i = 0 and j = 0 will never add to count as hitting mine will end game before check() is called
  for(int i = -1; i <= 1; i++)//i for rows
  {
    for(int j = -1; j <= 1; j++)// j for cols
    {
      if(Row+i<m_row && Col+j < m_col && Row+i>=0 && Col+j>=0)
      {
        if(Bboard[Row+i][Col+j]=="M")
        {
          count++;
        }
      }
    }
  }
  return(count);
}
//end Check



/*-------------------------------------------------------------------------------------------------RecCheck-----------------------------------------------------------------------------------*/
void Minesweeper::RecCheck(int Row, int Col)
{
  if(Uboard[Row][Col]!="F")//makes sure flagged spots arn't revealed when being revealed from RecCheck. redundant check first time when being called from revealing()
  {
    if(Check(Row,Col)==0 && Uboard[Row][Col]=="■")//Condition 1: There are no mines adjacent to the input position and this spot is in defalt status.
    {
      Uboard[Row][Col]="□";
      // case i = 0 and j = 0 will go down to check if it is next to mine and will not cuase infinite recurive loop
      for (int i = -1; i <= 1; i++)//i is for rows
      {
        for(int j = -1; j <= 1; j++)//j is for cols
        {
          if(Row+i<m_row && Col+j< m_col && Row+i>=0 && Col+j>=0)//Begin to check the 8 directions of the input position
          {
            RecCheck(Row+i,Col+j);
          }
        }
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
}
//end RecCheck



/*-------------------------------------------------------------------------------------------------print-----------------------------------------------------------------------------------*/
void Minesweeper::print(int option)
{
	cout<<"------------------------------------------\n";
	cout<<"    ";//print the space part on the left corner.
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
      		if(option==2&&Bboard[i][j]=="M")//Print mines when user lose the game.
			{
        		cout<<"M"<<"   ";
      		}
			else if (option == 3) {
				cout << Bboard[i][j] << "   ";
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
//end print
/*-------------------------------------------------------------------------------------------------Reset----------------------------------------------------------------------------------*/

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
//end Reset


 int Minesweeper::getRowMax()
 {
   return m_row;
 }

int Minesweeper::getColMax()
 {
   return m_col;
 }

 int Minesweeper::getMines()
 {
   return m_mines;
 }
