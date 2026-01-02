//
// Created by yonat on 1/2/2026.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SEGMENTS 100 /* m is guaranteed to be between 1 and 100 */

bool validatePair(int m, int index, int height) {
    return height >= 0 && index >= 0 && index < m;
}

void raiseSegments(int *m, int segments[]) {
    scanf(" %d", m);
    int index = 0;
    int height = 0;
    while (scanf(" %d %d", &index, &height) == 2) {
        if (validatePair(*m, index, height)) {
            segments[index] += height;
        }
    }
}

// Implement the function to calculate trapped water you may add more helper
// functions if needed
int calc_trapped_water() {
    int m = 0;
    int segments[MAX_SEGMENTS] = {0};
    raiseSegments(&m, segments);
    for (int i = 0; i < m; i++) {
        printf("%d: %d\n", i, segments[i]);
    }
    return 0;
}

int main() {
    printf("%d\n", calc_trapped_water());
    return 0;
}