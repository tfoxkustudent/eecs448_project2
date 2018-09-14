#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Minesweeper.h"
#include <limits>
#include <cstdlib>
#include <stdlib.h>


class Executive
{
	public:
		Executive();
		Executive(int row, int col, int mines);
		void run();
	private:
		int m_row;
		int m_col;
		int m_mines;
};
#endif
