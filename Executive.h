#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Minesweeper.h"


class Executive
{
	public:
		Executive();
		Executive(std::string row, std::string col, std::string numMines);
		void run();
	private:
		int m_row;
		int m_col;
		int m_mines;
};
#endif
