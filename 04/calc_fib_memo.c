#include <stdio.h>
int N = 45;
int memo[100];

int calc_fib(int n) {
  if (memo[n] == 0) memo[n] = n < 2 ? n : calc_fib(n - 1) + calc_fib(n - 2);
  return memo[n];
}

void main() {
  int i = 0;
  for (; ++i <= N;) printf("%2d: %-10d%c", i, calc_fib(i), i % 5 ? ' ' : '\n');
}
