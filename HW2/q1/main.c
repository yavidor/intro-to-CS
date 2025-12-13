//
// Created by yavidor on 13/12/2025.
//

#include <stdbool.h>
#include <stdio.h>

#define ALPHABET_SIZE 26
#define MAX_INPUT_SIZE 30
#define MAX_KEY_SIZE 10
#define A_ASCII_VAL 97

/*
 * -------------------
 * | Algorithm Steps |
 * -------------------
 * (1) Get the input, split it into the input and the key V
 * (2) Calculate the word size of the key
 * (3) For each hist 0-26 go over the input's words one by one:
 *              (3.a) Calculate the size
 *              (3.b) If it's the same as the key's size, compare
 *              (3.c) If they're the same, return the hist
 */

// Function declarations

// Utils

// Returns true if character is a-z, false otherwise
bool isAlpha(const char text[], int index);

// Gets the length of a word, defined by characters a-z
int getWordLen(const char text[], int index, int maxSize);

// Returns the index of the next non alphabet character
int getNextWordIndex(const char text[], int index, int maxSize);

// Steps

// Step (1) - Fills the key and input arrays with the user input, divided by \n
void getInput(char input[], char key[]);

// Steps (3.a) (3.b) Iterate over the words in the input
bool validate(char text[], char key[], int keySize);

// Step (3.c) - Compares two words of the same size
bool compareWords(const char input[], const char key[], int wordSize,
                  int inputIndex);

// Implementations

bool isAlpha(const char text[], const int index) {
    return text[index] >= 'a' && text[index] <= 'z';
}

int getWordLen(const char text[], int index, const int maxSize) {
    int length = 0;
    while (index < maxSize && isAlpha(text, index)) {
        length++;
        index++;
    }
    return length;
}

int getNextWordIndex(const char text[], int index, int maxSize) {
    while (index <= maxSize && isAlpha(text, index)) {
        index++;
    }
    return index;
}

void getInput(char input[], char key[]) {
    int index = 0;           // Index within the current array being filled
    bool isFirstLine = true; // Are we on the first line of the input
    char inputChar = 0;
    while (scanf("%c", &inputChar) != EOF) {
        if (inputChar == '\n') {
            isFirstLine = false;
            index = 0;
            continue;
        }
        if (isFirstLine) {
            input[index++] = inputChar;
        } else {
            key[index++] = inputChar;
        }
    }
}

bool compareWords(const char input[], const char key[], const int wordSize,
                  const int inputIndex) {
    int index = 0;
    while (index < wordSize && input[index + inputIndex] == key[index]) {
        index++;
    }
    return index == wordSize;
}

void decrypt(char text[], const int size, const int hist, char output[]) {
    for (int i = 0; i < size - 1; i++) {
        if (text[i] != ' ' && !isAlpha(text, i)) {
            continue;
        }
        if (text[i] == ' ') {
            output[i] = ' ';
            continue;
        }
        output[i] =
            ((text[i] - A_ASCII_VAL + hist) % ALPHABET_SIZE) + A_ASCII_VAL;
    }
}

bool validate(char text[], char key[], const int keySize) {
    int index = 0;
    do {
        const int wordSize = getWordLen(text, index, MAX_INPUT_SIZE);
        if (wordSize == keySize) {
            if (compareWords(text, key, wordSize, index)) {
                return true;
            }
        }
        index = getNextWordIndex(text, index, MAX_INPUT_SIZE) + 1;
    } while (index < MAX_INPUT_SIZE && isAlpha(text, index));
    return false;
}

int main(void) {
    char input[MAX_INPUT_SIZE];
    char key[MAX_KEY_SIZE];
    getInput(input, key);
    const int keySize = getWordLen(key, 0, MAX_KEY_SIZE);
    for (int hist = 0; hist < ALPHABET_SIZE; hist++) {
        char encrypted[MAX_INPUT_SIZE];
        decrypt(input, MAX_INPUT_SIZE, hist, encrypted);
        if (validate(encrypted, key, keySize)) {
            printf("%d", ALPHABET_SIZE - hist);
        }
    }
    return 0;
}
