int fact(int n) {
  if (n == 0) return 1;
  int res = 1;
  while (n > 0) res *= n--;
  return res;
}

main() {
  float d;
  int n;
  while (n < 10) {
    d += 1.0 / fact(n++);
  }
  printf("e ≒ %f (n = %d)\n", d, n);
}
