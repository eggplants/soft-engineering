#include <stdio.h>
#include <string.h>

int memo[1000][1000];

int pascal(int row, int col) {
  if (row <= 0 || col <= 0) return 0;
  if (row == 1 && col == 1) return 1;
  if (memo[row][col] == 0)
    memo[row][col] = pascal(row - 1, col) + pascal(row - 1, col - 1);
  return memo[row][col];
}

void repeat_space(int n, int width) {
  for (int i = 0; i < n * width; i++) printf(" ");
}

int main() {
  int n = 40;
  int max = pascal(n, n / 2);
  int d = 1;
  for (; max > 10; d++) max = max / 10;
  char digit[100];
  sprintf(digit, "%d", d);
  char format[] = "%-";
  strcat(format, digit);
  strcat(format, "d ");
  puts(format);
  for (int i = 1; i <= n; i++) {
    repeat_space(n + 1 - i, n / d - 1);
    for (int j = 1; j <= i; j++) {
      printf(format, pascal(i, j));
    }
    puts("");
  }
}
