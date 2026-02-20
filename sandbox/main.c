//
// Created by yavidor on 1/1/2026.
//
#include <stdio.h>
#include <stdlib.h>

void cpystr(char *str1, char *str2) {}
int lenstr(char *str) {
    char *ptr = str;
    int length = 0;
    while (*ptr != '\0') {
        ptr++;
        length++;
    }
    return length;
}
int main(void) {
    char *str1 = "Hello, World!";
    char *str2 = "HE";
    printf("%s: %d\n", str1, lenstr(str1));
    printf("%s: %d\n", str2, lenstr(str2));
}
