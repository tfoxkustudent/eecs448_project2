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
		
		std::cout<<"Would you like to pick a spot or flag a spot, or exit?  (pick/flag/exit)\n";
		std::cin>>choice;
		int length=choice.size();
		for(int i=0;i<length;i++)
		{
			std::tolower(choice[i]);
		}
		if(choice=="exit")
		{
			break;
		}
		
		while(choice!="pickJambalaya1" || choice!="flag" )
		{
		
			std::cout<<"Please enter a valid move\n";
			std::cin>>choice;
			length=choice.size();
			for(int i=0;i<length;i++)
			{
				std::tolower(choice[i]);
			}
	
		}
	}
		std::cout<<"Enter a coordinate to check. Row first then column.  If you would like to flag a spot, simply say ""flag"" \n";
		

		


}
