/** 
 * @author Team FourFour8
 * @file Executive.cpp
 * @date September 2018
 * @brief Executive implementation file 
**/




#include "Executive.h"


// Executive::Executive()
// {
// 	m_row=0;
// 	m_col=0;
// 	m_mines=0;
// }


Executive::Executive(int row, int col, int mines)
{


	m_row=row;
	m_col=col;
	m_mines=mines;
	m_flag=0;

}


void Executive::run()
{
	
	std::cout<<"Welcome to Minesweeper!\n";
	Minesweeper sweep(m_row, m_col, m_mines);
	int row=0;
	int col=0;
	std::string choice="";
	
	while(true)
	{

		
		sweep.print(1);
	
		std::cout<<"Please make your selection:\n1)R(Reveal)\n2)F(Flag)\n3)U(Unflag)\n4)C(Cheat)\n5)E(Exit)\n";
		std::cout<<"You have "<<(m_mines-m_flag)<<" flag(s) can be used.\n";
		std::cin>>choice;

		while(std::cin.fail()) //failbit
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout<<"Please provide a valid entry!\n"<<"Please make your selection:\n1)R(Reveal)\n2)F(Flag)\n3)U(Unflag)\n4)C(Cheat)\n5)E(Exit)\n";
			std::cin>>choice;
			std::cout<<endl;
		}
		
		while(choice!="r" && choice != "R" && choice != "f" && choice!= "F" && choice != "e" && choice != "E" && choice != "u" && choice != "U" && choice != "c" && choice != "C")
		{
			std::cout<<"Provide a valid move: ";
			std::cin>>choice;
			std::cout<<"\n";
		}
		choice=std::toupper(choice[0]);

/*---------------------------------------------------------------------------------Exit--------------------------------------------------------------------------------------------------*/


		if(choice=="E")
		{
			break;
		}




/*---------------------------------------------------------------------------------Revealing----------------------------------------------------------------------------------------------*/
		else if(choice=="R")   //Reveal
		{
			
			std::cout<<"Please enter your row:";
			std::cin>>row;



			while(std::cin.fail()) //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Row:";
				std::cin>>row;
				std::cout<<endl;
			}			//end failbit



		
			while(row>m_row || row<0)   //checks to see if row is in bounds
			{
				std::cout<<"The row you provided is out of bounds. The max row you can select is "<< m_row-1<<"\n Row:";
				std::cin>>row;



				while(std::cin.fail()) //failbit
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout<<"Please enter a number!\n Row:";
					std::cin>>row;
					std::cout<<endl;
				}			//end failbit




			}
			std::cout<<"Please enter your column:";
			std::cin>>col;




			while(std::cin.fail())   //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Col:";
				std::cin>>col;
				std::cout<<endl;
			}			//end failbit



			while(col>=m_col || col<0)  //checks to see if col is in bounds
			{
				std::cout<<"The column you provided is out of bounds. The max column you can select is "<< m_col-1<<"\nCol:";
				std::cin>>col;



				while(std::cin.fail()) //failbit
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout<<"Please enter a number!\n Col:";
					std::cin>>col;
					std::cout<<endl;
				}			//end failbit



			}
			try
			{
				if(sweep.Revealing(row,col)==false)  //after forcing good input, calls Revealing and if it returns false, the user has selected a mine. The game ends
                {
					sweep.print(2);
					std::cout<<"Sorry.You lose!\n Do you want to play again? \n Type 'y' for 'yes' and 'n' for 'no'";
					char playChoice='\0';
					std::cin>>playChoice;
					playChoice=std::tolower(playChoice);
					std::cout<<"Congratulations!You win the game!\n";
					std::cout<<"Do you want to play again?(Yes(Y/y) or No(N/n)):";
					while(true)//loop to get the write answer.
					{
						std::cin>>playChoice;
						if(playChoice=='Y' || playChoice=='y' || playChoice=='N' || playChoice=='n')
						{
						    break;
						}
						else
						{
				    		std::cout<<"Please enter right choice(Only Y/y or N/n).\n";
						}
					}
					if(playChoice=='Y' || playChoice=='y')
					{
					    sweep.Reset();//Reset the board.
					}
					else
					{
						std::cout<<"Goodbye!\n";//End the game.
						break;
					}
				}
			}
			catch(std::runtime_error &e)
			{
				std::cout<<e.what();
			}
				
		}


/*-------------------------------------------------------------------------------Flagging----------------------------------------------------------------------------------------------------*/


		else if(choice=="F")  //Flag
		{
			if(m_flag>=m_mines)
			{
				std::cout<<"\n-----Sorry.You cannot flag more than the number of mines.-----\n";
			}
			else
			{
				char playchoice=' ';
				try
				{
					std::cout<<"Please enter your row:";
					std::cin>>row;
					std::cout<<"Please enter your column:";
					std::cin>>col;
					m_flag++;
					if(sweep.Marking(row,col))//Condition1: user win.
					{
						std::cout<<"Congratulations!You win the game!\n";
						std::cout<<"Do you want to play again?(Yes(Y/y) or No(N/n)):";
						while(true)//loop to get the write answer.
						{
							std::cin>>playchoice;
							if(playchoice=='Y' || playchoice=='y' || playchoice=='N' || playchoice=='n')
							{
								break;
							}
							else
							{
								std::cout<<"Please enter right choice(Only Y/y or N/n).\n";
							}
						}
						if(playchoice=='Y' || playchoice=='y')
						{
							sweep.Reset();//Reset the board.
						}
						else
						{
							std::cout<<"Goodbye!\n";//End the game.
							break;
						}
				    }
				}
				catch(std::runtime_error &e)
				{
					std::cout<<e.what();
				}
		    }
		}

		
/*-------------------------------------------------------------------------------------------UnFlagging-----------------------------------------------------------------------------------------------*/


		else if(choice=="U")  //Unflag
		{
			std::cout<<"Please enter your row:";
			std::cin>>row;




			while(std::cin.fail()) //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Row:";
				std::cin>>row;
				std::cout<<endl;
			}			//end failbit
	




			while(row>m_row || row<0)   //checks to see if row is in bounds
			{
				std::cout<<"The row you provided is out of bounds. The max row you can select is "<< m_row-1<<"\n Row:";
				std::cin>>row;


				
				while(std::cin.fail()) //failbit
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout<<"Please enter a number!\n Row:";
					std::cin>>row;
					std::cout<<endl;
				}			//end failbit



			}
			std::cout<<"Please enter your column:";
			std::cin>>col;




			while(std::cin.fail())   //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Col:";
				std::cin>>col;
				std::cout<<endl;
			}			//end failbit
			



			while(col>m_col || col<0)   //checks to see if col is in bounds
			{
				std::cout<<"The column you provided is out of bounds. The max column you can select is "<< m_col-1<<"\nCol:";
				std::cin>>col;


				
				while(std::cin.fail()) //failbit
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout<<"Please enter a number!\n Col:";
					std::cin>>col;
					std::cout<<endl;
				}			//end failbit


				
			}
			try
			{
				sweep.unMarking(row,col);	//call flagging method after good input is enforced
				m_flag--;
			}
			catch(std::runtime_error &e)
			{
				std::cout<<e.what();
			}
		}
		
		else if (choice == "C") {
			sweep.print(3);
		}		
		
	}
}
