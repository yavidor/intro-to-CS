//
// Created by yavidor on 12/22/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define M 1000

int lenPacmanPath(char mat[][M], int n,
                  int m); // Replace this line with your function.

// Do not change these functions
void fillMatrix(char mat[][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &mat[i][j]);
        }
    }
}

// Do not change the main function
int main() {
    int n = 0, m = 0;
    int student_output = -2;
    // First enter the size of the matrix
    scanf(" %d %d", &n, &m);
    // allocating the matrix - will be explained later in the course
    char (*mat)[M] = malloc(n * M * sizeof(char));
    if (mat) {
        fillMatrix(mat, n, m);
        student_output = lenPacmanPath(mat, n, m);
    }
    printf("%d", student_output);
    // Freeing the matrix - will be explained later in the course
    free(mat);
    return 0;
}