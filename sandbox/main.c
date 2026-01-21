//
// Created by yavidor on 1/1/2026.
//
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double *something = malloc(3 * sizeof(double));
    *something = 1.0;
    *(something + 1) = 2.0;
    *(something + 2) = 3.0;
    double *somethingElse = something;
    (*somethingElse)++;
    somethingElse+=2;
    printf("%lf\n", *something);
    printf("%lf\n", *somethingElse);
    free(something);
}