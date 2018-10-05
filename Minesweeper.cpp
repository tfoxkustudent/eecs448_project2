/**
 * @author Team FourFour8
 * @file Minesweeper.cpp
 * @date September 2018
 * @brief Minesweeper implementation file
**/



#include "Minesweeper.h"
#include <string>
#include <exception>
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
  Bboard = new string*[m_row];
  Sboard = new string*[m_row];
  for (int i = 0; i < Row; i++)
  {
    Uboard[i] = new string [m_col];
    Bboard[i] = new string[m_col];
    Sboard[i] = new string[m_col];
  }
  for(int i=0;i<m_row;i++)
  {
    for(int j=0;j<m_col;j++)
    {
      Uboard[i][j]="■";
      Bboard[i][j]="□";
      Sboard[i][j]="■";
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
    delete[] Bboard[i];
    delete[] Sboard[i];
  }
  delete[] Uboard;
  delete[] Bboard;
  delete[] Sboard;
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
				  if (Bboard[tempRow+i][tempCol+j] == "□") {
					  Bboard[tempRow+i][tempCol+j] = "1";
				  }
				  else {
					int bombCnt = stoi(Bboard[tempRow+i][tempCol+j]);
					bombCnt++;
					Bboard[tempRow+i][tempCol+j] = to_string(bombCnt);
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

/*-------------------------------------------------------------------------------------------------RecCheck-----------------------------------------------------------------------------------*/
void Minesweeper::RecCheck(int Row, int Col)
{
  if(Uboard[Row][Col]!="F")//makes sure flagged spots arn't revealed when being revealed from RecCheck. redundant check first time when being called from revealing()
  {
    if(Bboard[Row][Col]=="□" && Uboard[Row][Col]=="■")//Condition 1: There are no mines adjacent to the input position and this spot is in defalt status.
    {
      Uboard[Row][Col]="□";
      Sboard[Row][Col]="□";
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
      if(Bboard[Row][Col] == "□")//This was set to prevent the situation the 0 will show on the board.
      {
        Uboard[Row][Col]="□";
        Sboard[Row][Col]="□";
      }
      else
      {
        Uboard[Row][Col]=Bboard[Row][Col];//set the spot to the number of the mines those are adjacent to it.
        Sboard[Row][Col]=Bboard[Row][Col];
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
      else if (option == 4){
        cout << Sboard[i][j] << "   ";
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

 /*---------------------------------------------------------------LittleHelperFunction----------------------------*/

void Minesweeper::Helping(int Row, int Col)  //little helper function
{
      bool done = false;
      std::string helpermove;
      for (int i = 0; i < getRowMax(); i++)
      {
        for (int j = 0; j < getColMax(); j++)
        {
          Sboard[i][j]= Uboard[i][j];
        }
      }

      while(done!= true)
      {
        Sboard[Row][Col] = "$";
        for (int i = -1; i <= 1; i++)
        {
   		    for (int j = -1; j <= 1; j++)
          {
   			    if (Sboard[Row+i][Col+j] != "$")
            {
              Sboard[Row+i][Col+j]= Bboard[Row+i][Col+j];
            }
          }
        }
        print(4);
        std::cout<< "Please enter command to move your little helper \n a: for left \n w: for up \n d: for left \n s: for down \n x: to leave helper mode \n";
        std::cin>> helpermove;
        helpermove=std::toupper(helpermove[0]);
        Sboard[Row][Col] = Bboard[Row][Col];
        if(helpermove == "A")
        {
           if(Col==1)
           {
             cout << "You can not move to the edge, you might fall off\n";
             continue;
           }

          for (int i = -1; i <= 1; i++)
          {
            Sboard[Row+i][Col]= Uboard[Row+i][Col];
          }
          --Col;
        }
        else if(helpermove == "W")
        {
          if(Row==1)
          {
            cout << "You can not move to the edge, you might fall off\n";
            continue;
          }

          for (int i = -1; i <= 1; i++)
          {
            Sboard[Row][Col+i]= Uboard[Row][Col+i];
          }
          --Row;
        }
        else if(helpermove == "S")
        {
          if(Row==getRowMax()-2)
          {
            cout << "You can not move to the edge, you might fall off\n";
            continue;
          }

          for (int i = -1; i <= 1; i++)
          {
            Sboard[Row][Col+i]= Uboard[Row][Col+i];
          }
          ++Row;
        }
        else if(helpermove == "D")
        {
          if(Col==getColMax()-2)
          {
            cout << "You can not move to the edge, you might fall off\n";
            continue;
          }

          for (int i = -1; i <= 1; i++)
          {
            Sboard[Row+i][Col]= Uboard[Row+i][Col];
          }
          ++Col;
        }
        else if(helpermove=="X")
        {
          for (int i = -1; i <= 1; i++)
          {
            for (int j = -1; j <= 1; j++)
            {
              Sboard[Row+i][Col+j]= Uboard[Row+i][Col+j];
            }
          }
          done= true;
        }
        else
        {
          cout << "Invalid command, try again.\n";
        }
      }
}
 //end little helper function
