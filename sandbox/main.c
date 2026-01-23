//
// Created by yavidor on 1/1/2026.
//
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void recursive_sort(int a[], int n) {
    int i;
    if (n <= 1) {
        return;
    }
    recursive_sort(a + 1, n - 1);
    for (i = 0; (i < n - 1) && (a[i] > a[i + 1]); i++) {
        swap(a + i, a + i + 1);
    }
}

int main(void) {}
