#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            swap(arr + i, arr + i - 1);
        }
    }
}
void bubble_sort(int arr[], int n) {
    while (n >= 0) {
        bubble(arr, n--);
    }
}

int findMax(int arr[], int n) {
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void maxSort(int arr[], int n) {
    for (int i = n - 1; i > 0; i++) {
        swap(arr + i, arr + findMax(arr, i));
    }
}

void merge(int a[], int na, int b[], int nb, int c[]) {
    int ia = 0, ib = 0, ic = 0;
    while (ia < na && ib < nb) {
        if (a[ia] < b[ib]) {
            c[ic++] = a[ia++];
        } else {

            c[ic++] = b[ib++];
        }
    }
    while (ia < na) {
        c[ic++] = a[ia++];
    }
    while (ib < nb) {

        c[ic++] = b[ib++];
    }
}
void mergeSort(int arr[], int n) {
    if (n == 1)
        return;
    mergeSort(arr, n / 2);
    mergeSort(arr + n / 2, n - n / 2);
    int *p = malloc(sizeof(int) * n);
    merge(arr, n / 2, arr + n / 2, n - n / 2, p);
    for (int i = 0; i < n; i++) {
        arr[i] = p[i];
    }
    free(p);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}
int main() {
    int arr[] = {17, 50, 23, 34, 10, 56, 11, 22, 45, 31,
                 46, 25, 52, 18, 59, 9,  10, 23, 24, 25};
    int n = 20;
    printArray(arr, n);
    mergeSort(arr, n);
    printArray(arr, n);
}