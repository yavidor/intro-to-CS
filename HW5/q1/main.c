//
// Created by yavidor on 1/23/2026.
//
#include <stdbool.h>
#include <stdio.h>
#define NUM_PLATFORMS 3
#define MAX_FARM_SIZE 1000

// Checks if two capys should be swapped
// pop1: The popularity of the first
// plat1: The platform of the first
// pop2: The popularity of the second
// plat2: The platform of the second
bool shouldSwapCapybaras(int pop1, int plat1, int pop2, int plat2) {
    if (plat1 != plat2) {
        return plat1 < plat2;
    }
    return pop1 > pop2;
}

// Swaps two capys
// popularity: The popularity of the capybaras
// platform: The platforms of the capybaras
// i: Index of the first capy
// j: Index of the second capy
void swapCapybaras(int popularity[], int platform[], int i, int j) {
    int temp;
    temp = popularity[i];
    popularity[i] = popularity[j];
    popularity[j] = temp;
    temp = platform[i];
    platform[i] = platform[j];
    platform[j] = temp;
}

// Bubble up one capy array iterations
// popularity: The popularity of the capybaras
// platform: The platforms of the capybaras
// n: length
void bubble(int popularity[], int platform[], int n) {
    for (int i = 1; i < n; i++) {
        if (shouldSwapCapybaras(popularity[i], platform[i], popularity[i - 1],
                                platform[i - 1])) {
            swapCapybaras(popularity, platform, i, i - 1);
        }
    }
}

// Sorts the capybaras
// popularity: The popularity of the capybaras
// platform: The platforms of the capybaras
// n: length
void viralCapySort(int popularity[], int platform[], int n) {
    while (n > 1) {
        bubble(popularity, platform, n--);
    }
}

// Gets the input from the user
// popularity: The popularity of the capybaras
// platform: The platforms of the capybaras
// n: length
void getInput(int popularity[], int platform[], int *n) {
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
        scanf("%d", &popularity[i]);
    for (int i = 0; i < *n; i++)
        scanf("%d", &platform[i]);
}

int main() {
    int n, popularity[MAX_FARM_SIZE], platform[MAX_FARM_SIZE];
    getInput(popularity, platform, &n);
    viralCapySort(popularity, platform, n);
    for (int i = 0; i < n; i++) {
        printf("%d", popularity[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d", platform[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
