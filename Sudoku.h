#pragma once
#include <iostream>
#include <cstdlib>

#define N 9
#define UNASSIGNED 0

using namespace std;

//const int N = 9;
//const int UNASSIGNED = 0;
class Sudoku{

    private:
        bool  isUsedInRow(int matrix[N][N], int  row, int  num);
        bool  isUsedInCol(int matrix[N][N], int  col, int  num);
        bool  isUsedInBox(int matrix[N][N],int  rowStart, int colStart,int  num);
        bool isValid(int matrix[N][N], int row, int col, int num);
        bool findEmptyPlace(int matrix[N][N], int& row, int& col);

    public:
     // int N;
      Sudoku(){}
      ~Sudoku(){}
      void print(int matrix[N][N]);
      bool solveSudoku (int matrix[N][N]);
      void enterDigits();




};

