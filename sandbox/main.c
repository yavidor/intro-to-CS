#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void f3(long long n);

void g3(long long n);

static long long ops = 1;

long long g(int n) {
  ops++;
  if (!n)
    return 2;
  for (int i = 1; i * i < n; i++)
    ;
  return n + g(n / 2);
}

void f2(int n) {
  ops++;
  free(malloc(g(n) * g(n)));
}

long long benchmark(long long n) { return sqrt(n); }

int main() {
  int n = 1;
  f2(n);
  long long previous_ops = ops;
  long long previous_benchmark = benchmark(n);
  long long current_ops = 0;
  long long current_benchmark = 0;
  for (int i = 0; i < 10; i++) {
    printf("----------\nStep: %d, n: %d\n------------\n", i, n);
    n++;
    ops = 0;
    f2(n * n);
    current_ops = ops;
    current_benchmark = benchmark(n * n);
    long long ratio_ops = current_ops / previous_ops;
    long long ratio_benchmark = current_benchmark / previous_benchmark;
    printf("----\nOps: Current: %lld | Previous: %lld | Ratio: %lld\n",
           current_ops, previous_ops, ratio_ops);
    printf("----\nBenchmark: Current: %lld | Previous: %lld | Ratio: %lld\n",
           current_benchmark, previous_benchmark, ratio_benchmark);
    previous_benchmark = current_benchmark;
    previous_ops = current_ops;
  }
}
