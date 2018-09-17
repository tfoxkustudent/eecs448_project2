/** 
 * @author Team FourFour8
 * @file Executive.h
 * @date September 2018
 * @brief Executive class. Takes in rows and columns from user, creates a Minesweeper object and interacts with the user
**/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Minesweeper.h"
#include <limits>
#include <cstdlib>
#include <stdlib.h>


class Executive
{
	public:

/**
 * @brief Executive default constructor
 * @pre  none
 * @post private variables set to 0
**/
  Executive();
  
/**
 * @brief Executive class constructor. Stores row, col, and  mines privately
 * @pre  row, col, and mines are valid integers within range
 * @post stores private params in private variables
 * @param row number of rows for the board
 * @param col number of columns for the board
 * @param mines number of mines for the board
**/
  Executive(int row, int col, int mines);
		


/**
 * @brief Run method.  Goes back and forth with the user as the game is played.
 * @pre  valid dimensions and number of mines
 * @post game over
**/
void run();

	private:




/**
 * an integer
 * privately stores the number of rows
**/
int m_row;

/**
 * an integer
 * privately stores the number of columns
**/
int m_col;
		


/**
 * an integer
 * privately stores the number of mines
**/
int m_mines;

/**
 * an integer
 * privately stores the number of flags
**/
int m_flag;

};
#endif
