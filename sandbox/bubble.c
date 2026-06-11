#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void bubble(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] > arr[i]) {
      swap(arr + (i - 1), arr + i);
    }
  }
}

void bubble_sort(int *arr, int n) {
  for (int i = n; i > 0; i--) {
    bubble(arr, i);
  }
}
int main() {
  int a[] = {4, 73, 647, 234, 8, 1, 57, 90, 100, 80};
  int b[] = {3, 72, 646, 235, 7, 3, 55, 93, 103, 76};
  for (int i = 0; i < 10; i++) {
    printf("%d,", a[i]);
  }
  printf("\n\n%zu\n\n", sizeof(a) / sizeof(int));
  bubble_sort(a, 10);
  printf("\n");
  for (int i = 0; i < 10; i++) {
    printf("%d,", a[i]);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    printf("%d,", b[i]);
  }
  printf("\n\n%zu\n\n", sizeof(b) / sizeof(int));
  bubble_sort(b, 10);
  printf("\n");
  for (int i = 0; i < 10; i++) {
    printf("%d,", b[i]);
  }
  printf("\n");

  return 0;
}
