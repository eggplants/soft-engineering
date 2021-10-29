#include <stdio.h>
int N = 45;

int calc_fib(int n) { return n < 2 ? n : calc_fib(n - 1) + calc_fib(n - 2); }

void main() {
  int i = 0;
  for (; ++i <= N;) printf("%2d: %-10d%c", i, calc_fib(i), i % 5 ? ' ' : '\n');
}
