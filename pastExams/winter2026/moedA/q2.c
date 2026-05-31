#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
#define MAX_WORD_LENGTH 10

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int examA_q2(char **arr, int n, int m);

//Do not change these functions
void free_string_arr(char **arr, int n) {
    for (int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);
}

bool read_string(char **s) {
    int len;
    if (scanf("%d", &len) != 1) {
        return false;
    }
    *s = malloc((len + 1) * sizeof(char));
    if (!*s) {
        return false;
    }
    if (scanf("%s", *s) != 1) {
        free(*s);
        return false;
    }
    return true;
}

int main(void) {
    // uncomment next line if you don't know the answer
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;
    char **arr = malloc(sizeof(char *) * n);
    if (!arr) return 1;
    for (int i = 0; i < n; i++) {
        if (!read_string(arr + i)) {
            free_string_arr(arr, i);
            return 1;
        }
    }
    int m;
    if (scanf("%d", &m) != 1) {
        free_string_arr(arr, n);
        return 1;
    }
    printf("%d", examA_q2(arr, n, m));
    free_string_arr(arr, n);
    return 0;
}

bool tryPoemLength(char **arr, int n, int m,int length) {
    
}

int examA_q2(char **arr, int n, int m) {
    printf("n: %d, m: %d\n", n, m);
    int high = n * 10;
    int low = 0;
    while (low < high) {
        int mid = (high + low) / 2;
        if (tryPoemLength(arr,n,m,mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
