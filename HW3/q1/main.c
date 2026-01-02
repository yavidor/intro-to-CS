//
// Created by yavidor on 12/22/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define M 1000

void makeMove(int position[], char direction, int n, int m) {
    switch (direction) {
    case 'U':
        position[0] = (position[0] + n - 1) % n;
        break;
    case 'D':
        position[0] = (position[0] + 1) % n;
        break;
    case 'L':
        position[1] = (position[1] + m - 1) % m;
        break;
    case 'R':
        position[1] = (position[1] + 1) % m;
        break;
    }
}

int lenPacmanPath(char mat[][M], int n, int m) {
    int pos[] = {0, 0};
    int length = 0;
    char direction = 0;
    do {
        if (mat[pos[0]][pos[1]] != '#') {
            direction = mat[pos[0]][pos[1]];
        }
        length++;
        makeMove(pos, direction, n, m);
    } while (!(pos[0] == 0 && pos[1] == 0) && length <= n * m);
    if (length <= n * m) {
        return length;
    }
    return -1;
}

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