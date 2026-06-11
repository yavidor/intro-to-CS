#include <stdio.h>
#include <stdlib.h>

void merge(const int *a, int an, const int *b, int bn, int *c) {
  int ai = 0;
  int bi = 0;
  int ci = 0;
  while (ai < an && bi < bn) {
    c[ci++] = a[ai] < b[bi] ? a[ai++] : b[bi++];
  }
  while (ai < an) {
    c[ci++] = a[ai++];
  }
  while (bi < bn) {
    c[ci++] = b[bi++];
  }
}

void merge_sort(int *arr, int n) {
  if (n == 1) {
    return;
  }
  int *temp = (int *)malloc(sizeof(int) * n);
  int half_point = n / 2;
  int remainder = n - half_point;
  merge_sort(arr, half_point);
  merge_sort(arr + half_point, remainder);
  merge(arr, half_point, arr + half_point, remainder, temp);
  for (int i = 0; i < n; i++) {
    arr[i] = temp[i];
  }
  free(temp);
}

int main() {
  int a[] = {4, 73, 647, 234, 8, 1, 57, 90, 100, 80};
  int b[] = {3, 72, 646, 235, 7, 3, 55, 93, 103, 76};
  for (int i = 0; i < 10; i++) {
    printf("%d,", a[i]);
  }
  printf("\n\n%zu\n\n", sizeof(a) / sizeof(int));
  merge_sort(a, 10);
  printf("\n");
  for (int i = 0; i < 10; i++) {
    printf("%d,", a[i]);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    printf("%d,", b[i]);
  }
  printf("\n\n%zu\n\n", sizeof(b) / sizeof(int));
  merge_sort(b, 10);
  printf("\n");
  for (int i = 0; i < 10; i++) {
    printf("%d,", b[i]);
  }
  printf("\n");

  return 0;
}
