//
// Created by yavidor on 1/5/2026.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEMURIAN_VALUE 1100

int floor_pow_1_5(int i) {
    if (i == 0)
        return 0;
    long long cubed = (long long)i * i * i;
    int low = 1, high = i * i, ans = 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if ((long long)mid * mid <= cubed) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
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
bool canCross(int p[], int weight, int n, int d) {
    if (p[0] + floor_pow_1_5(0) < weight)
        return false;
    int curr = 0;
    while (curr < n - 1) {
        int next = -1;
        int limit = (curr + d < n - 1) ? curr + d : n - 1;
        for (int i = limit; i > curr; i--) {
            if (p[i] + floor_pow_1_5(i) >= weight) {
                next = i;
            }
        }
        if ((curr = next) == -1)
            return false;
    }
    return true;
}
int max_robot_weight(int p[], int n, int d) {
    int answer = 0;
    int upperBound = MAX_LEMURIAN_VALUE;
    int lowerBound = 1;
    int mid = 1;
    while (lowerBound <= upperBound) {
        mid = lowerBound + ((upperBound - lowerBound) / 2);
        if (canCross(p, mid, n, d)) {
            answer = mid;
            lowerBound = mid + 1;
        } else {
            upperBound = mid - 1;
        }
    }
    return answer ? answer : upperBound - 1;
}

int main(void) {
    int n, d;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    int *p = (int *)malloc(sizeof(int) * n);
    if (!p) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", p + i) != 1) {
            free(p);
            return 1;
        }
    }
    if (scanf("%d", &d) != 1) {
        free(p);
        return 1;
    }
    printf("%d", max_robot_weight(p, n, d));
    free(p);
    return 0;
}