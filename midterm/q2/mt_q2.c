#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
  printf("%s", DONT_KNOW);
  exit(0);
}

int midterm_quiz_q2(long long n);
bool isPrime(long long candidate);

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
  // printIDontKnow();

  long long n;
  if (scanf("%lld", &n) != 1) {
    return 1;
  }
  printf("%d", midterm_quiz_q2(n));
  return 0;
}

bool isPrime(long long candidate) {
  // There are no divisors that are larger than half the original number
  for (int i = 2; i < candidate / 2; i++) {
    // q is a divisor p <=> p % q == 0
    // p is prime <=> p has no divisors
    if (candidate % i == 0) {
      return false;
    }
  }
  return true;
}

int midterm_quiz_q2(long long n) {
  // Counter for the prime
  int primeCounter = 0;
  // 2^k
  long long powerOfTwo = 2;
  while (powerOfTwo < n) {
    powerOfTwo *= 2;
    // The number we want to check: 2^k - 1, probably not the correct spelling
    long long marsen = powerOfTwo - 1;
    // checking that we got a prime number without going over our target
    if (marsen <= n && isPrime(marsen)) {
      primeCounter += 1;
    }
  }
  return primeCounter;
}