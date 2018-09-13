#include "Executive.h"
#include <time.h>

int main(int argc, char* argv[])
{

	if(argc<4)
	{
		std::cout<<"Incorrect number of parameters!  Program should be run as './e1 [row] [col] [numberOfMines]' \n";
	}
	else
	{


		Executive exec(argv[1],argv[2],argv[3]);
		exec.run();

	}

	
return(0);
}
