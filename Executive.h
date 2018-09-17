#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Minesweeper.h"


class Executive
{
	public:
		//Executive();
		/* 
		* @pre:  Bboard was successfully created.
		* @post: Taking in the numbers of Rows,Columns and Number of Mines.
		* @param:Rows,Columns and Number of Mines(strings).
		*/
		Executive(int row, int col, int numMines);
		//~Executive();
		void run();
	private:
		int m_row;
		int m_col;
		int m_mines;
		int m_flag;
};
#endif
