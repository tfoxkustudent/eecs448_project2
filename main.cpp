
/** 
 * @author Team FourFour8
 * @file main.cpp
 * @date September 2018
 * @brief main. handles initial i/o and gives control off to exec
**/


#include "Executive.h"
#include <time.h>

int main(int argc, char* argv[])
{

	if(argc<1)
	{
		std::cout<<"Incorrect number of parameters!\n";
	}
	else
	{
		int maxMines=0;

		int row=0;
		int col=0;
		int mines=0;
		

		std::cout<<"Enter the number of rows you would like: ";
		std::cin>>row;

/*--------------------------------------------------------------------rows failbit------------------------------------------------------------------*/

		while(std::cin.fail()) //failbit
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<<"Please enter a number!\n Row:";
			std::cin>>row;
			std::cout<<endl;
		}			//end failbit


