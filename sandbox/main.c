//
// Created by yavidor on 1/1/2026.
//
#include <stdio.h>
#include <stdlib.h>

void notmain(char *str) {
    *(str + 1) += 1;
    printf("%s\n", str);
}

int main(void) {
    char sarr[] = "Camels are good";
    char *parr = "I love camels";
    notmain(sarr);
    notmain(parr);
}