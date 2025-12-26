#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
  printf("%s", DONT_KNOW);
  exit(0);
}

int midterm_quiz_q3(int arr[], int n);
bool isPerfect(int candidate);

// Do not change read_arr!!!
int *read_arr(int *n) {
  if (scanf("%d", n) != 1)
    return NULL;
  int *arr = malloc((*n) * sizeof(int));
  if (!arr)
    return NULL;
  for (int i = 0; i < *n; i++) {
    if (scanf("%d", arr + i) != 1) {
      free(arr);
      return NULL;
    }
  }
  return arr;
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
  // printIDontKnow();

  int n;
  int *arr = read_arr(&n);
  if (!arr)
    return 1;
  printf("%d", midterm_quiz_q3(arr, n));
  free(arr);
  return 0;
}

bool isPerfect(int candidate) {
  // The summation of the natural divisors
  int sum = 0;
  // There are no divisors that are larger than half the original number
  for (int i = 1; i <= candidate / 2; i++) {
    // q is a divisor p <=> p % q == 0
    if (candidate % i == 0) {
      sum += i;
    }
  }
  // A number is perfect if it's equal to the sum of its
  return sum == candidate;
}

int midterm_quiz_q3(int arr[], int n) {
  // Counter for the perfect numbers
  int perfectCounter = 0;
  // Count the perfect numbers in the array
  for (int i = 0; i < n; i++) {
    if (isPerfect(arr[i])) {
      perfectCounter++;
    }
  }
  return perfectCounter;
}