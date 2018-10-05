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

/**
 * a shared pointer
 * privately stores the minesweeper board
**/
std::shared_ptr<Minesweeper> sweep;

/**
 * Handles user input to create new board
 * @return shared pointer to new board
**/
std::shared_ptr<Minesweeper> create();
};
#endif
