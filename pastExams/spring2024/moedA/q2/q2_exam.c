#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

double exam_q2(double arr[], int n);

// a_r = a_1 * ratio^r
double rthPlaceInSeries(int r, double a_one, double ratio) {
    return a_one * pow(ratio, r);
}

int binarySearch(double arr[], int n, double ratio) {
    int high = n - 1;
    int low = 0;
    while (low <= high) {
        int mid = (high + low) / 2;
        double expected = rthPlaceInSeries(mid,arr[0],ratio);
        if (arr[mid] != expected) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    // uncomment next line if you don't know the answer
    // printIDontKnow();

    // read the array (length and items)
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    double *arr = (double *) malloc(sizeof(double) * n);
    if (!arr) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", arr + i) != 1) {
            free(arr);
            return 1;
        }
    }

    printf("%.2lf", exam_q2(arr, n));
    free(arr);
    return 0;
}

/* Your code here */

double exam_q2(double arr[], int n) {
    double ratio = pow(arr[n - 1] / arr[0], 1.0 / n);
    int missingIndex = binarySearch(arr, n, ratio);
    return rthPlaceInSeries(missingIndex, arr[0], ratio);
}
