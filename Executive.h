#if#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Minesweeper.h"


class Executive
{
	public:
		Executive();
		Executive(std::string row, std::string col, std::string numMines);
		void run(int row, int col, int numMines);
	private:


};
#endif
#endif
