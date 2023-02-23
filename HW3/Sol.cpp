#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>


using namespace std;


//This function checks the values in the rows, columns, and subgrids
bool Val_Check(vector<string>& board, int row, int column, int pos) 
{

 for (int j = 0; j < board.size(); j++) //This Checks Rows
 {
    if (board[row][j] == pos) 
    {
      return false;
    }
 }
      
      for (int i = 0; i < board.size(); i++) //This Checks Columns
      {
        if (board[i][column] == pos) 
        {
          return false;
        }
      }
      //Following checks the Subgrids:
      int grid_size = sqrt(board.size()); //Since the grids will always be related to the board size as a square

      int row1 = row - row % grid_size;
      int col1 = column - column % grid_size;
      for (int i = 0; i < grid_size; i++) 
      {
        for (int j = 0; j < grid_size; j++) 
        {
          if (board[row1 + i][col1 + j] == pos) 
          {
            return false;
          }
        }
      }
      return true; //To return true once all parameters are checked
}


bool Solve_Board(vector<string>& board, int row, int column){
  //This will stop backtracking if the last cell is reached
  if (row == board.size() - 1 && column == board.size())
  {
    return true;
  }
  //This moves our checker to the next row once the last cell is reached, and the column is reset to zero
  if (column == board.size()) 
  {
    row++;
    column = 0;
  }
 
  //Suppose the cell is filled
  if (board[row][column] != '-') 
  {
    return Solve_Board(board, row, column + 1);
  }
 
  //Suppose empty cell, fill the correct number
  for (char val = '1'; val < board.size() + '1'; val++) 
  {
    if (Val_Check(board, row, column, val)) 
    {
      board[row][column] = val; //Assign number only after checking if it's correct (i.e., unique)
      if (Solve_Board(board, row, column + 1)) 
      {
        return true; //If more than one cell returns true, we return true, else empty the cell and continue assigning next numbers to the cell
      }
    }
    board[row][column] = '-';
  }

  //If jumped out, no number is unique and return false
  return false;
}
 
//Printing the Board
void Print_Board(vector<string> board, int i) 
{
  if (i == board.size()) 
  {
    cout << endl;
    return;
  }
  else 
  {
    cout << board[i] << endl;
    Print_Board(board, i + 1);
  }
}
 
 
//Readind values from the file
vector<string> F_Read(string f_name) 
{
  ifstream fin;
  fin.open(f_name);
  vector<string> board;
  string x;
  int data = 0;
  while (getline(fin, x)) 
  {
    board.push_back(x);
    data++;
  }
 
  return board;
}
 
int main()
{
  cout << "Enter the name of file: " << endl;
  string f_name;
  cin >> f_name;
  //f_name = "JohnDoe.txt";
 
  vector<string> board = F_Read(f_name);
  Print_Board(board, 0);
 
  if (Solve_Board(board, 0, 0)) 
  {
    Print_Board(board, 0);
  }
  else 
  {
    cout << "Incorrect Arrangement. Try again!" << endl;
  }
}
