//
// Created by yavidor on 1/23/2026.
//
#include <stdbool.h>
#include <stdio.h>
#define NUM_PLATFORMS 3
#define MAX_FARM_SIZE 1000

bool shouldSwapCapybaras(int pop1, int plat1, int pop2, int plat2) {
    if (pop1 != pop2)
        return pop1 < pop2;
    return plat1 > plat2;
}

void swapCapybaras(int popularity[], int platform[], int i, int j) {
    int temp;
    temp = popularity[i];
    popularity[i] = popularity[j];
    popularity[j] = temp;
    platform[i] = platform[j];
    platform[j] = platform[i];
}

void viralCapySort(int popularity[], int platform[], int n) {
    printf("%d\n", popularity[0]);
    printf("%d\n", platform[0]);
    printf("%d\n", n);
}

int main() {
    int n, popularity[MAX_FARM_SIZE], platform[MAX_FARM_SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &popularity[i]);
    }
    for (int i = 0; i <= n; i++) {
        scanf("%d", &platform[i]);
    }
    viralCapySort(popularity, platform, n);
    for (int i = 0; i < n; i++) {
        printf("%d", popularity[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d", platform[0]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}