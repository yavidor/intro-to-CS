//
// Created by yonat on 1/26/2026.
//
#include <stdbool.h>
#include <stdio.h>

#define N 9
#define N_ROOT 3

bool checkRow(int board[N][N], int row);
bool checkCol(int board[N][N], int col);
bool checkSquares(int board[N][N], int row, int col);
bool isLegal(int board[N][N], int row, int col);
int countZeros(int board[N][N]);
void getNextZero(int board[N][N], int *row, int *col);

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
bool checkRow(int board[N][N], int row) {
    bool values[N] = {0};
    for (int i = 0; i < N; i++) {
        int boardValue = board[row][i];
        if (values[boardValue] == true) {
            return false;
        }
        values[boardValue] = true;
    }
    return true;
}

bool checkCol(int board[N][N], int col) {
    bool values[N] = {0};
    for (int i = 0; i < N; i++) {
        int boardValue = board[i][col];
        if (values[boardValue] == true) {
            return false;
        }
        values[boardValue] = true;
    }
    return true;
}
bool checkSquares(int board[N][N], int row, int col) {


}
bool isLegal(int board[N][N], int row, int col) {
    return checkCol(board, col) && checkRow(board, row) &&
           checkSquares(board, row, col);
}

bool findSolution(int board[N][N], int row, int col) {
    if (board[row][col] != 0 || (row == N - 1 && col == N - 1)) {
        return isLegal(board, row, col);
    }
    bool flag = false;
    for (int value = 1; value <= N; value++) {
        if (!isLegal(board, row, col)) {
            continue;
        }
        board[row][col] = value;
        flag = flag || findSolution(board, row, col);
    }
    return flag;
}

// Write your solution in this function.
// You may (and encourage to) use as many helper functions as you want.
bool solveSudoku(int board[N][N]) {
    bool flag = false;
    int row = 0;
    int col = 0;
    while (countZeros(board) != false) {
        getNextZero(board, &row, &col);
        flag = findSolution(board, row, col);
        printf("%d\n", flag);
        if (flag == true) {
            return flag;
        }
    }
    return flag;
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

    // If the given board has a solution prints it. Otherwise, print no solution
    // statement.
    if (solveSudoku(board)) {
        printf("Solved Sudoku:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}