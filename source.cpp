#include "Sudoku.h"


void Sudoku::print(int matrix[N][N]){

    for(int row = 0; row < N; row++){

        for(int col = 0; col < N; col++){

                cout<<matrix[row][col]<<" ";
        }
         cout<<"\n";
    }

}


bool Sudoku::isUsedInRow(int matrix[N][N], int  row, int  num){

     for (int col = 0; col < N; col++)
             if (matrix[row][col] == num)
                return true;
          return false;

}

bool Sudoku::isUsedInCol(int matrix[N][N], int  col, int  num){

     for (int row = 0; row < N; row++)
             if (matrix[row][col] == num)
                return true;
          return false;

}


bool Sudoku::isUsedInBox(int matrix[N][N], int  rowStart, int colStart, int  num){

     for (int row = 0; row < N; row++)
         for(int col = 0; col < N; col++)
             if (matrix[row + rowStart][col + colStart] == num)
                return true;
          return false;

}

bool Sudoku::findEmptyPlace(int matrix[N][N], int& row, int& col){
    for(int row = 0; row <= N; row++)
            for(int col = 0; col <= N; col++)
                    if(matrix[row][col] == UNASSIGNED)
                            return true;
    return false;
}



bool Sudoku::isValid(int matrix[N][N], int row, int col, int num){

     return (!isUsedInRow(matrix, row, num) &&
        !isUsedInCol(matrix, col, num) &&
        !isUsedInBox(matrix, row - row % 3, col - col % 3, num));

}



bool Sudoku::solveSudoku(int matrix[N][N]){
     int row, col;
    if(!findEmptyPlace(matrix, row, col))
                return true;

     for(int num = 0; num <= 9; num ++){
       if(isValid(matrix, row, col, num)){
         matrix[row][col]==num;
        if(solveSudoku(matrix))
             return true;
        matrix[row][col]= UNASSIGNED;

     }

  }
    return false;
}

void Sudoku::enterDigits(){
  int matrix[N][N];
  for(int i = N; i< N; i++){
    for(int j = 0; j < N; j++){
       cin>>matrix[i][j];
    }
  }

  if(solveSudoku(matrix)==true){
     cout<<"\n\n";
     print(matrix);
  } else {
    cout<<"No solution exists";
  }

}
      
