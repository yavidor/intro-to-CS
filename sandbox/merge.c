#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int an, int *b, int bn, int *c) {
  int ai = 0;
  int bi = 0;
  int ci = 0;
  while (ai < an && bi < bn) {
    if (a[ai] < b[bi]) {
      c[ci++] = a[ai++];
    } else {
      c[ci++] = b[bi++];
    }
  }
  while (ai < an) {
    c[ci++] = a[ai++];
  }
  while (bi < bn) {
    c[ci++] = b[bi++];
  }
}

void merge_sort(int arr, int n) { int *temp = (int *)malloc(sizeof(int) * n); }

int main() {
  int a[] = {4, 73, 647, 234, 8, 1, 57, 90, 100, 80};
  int b[] = {3, 72, 646, 235, 7, 3, 55, 93, 103, 76};
  int c[20];
  merge(a, 10, b, 10, c);
  for (int i = 0; i < 20; i++) {
    printf("%d\n", c[i]);
  }
  return 0;
}
