//
// Created by yavidor on 12/12/2025.
//

#include <stdbool.h>
#include <stdio.h>

#define ALPHABET 26
#define MAX_INPUT_SIZE 30
#define MAX_INPUT_SIZE_STR "30"
#define MAX_KEY_SIZE 10
#define A_ASCII_VAL 97
#define MAX_HIST 26

void encrypt(char text[], const int size, int hist) {
    char arr[size];
    arr[size - 1] = '\0';
    for (int i = 0; i < size - 1; i++) {
        if (text[i] != ' ' && (text[i] < 'a' || text[i] > 'z')) {
            printf("AYO BRO GET THE FUCK OUT OF HERE WITH THAT %d SHIT\n",
                   text[i]);
            continue;
        }
        if (text[i] == ' ') {
            arr[i] = ' ';
            continue;
        }
        arr[i] = ((text[i] - A_ASCII_VAL + hist) % ALPHABET) + A_ASCII_VAL;
    }
    printf("%s\n", arr);
}

void getInput(char input[], char key[]) {
    int index = 0;           // Index within the current array being filled
    bool isFirstLine = true; // Are we on the first line of the input
    char inputChar = 0;
    while (scanf("%c", &inputChar) != EOF) {
        if (inputChar == ' ') {
            isFirstLine = false;
            index = 0;
        }
        if (isFirstLine) {
            input[index++] = inputChar;
        } else {
            key[index++] = inputChar;
        }
    }
}

int main(void) {
    char input[MAX_INPUT_SIZE];
    char key[MAX_KEY_SIZE];
    getInput(input, key);

    for (int i = 0; i < MAX_HIST; i++) {
        encrypt(input, MAX_INPUT_SIZE, i);
    }
    return 0;
}
