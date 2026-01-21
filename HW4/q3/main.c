//
// Created by yavidor on 1/13/2026.
//
#include <stdbool.h>
#include <stdio.h>

#define N (100)
#define M (100)

void swapElements(double *firstElement, double *secondElement) {
    double temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

void printMatrix(double a[][M], int n, int m) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            printf("%.2lf", a[row][col]);
            if (col != m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

bool inputMatrix(double a[][M], int n, int m) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            double input;
            if (scanf("%lf", &input) != 1) {
                return false;
            }
            a[row][col] = input;
        }
    }
    return true;
}

void swapRows(double *r1s, double *r1e, double *r2s, double *r2e) {
    double *r1curr = r1s;
    double *r2curr = r2s;
    while (r1curr <= r1e) {
        swapElements(r1curr, r2curr);
        r1curr++;
        r2curr++;
    }
}

void multiplyRow(double *rs, double *re, double scalar) {
    double *rcurr = rs;
    while (rcurr <= re) {
        *(rcurr) *= scalar;
        rcurr++;
    }
}

void addRows(double *r1s, double *r1e, double *r2s, double *r2e, double s) {
    double *r1curr = r1s;
    double *r2curr = r2s;
    while (r1curr <= r1e) {
        *(r1curr) += *(r2curr)*s;
        r1curr++;
        r2curr++;
    }
}

void findLeadElement(double a[][M], int n, int m, int *r, int *c, bool *res) {
    for (int col = 0; col < m; col++) {
        for (int row = 0; row < n; row++) {
            if (a[row][col] != 0) {
                *r = row;
                *c = col;
                *res = true;
                return;
            }
        }
    }
    *res = false;
}

void reduceRows(double a[][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        int lead_r, lead_c;
        bool found;
        findLeadElement(a + i, n - i, m, &lead_r, &lead_c, &found);
        if (!found)
            break;
        int cur_r = i + lead_r;
        if (cur_r != i)
            swapRows(a[cur_r], a[cur_r] + m - 1, a[i], a[i] + m - 1);
        double pivot_val = a[i][lead_c];
        multiplyRow(a[i], a[i] + m - 1, 1 / pivot_val);
        for (int k = i + 1; k < n; k++) {
            double factor = -a[k][lead_c];
            if (factor != 0) {
                addRows(a[k], a[k] + m - 1, a[i], a[i] + m - 1, factor);
            }
        }
    }
}

int main() {
    int n, m;
    double matrix[N][M];
    printf("Enter number of rows (n) and columns (m):\n");
    scanf("%d %d", &n, &m);
    // Ensure that n and m are positive and that m <= M and n <= N.
    if (n <= 0 || n > N || m <= 0 || m > M) {
        printf("Invalid matrix size.\n");
        return 1;
    }
    printf("Enter the matrix elements:\n");
    if (!inputMatrix(matrix, n, m)) {
        printf("Invalid matrix elements.\n");
        return 1;
    }
    // If the function returns false, print the error message and return 1.
    printf("Original Matrix:\n");
    printMatrix(matrix, n, m);
    reduceRows(matrix, n, m);
    printf("Reduced Matrix:\n");
    printMatrix(matrix, n, m);
}
