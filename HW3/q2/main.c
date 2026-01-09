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
int min(int first, int second) {
    if (first < 0 && second < 0) {
        return 0;
    }
    if (first >= second) {
        return second;
    }
    return first;
}

int getLeftBoundary(int segments[], int initialIndex) {
    for (int i = 0; i < initialIndex; i++) {
        if (segments[i] > segments[initialIndex]) {
            return segments[i];
        }
    }
    return segments[initialIndex];
}

int getRightBoundary(int segments[], int initialIndex, int m) {
    for (int i = m - 1; i > initialIndex; i--) {
        if (segments[i] > segments[initialIndex]) {
            return segments[i];
        }
    }
    return segments[initialIndex];
}

int addWater(int m, int segments[], int index) {
    int left = getLeftBoundary(segments, index);
    int right = getRightBoundary(segments, index, m);
    return min(left - segments[index], right - segments[index]);
}

// Implement the function to calculate trapped water you may add more helper
// functions if needed
int calc_trapped_water() {
    int m = 0;
    int segments[MAX_SEGMENTS] = {0};
    int sum = 0;
    raiseSegments(&m, segments);
    for (int i = 1; i < m - 1; i++) {
        sum += addWater(m, segments, i);
    }
    return sum;
}

int main() {
    printf("%d\n", calc_trapped_water());
    return 0;
}