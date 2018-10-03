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
#include <memory>


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
 * @brief Run method.  Goes back and forth with the user as the game is played.
 * @pre  valid dimensions and number of mines
 * @post game over
**/
void run();

	private:

/**
 * an integer
 * privately stores the number of flags
**/
int m_flag;

std::shared_ptr<Minesweeper> sweep;

std::shared_ptr<Minesweeper> create();
};
#endif
