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
  int num;
  int remaining;
  string** Uboard;
  string** Bboard;
  void setMines(std::string **arr, int row, int col, int mimes, std::string mineSignal);
  bool RecCheck(int Row,int Col);
  int Check(int Row,int Col);
  /*
   * @pre:  Bboard was successfully created.
   * @post: Set the mines on Bboard randomly.
   * @param:Number of mines(int).
   */
  void setMines(int NumOfMines);
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
  /*
   * @pre: None
   * @post: Print the Uboard to check for the process
   * @param:None
   */
  void print();
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
   * @pre:  A valid input position.
   * @post: Reveal the input position. If the position is a mine, the game is over.
   *        Otherwise, run the rec_check method.
   * @param:the target position's Row and Col(int).
   */
  bool Revealing(int Row, int Col);
  /*
   * @pre:  A valid input position.
   * @post: Put the flag on the input position.
   * @param:the target position's Row and Col(int).
   */
  bool Marking(int Row, int Col);

};
#endif
