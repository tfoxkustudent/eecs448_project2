#include "Executive.h"


Executive::Executive()
{
	m_row=0;
	m_col=0;
	m_mines=0;
}


Executive::Executive(std::string row, std::string col, std::string numMines)
{


	m_row=std::stoi(row);
	m_col=std::stoi(col);
	m_mines=std::stoi(numMines);


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
		std::cout<<"1)Reveal\n2)Flag\n3)Unflag\n4)Reset\n5)Exit\nPlease make your selection(Enter numbers only):";
		std::cin>>choice;
		int length=choice.size();
		for(int i=0;i<length;i++)
		{
			std::tolower(choice[i]);
		}
		if(choice=="5")//Choose to exit;
		{
			break;//Break the loop and end the game.
		}
		else if(choice=="1")//Choose to reveal 
		{
			std::cout<<"Please enter your row:";
			std::cin>>row;
			std::cout<<"Please enter your column:";
			std::cin>>col;
			if(sweep.Revealing(row,col)==false)//The cricumstance that user click on the mine. Revealing returned a false.
			{
				
				sweep.print(2);//print the board with mines on it.
				std::cout<<"Sorry.You lose!\n";
				std::cout<<"Do you want to play again?(Yes(Y/y) or No(N/n)):";
				char playchoice=' ';
				while(true)// infinite loop to take right choice.
				{
					std::cin>>playchoice;
					if(playchoice=='Y' || playchoice=='y' || playchoice=='N' || playchoice=='n')
					{
						break;//end the loop until get the right choice.
					}
					else
					{
						std::cout<<"Please enter right choice(Only Y/y or N/n).\n";
					}
			    }
				if(playchoice=='Y' || playchoice=='y')
				{
					sweep.Reset();
				}
				else
				{
					std::cout<<"Goodbye!\n";
					break;
				}
			}
		}
		else if(choice=="2")//Chose to flag
		{
			bool Markingflag=false;
			char playchoice=' ';
			while(Markingflag!=true)
			{
				try
				{
					std::cout<<"Please enter your row:";
					std::cin>>row;
					std::cout<<"Please enter your column:";
					std::cin>>col;
					if(sweep.Marking(row,col,1))
					{
						std::cout<<"Congratulations!You win the game!\n";
						std::cout<<"Do you want to play again?(Yes(Y/y) or No(N/n)):";
						
						while(true)
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
						Markingflag=true;
					}
			    }
				catch(std::runtime_error &e)
				{
					std::cout<<e.what();
				}
			}
			if(playchoice=='Y' || playchoice=='y')
			{
				sweep.Reset();
			}
			else
			{
				std::cout<<"Goodbye!\n";
				break;
			}

		}
		else if(choice=="3")
		{
			std::cout<<"Please enter your row:";
			std::cin>>row;
			std::cout<<"Please enter your column:";
			std::cin>>col;
			sweep.Marking(row,col,2);//Marking function with option=2 is for unflaging.
		}
		else if(choice=="4")
		{
			sweep.Reset();
		}
	}
}
