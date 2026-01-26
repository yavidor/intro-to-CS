//
// Created by yonat on 1/26/2026.
//
#include <stdio.h>
#include <stdbool.h>

#define N 9


// Function to print the board
void printBoard(int board[N][N]) {
  // You shouldn't change this function!!

  for (int i = 0; i < N; i++) {
    if (i % 3 == 0 && i != 0) {
      printf("---------------------\n");
    }
    for (int j = 0; j < N; j++) {
      if (j % 3 == 0 && j != 0) {
        printf("| ");
      }
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Write your solution in this function.
// You may (and encourage to) use as many helper functions as you want.
bool solveSudoku(int board[N][N]) {
  return false;
}


int main() {
  // You shouldn't change this function!!

  int board[N][N];

  // Read input directly into the board
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  printf("Original Sudoku:\n");
  printBoard(board);

  // If the given board has a solution prints it. Otherwise, print no solution statement.
  if (solveSudoku(board)) {
    printf("Solved Sudoku:\n");
    printBoard(board);
  } else {
    printf("No solution exists.\n");
  }

  return 0;
}