/**
 * @author Team FourFour8
 * @file Executive.cpp
 * @date September 2018
 * @brief Executive implementation file
**/

#include "Executive.h"

Executive::Executive()
{
	m_flag=0;
}


std::shared_ptr<Minesweeper> Executive::create()
{
	int maxMines=0;

	int row=0;
	int col=0;
	int mines=0;
	m_flag=0;


	std::cout<<"Enter the number of rows you would like: ";
	std::cin>>row;

/*--------------------------------------------------------------------rows failbit------------------------------------------------------------------*/

	while(std::cin.fail()) //failbit
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout<<"Please enter a number!\n Row: ";
		std::cin>>row;
		std::cout<<endl;
	}			//end failbit

	while(row<2|| row>40)   //checks to see if row is in bounds
	{
		std::cout<<"The number of rows you provided is out of bounds. The lower bound is 2 and the upper bound is 40.\n Enter # of rows: ";
		std::cin>>row;

		while(std::cin.fail()) //failbit
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<<"Please enter a number!\n Row: ";
			std::cin>>row;
			std::cout<<endl;
		}			//end failbit

	}

	std::cout<<"Enter the number of columns you would like: ";
	std::cin>>col;

/*--------------------------------------------------------------------columns failbit------------------------------------------------------------------*/
	while(std::cin.fail()) //failbit
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout<<"Please enter a number!\n Col: ";
		std::cin>>col;
		std::cout<<endl;
	}			//end failbit

	while(col<2|| col>40)   //checks to see if row is in bounds
	{
		std::cout<<"The number of columns you provided is out of bounds. The lower bound is 2 and the upper bound is 40.\n Enter # of columns: ";
		std::cin>>col;
		while(std::cin.fail()) //failbit
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<<"Please enter a number!\n Row: ";
			std::cin>>col;
			std::cout<<endl;
		}			//end failbit
	}


	maxMines=(row*col)-1;

	std::cout<<"Enter the number of mines you would like: ";
	std::cin>>mines;

/*--------------------------------------------------------------------mines failbit------------------------------------------------------------------*/
	while(std::cin.fail()) //failbit
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout<<"Please enter a number!\n Mines: ";
		std::cin>>mines;
		std::cout<<endl;
	}			//end failbit

	while(mines<1 || mines>maxMines)   //checks to see if row is in bounds
	{
		std::cout<<"The number of mines you provided is out of bounds. The lower bound is 1 and the upper bound is "<<maxMines<<"\n Enter # of mines: ";
		std::cin>>mines;

		while(std::cin.fail()) //failbit
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<<"Please enter a number!\n Mines: ";
			std::cin>>mines;
			std::cout<<endl;
		}			//end failbit
	}
	return std::make_shared<Minesweeper>(row,col,mines);
}

void Executive::run()
{
	std::cout<<"Welcome to Minesweeper!\n";
	sweep = create();
	int row=0;
	int col=0;
	std::string choice="";

	while(true)
	{
		if (choice == "C") 
		{
			sweep->print(3);
		}
		else 
		{
			sweep->print(1);
		}

		std::cout<<"Please make your selection:\n1)R(Reveal)\n2)F(Flag)\n3)U(Unflag)\n4)C(Cheat)\n5)H(Little Helper)\n6)E(Exit)\n";
		std::cout<<"You have "<<(sweep->getMines()-m_flag)<<" flag(s) that can be used.\n";

		std::cin>>choice;

		while(std::cin.fail()) //failbit
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout<<"Please provide a valid entry!\n"<<"Please make your selection:\n1)R(Reveal)\n2)F(Flag)\n3)U(Unflag)\n4)C(Cheat)\n5)H(Little Helper)\n6)E(Exit)\n";
			std::cin>>choice;
			std::cout<<endl;
		}

		while(choice!="r" && choice != "R" && choice != "f" && choice!= "F" && choice != "e" && choice != "E" && choice != "u" && choice != "U" && choice != "c" && choice != "C" && choice != "h" && choice != "H")
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

			std::cout<<"Please enter your row: ";
			std::cin>>row;



			while(std::cin.fail()) //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Row: ";
				std::cin>>row;
				std::cout<<endl;
			}			//end failbit

			while(row>=sweep->getRowMax() || row<0)   //checks to see if row is in bounds
			{
				std::cout<<"The row you provided is out of bounds. The max row you can select is "<< sweep->getRowMax()-1<<"\n Row: ";
				std::cin>>row;

				while(std::cin.fail()) //failbit
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout<<"Please enter a number!\n Row: ";
					std::cin>>row;
					std::cout<<endl;
				}			//end failbit

			}
			std::cout<<"Please enter your column: ";
			std::cin>>col;

			while(std::cin.fail())   //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Col: ";
				std::cin>>col;
				std::cout<<endl;
			}			//end failbit

			while(col>=sweep->getColMax() || col<0)  //checks to see if col is in bounds
			{
				std::cout<<"The column you provided is out of bounds. The max column you can select is "<< sweep->getColMax()-1<<"\nCol: ";
				std::cin>>col;

				while(std::cin.fail()) //failbit
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout<<"Please enter a number!\n Col: ";
					std::cin>>col;
					std::cout<<endl;
				}			//end failbit

			}
			try
			{
				if(sweep->Revealing(row,col)==false)  //after forcing good input, calls Revealing and if it returns false, the user has selected a mine. The game ends
                {
					sweep->print(2);
					std::cout<<"Sorry. You lose!\n";
					char playChoice='\0';
					// std::cin>>playChoice;
					// playChoice=std::tolower(playChoice);
					// std::cout<<"Congratulations!You win the game!\n";
					std::cout<<"Do you want to play again? (Yes(Y/y) or No(N/n)): ";
					while(true)//loop to get the write answer.
					{
						std::cin>>playChoice;
						if(playChoice=='Y' || playChoice=='y' || playChoice=='N' || playChoice=='n')
						{
						    break;
						}
						else
						{
				    		std::cout<<"Please enter right choice (Only Y/y or N/n): ";
						}
					}
					if(playChoice=='Y' || playChoice=='y')
					{
						sweep = create();
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
			if(m_flag>=sweep->getMines())
			{
				std::cout<<"\n-----Sorry. You cannot flag more than the number of mines.-----\n";
			}
			else
			{
				char playchoice=' ';
				try
				{
					std::cout<<"Please enter your row:";
					std::cin>>row;
                    while(row>=sweep->getRowMax() || row<0)   //checks to see if row is in bounds
                    {
                        std::cout<<"The row you provided is out of bounds. The max row you can select is "<< sweep->getRowMax()-1<<"\n Row: ";
                        std::cin>>row;

                        while(std::cin.fail()) //failbit
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout<<"Please enter a number!\n Row: ";
                            std::cin>>row;
                            std::cout<<endl;
                        }
                    }//end failbit
					std::cout<<"Please enter your column: ";
					std::cin>>col;
                    while(col>=sweep->getColMax() || col<0)  //checks to see if col is in bounds
                    {
                        std::cout<<"The column you provided is out of bounds. The max column you can select is "<< sweep->getColMax()-1<<"\nCol: ";
                        std::cin>>col;

                        while(std::cin.fail()) //failbit
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout<<"Please enter a number!\n Col: ";
                            std::cin>>col;
                            std::cout<<endl;
                        }            //end failbit
                    }

					if(sweep->Marking(row,col))//Condition1: user win.
					{
						std::cout<<"Congratulations! You win the game!\n";
						std::cout<<"Do you want to play again? (Yes(Y/y) or No(N/n)): ";
						while(true)//loop to get the write answer.
						{
							std::cin>>playchoice;
							if(playchoice=='Y' || playchoice=='y' || playchoice=='N' || playchoice=='n')
							{
								break;
							}
							else
							{
								std::cout<<"Please enter right choice (Only Y/y or N/n).\n";
							}
						}
						if(playchoice=='Y' || playchoice=='y')
						{
							sweep = create();
						}
						else
						{
							std::cout<<"Goodbye!\n";//End the game.
							break;
						}
				    }
					else
					{
						m_flag++;
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
			std::cout<<"Please enter your row: ";
			std::cin>>row;

			while(std::cin.fail()) //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Row: ";
				std::cin>>row;
				std::cout<<endl;
			}			//end failbit

			while(row>sweep->getRowMax() || row<0)   //checks to see if row is in bounds
			{
				std::cout<<"That row is unsafe. You might fall off! The max row you can select is "<< sweep->getRowMax()-1<<"\n Row: ";
				std::cin>>row;

				while(std::cin.fail()) //failbit
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout<<"Please enter a number!\n Row: ";
					std::cin>>row;
					std::cout<<endl;
				}			//end failbit

			}
			std::cout<<"Please enter your column: ";
			std::cin>>col;

			while(std::cin.fail())   //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Col: ";
				std::cin>>col;
				std::cout<<endl;
			}			//end failbit

			while(col>sweep->getColMax() || col<0)   //checks to see if col is in bounds
			{
				std::cout<<"That column is unsafe. You might fall off! The max column you can select is "<< sweep->getColMax()-1<<"\nCol: ";
				std::cin>>col;

				while(std::cin.fail()) //failbit
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout<<"Please enter a number!\n Col: ";
					std::cin>>col;
					std::cout<<endl;
				}			//end failbit

			}
			try
			{
				sweep->unMarking(row,col);	//call flagging method after good input is enforced
				m_flag--;
			}
			catch(std::runtime_error &e)
			{
				std::cout<<e.what();
			}
		}

		else if(choice=="H")   //little helper
		{
			std::cout<<"Please enter your row: ";
			std::cin>>row;

			while(std::cin.fail()) //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Row: ";
				std::cin>>row;
				std::cout<<endl;
			}			//end failbit


			while(row>=sweep->getRowMax()-1 || row<=0)   //checks to see if row is in bounds
			{
				std::cout<<"That row is unsafe. If you get too close to the edge you might fall off! The max row you can select is "<< sweep->getRowMax()-1<<"\n Row: ";
				std::cin>>row;

				while(std::cin.fail()) //failbit
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout<<"Please enter a number!\n Row: ";
					std::cin>>row;
					std::cout<<endl;
				}			//end failbit

			}
			std::cout<<"Please enter your column: ";
			std::cin>>col;

			while(std::cin.fail())   //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Col: ";
				std::cin>>col;
				std::cout<<endl;
			}			//end failbit

			while(col>=sweep->getColMax()-1 || col<=0)  //checks to see if col is in bounds
			{
				std::cout<<"That column is unsafe. If you get too close to the edge you might fall off! The max column you can select is "<< sweep->getColMax()-1<<"\nCol: ";
				std::cin>>col;

				while(std::cin.fail()) //failbit
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout<<"Please enter a number!\n Col: ";
					std::cin>>col;
					std::cout<<endl;
				}			//end failbit

			}
			try
			{
				sweep->Helping(row,col);

			}
			catch(std::runtime_error &e)
			{
				std::cout<<e.what();
			}

		}
	}
}
