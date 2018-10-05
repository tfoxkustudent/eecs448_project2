
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
	
	Executive exec;
	exec.run();

	}

	
return(0);
}

