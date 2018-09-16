#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Minesweeper
{
private:
  int m_row;
  int m_col;
  int m_mines;
  string** Uboard;// The board for user which will display everytime after user make moves.
  string** Bboard;// The board to store the position of mines.
  int NumOfFlag;// The number of the right flags.
  int GeneralFlag;//The number of the flags the user puts.

  /* 
   * @pre:  Bboard was successfully created.
   * @post: Set the mines on Bboard randomly.
   * @param:Null.
   */
  void setMines();

  /* 
   * @pre:  A valid input position.
   * @post: If there are mines adjacent to the target position, set the position's
   *        content to number returned from Check method.Otherwise, recursively
   *        check the 8 directions.
   * @param:The target position's Row and Col(int).
   */
  void RecCheck(int Row, int Col);

  /* 
   * @pre:  A valid input position.
   * @post: If there are mines adjacent to the target position,
   *        set the position's content to number of mines adjacent to it.
   * @param:The target position's Row and Col(int).
   */
  int Check(int Row, int Col);

  

  

public:
  /*
   * @pre:  Null.
   * @post: 1.Create two boards with the input rows and colns.
   *        2.Set the mines on Bboard.
   * @param:the target position's Row and Col(int).Number of mines the user want(int).
   */
  Minesweeper(int Row, int Col, int NumOfMines);

  ~Minesweeper();

  /*
   * @pre:  Null.
   * @post: Print the Uboard
   * @param:Null.
   */
  void print(int option);

  /*
   * @pre:  A valid input position.
   * @post: Reveal the input position. If the position is a mine, the game is over.
   *        Otherwise, run the rec_check method.Throw exception when the spot is already revealed.
   * @param:the target position's Row and Col(int).
   */
  bool Revealing(int Row, int Col) throw(runtime_error);

  /*
   * @pre:  A valid input position.
   * @post: Put the flag on the input position.Throw exception when the spot is not blank spot.
   * @param:the target position's Row and Col(int).
   */
  bool Marking(int Row, int Col) throw(runtime_error);
  
  /*
   * @pre:  A valid input position.
   * @post: Put the flag on the input position.Throw exception when the spot is not flaged.
   * @param:the target position's Row and Col(int).
   */
  void unMarking(int Row, int Col) throw(runtime_error);

  /* 
   * @pre:  Null.
   * @post: Reset the Uboard and Bboard and the game start over.
   * @param:Null.
   */
  void Reset();
  
};
#endif
