#include <stdio.h>

/*
Author: Ari Chai
Course: CS125
Assignment: In Class Exercise 10/01
References: Course Material, brief ChatGPT usage for debugging

Note: For the extra credit opportunity, I wrote a program that is capable
of adding two user-entered matrices of any size.
*/

int addMatrices(int row, int column, int m1[row+1][column+1], int m2[row+1][column+1], int mSum[row+1][column+1]) {
  int i=0, j=0;
  for (i=0; i<=row; i++) {
    for (j=0; j<=column; j++) {
      mSum[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

int main() {
  
  int matrixRows, matrixColumns;
  int i, j, userVal;
  
  printf("\n\nEnter the number of rows: ");
  scanf("%d", &matrixRows);
  printf("\nEnter the number of columns: ");
  scanf("%d", &matrixColumns);
  printf("You entered a %d by %d matrix.", matrixRows, matrixColumns);
  
  int matrix1[matrixRows][matrixColumns], matrix2[matrixRows][matrixColumns], matrixSum[matrixRows][matrixColumns];
  matrixRows--;
  matrixColumns--;
  
  printf("\nBegin entering values for Matrix 1: ");
  for (i=0; i<=matrixRows; i++) {
    for (j=0; j<=matrixColumns; j++) {
      scanf("%d", &userVal);
      matrix1[i][j] = userVal;
    }
  }
  
  printf("\n\nBegin entering values for Matrix 2: ");
  for (i=0; i<=matrixRows; i++) {
    for (j=0; j<=matrixColumns; j++) {
      scanf("%d", &userVal);
      matrix2[i][j] = userVal;
    }
  }

  printf("\n\nMatrix 1: \n");
  for (i=0; i<=matrixRows; i++) {
    for (j=0; j<=matrixColumns; j++) {
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
  }
  
  printf("\n\nMatrix 2: \n");
  for (i=0; i<=matrixRows; i++) {
    for (j=0; j<=matrixColumns; j++) {
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }
  
  addMatrices(matrixRows, matrixColumns, matrix1, matrix2, matrixSum);
  
  printf("\n\nSum of Matrix 1 and Matrix 2: \n");
  for (i=0; i<=matrixRows; i++) {
    for (j=0; j<=matrixColumns; j++) {
      printf("%d ", matrixSum[i][j]);
    }
    printf("\n");
  }
  
  
}