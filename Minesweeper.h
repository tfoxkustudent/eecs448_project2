/**
 * @author Team FourFour8
 * @file Minesweeper.h
 * @date September 2018
 * @brief Minesweeper class. Handles board creation and modification and can be reset. Generates a User facing board and a private board used to store the mines.
**/




#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


class Minesweeper
{
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
 * a 2D array of strings
 * privately stores the representation of the user facing board
**/
  string** Uboard;// The board for user which will display everytime after user make moves.

/**
 * a 2D array of strings
 * privately stores the representation of the back-facing board
**/
  string** Bboard;// The board to store the position of mines.

/**
 * a 2D array of strings
 * privately stores the representation of the helper's board
**/
  string** Sboard;

/**
 * an integer
 * privately stores the number of flags
**/
  int NumOfFlag;// The number of the right flags.

/**
 * @brief Sets the mines on the randomly using the selected number of mines.
 * @return void
 * @pre Bboard was successfully createad.
 * @post Mines are set on Bboard randomly
**/
  void setMines();




/**
 * @brief RecCheck is A function that recursively checks the spots around it. RecCheck checks each of the eight possible paths and recursively tries each one until it reaches a spot adjacent to a mine or an edge.
 * @return void
 * @param row The given row initially passed in and then recursively there on
 * @param col The given col initially passed in adn then recursively there on
 * @pre A valid input position
 * @post If there are mines adjacent to the target position, set the position'se content to the number returned from the Check method.  Otherwise, recursively continues.
**/
  void RecCheck(int Row, int Col);






/**
 * Check examines a spot and returns an integer representing the number of mines adjacent to that spot.  Check is utilized by RecCheck in that if it returns 0, RecCheck knows to continue recursing.
 * @param row the row to be checked
 * @param col the col to be checked
 * @return number of mines adjacent to that spot
 * @pre A valid input position
 * @post If there are mines adjacent to the target position, sets the position to the number of adjacent mines.
**/
	int Check(int Row, int Col);





public:
/**
 * @pre  Null.
 * @post Create two boards with the input rows and colns and sets the mines on Bboard.
 * @param row the target position's row (int)
 * @param the target position's column (int)
 * @param NumofMines Number of mines the user wants (int). Exclusively between 1 and row*col - 1

**/
  Minesweeper(int Row, int Col, int NumOfMines);




/**
 * @pre  Null.
 * @post destroys board and clears memory
**/
  ~Minesweeper();

/**
 * @brief
 * @pre  Null.
 * @post Print the Uboard
 * @param Null.


**/
  void print(int option);

   /**
   * @brief unMarking is the function that deals with revealing
   * @pre  A valid input position.
   * @post spot and potentially the spots around it are revealed. Game ends if spot is a mine
   * @param row the target position's Row (int)
   * @param col the target position's column (int)
   **/
  bool Revealing(int Row, int Col);

    /**
   * @brief Marking is the function that deals with flagging
   * @pre  A valid input position.
   * @post spot is flagged
   * @param row the target position's Row (int)
   * @param col the target position's column (int)
   **/
  bool Marking(int Row, int Col);

  /**
   * @brief unMarking is the function that deals with unflagging
   * @pre  A valid input position.
   * @post spot is unflagged
   * @param row the target position's Row (int)
   * @param col the target position's column (int)
   **/
  void unMarking(int Row, int Col);
/**
 * @brief Reset creates a new board with the same dimensions but randomizes the placement of the mines.
 * @pre  Null.
 * @post Reset the Uboard and Bboard and the game start over.
 * @param Null.
**/
  void Reset();


  /**
   * @brief Returns max number of rows in board
   * @pre NONE
   * @return number of rows in board
   **/
  int getRowMax();

  /**
   * @brief Returns max number of columns in board
   * @pre NONE
   * @return number of columns in board
   **/
  int getColMax();


    /**
   * @brief Returns number of mines
   * @pre NONE
   * @return number of rnumber of mines
   **/
  int getMines();

  /**
  * @brief Returns Character and surround spaces
  * @pre A valid Input location
  * @return character and surrounding spaces
  **/
  void Helping(int Row, int Col);

};
#endif
