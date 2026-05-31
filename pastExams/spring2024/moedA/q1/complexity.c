#include <stdio.h>


long long f3(long long n) {
    long long counter = 0;
    while (n >= 2) {
        counter += (n + 1);
        n /= 4;
    }
    counter++;
    return counter;
}

long long benchmark(long long n) {
    return (n * (4 / 3))-1;
}

int main() {
    long long n = 50000;
    long long prev_operations = f3(n);
    long long previous_benchmark = benchmark(n);
    for (int i = 1; i < 6; i++) {
        n *= 2;
        long long current_operations = f3(n);
        long long current_bench = benchmark(n);
        long long ratio_operations = current_operations / prev_operations;
        long long ratio_benchmark = current_bench / previous_benchmark;
        printf("Real: Step - %d | Ops -  %lld | Ratio -  %lld\n", i,
               current_operations, ratio_operations);
        printf("Benchmark: Step - %d | Ops -  %lld | Ratio -  %lld\n", i,
               current_bench, ratio_benchmark);
    }
}
