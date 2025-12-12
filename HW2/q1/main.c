//
// Created by yavidor on 12/11/2025.
//

#include <stdio.h>

#define ALPHABET 26
#define SIZE 27
#define A_ASCII 97
#define MAX_HIST 26

void encrypt(const char text[], const int size, int hist) {
    char arr[size];
    arr[size - 1] = '\0';
    for (int i = 0; i < size - 1; i++) {
        if (text[i] == ' ') {
            arr[i] = ' ';
            continue;
        }
        arr[i] = ((text[i] - A_ASCII + hist) % ALPHABET) + A_ASCII;
    }
    printf("%s\n", arr);
}

int main(void) {
    char plain[SIZE] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < MAX_HIST; i++) {
        encrypt(plain, SIZE, i);
    }
    return 0;
}
