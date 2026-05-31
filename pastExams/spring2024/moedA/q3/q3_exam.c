#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q3(char arr[], int n);

int main() {
    // uncomment next line if you don't know the answer
    // printIDontKnow();
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    getchar();

    char *arr = (char *) malloc((n) * sizeof(char));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n - 1; ++i) {
        scanf("%c", &arr[i]);
    }
    arr[n - 1] = '\0';


    for (int i = 0; i < n; ++i) {
        if (arr[i] == ' ') {
            arr[i] = '\0';
        }
    }

    exam_q3(arr, n);

    for (int i = 0; i < n; ++i) {
        if (arr[i] == '\0') {
            printf(" ");
        } else {
            printf("%c", arr[i]);
        }
    }

    free(arr);
    return 0;
}

/* Your code here */

void reverseString(char str[], int n) {
    int startIndex = 0;
    while (startIndex < n / 2) {
        int endIndex = n - 1 - startIndex;
        char temp = str[endIndex];
        str[endIndex] = str[startIndex];
        str[startIndex] = temp;
        startIndex++;
    }
}

void printStringArr(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == '\0') {
            printf("-");
        } else {
            printf("%c", arr[i]);
        }
    }
    printf("\n");
}

void exam_q3(char arr[], int n) {
    reverseString(arr, n);
    int index = 1;
    while (index < n) {
        int startingIndex = index-1;
        int word_len = 1;
        while (arr[index] != '\0' && index < n) {
            index++;
            word_len++;
        }
        reverseString(arr + startingIndex, word_len);
        index++;
    }
}
