#include <stdio.h>
#include <stdlib.h>
double distance(double a, double b) {
  if (a >= b) {
    return a - b;
  }
  return b - a;
}
int closest(double a[], int n, double x) {
  int high = n - 1;
  int low = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] == x) {
      return mid;
    }
    if (a[mid] > x) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (distance(a[low], x) > distance(a[high], x)) {
    return high;
  }
  return low;
}
int main() {
  int n = 0;
  double x = 0;
  scanf("%lf", &x);
  scanf("%d", &n);
  double *a = (double *)malloc(sizeof(double) * n);
  if (a == NULL) {
    printf("FUCK\n");
    exit(1);
  }

  for (int i = 0; i < n; i++) {
    scanf("%lf", a + i);
  }
  printf("%d\n", closest(a, n, x));
}
