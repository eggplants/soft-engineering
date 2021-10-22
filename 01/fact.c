#include <stdio.h>

int fact(int n) {
  if (n < 0) {
    fprintf(stderr, "Error: n must be positive\n");
    exit(1);
  }
  if (n == 0) return 1;
  int res = 1;
  for (; n > 0; n--) res *= n;
  return res;
}

main() {
  int n;
  printf("Please input number: ");
  scanf("%d", &n);
  printf("%d\n", fact(n));
}
