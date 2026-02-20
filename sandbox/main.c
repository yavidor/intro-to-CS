
// Created by yavidor on 1/1/2026.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STRSIZE 200

void cpystr(char *str1, char *str2) {
    char *str1ptr = str1;
    char *str2ptr = str2;
    while (*str1ptr != '\0') {
        *str2ptr = *str1ptr;
        str1ptr++;
        str2ptr++;
    }
    *str2ptr = '\0';
}
int lenstr(char *str) {
    char *ptr = str;
    int length = 0;
    while (*ptr != '\0') {
        ptr++;
        length++;
    }
    return length;
}
void catstr(char *str1, char *str2) {
    char *ptr1 = str1;
    char *ptr2 = str2;
    while (*ptr1 != '\0') {
        ptr1++;
    }
    while (*ptr2 != '\0') {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0';
}

bool cmpstr(char *str1, char *str2) {
    if (lenstr(str1) < lenstr(str2)) {
        return -1;
    }
    char *ptr1 = str1;
    char *ptr2 = str2;
    while (*ptr1 != '\0') {
        if (*ptr1 > *ptr2) {
            return 1;
        }
        if (*ptr1 < *ptr2) {
            return -1;
        }
    }
    return 0;
}

void swap(int *ptr1, int *ptr2) {
    printf("%d - %d\n", *ptr1, *ptr2);
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void bubble(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            swap(arr + (i - 1), arr + i);
        }
    }
}

void bubble_sort(int arr[], int n) {
    while (n > 1) {
        printf("1\n");
        bubble(arr, n--);
    }
}

int findMax(int arr[], int n) {
    int max = arr[0];
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void maxSort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        swap(arr + i, arr + findMax(arr, i));
    }
}

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main(void) {
    int arr[] = {7, 9, 2, 5, 3};
    int n = 5;
    printf("%d\n", n);
    print_arr(arr, n);
    maxSort(arr, n);
    print_arr(arr, n);
}
