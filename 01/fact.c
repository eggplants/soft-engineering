int fact(int n) {
  if (n == 0) return 0;
  int res = 1;
  for (; n > 0; n--) res *= n;
  return res;
}

main() {
  int n;
  printf("Please input number: ");
  scanf("%d", &n);
  printf("%d\n", n);
  int flag = (n > 0 ? 1 : -1);
  printf("%d\n", flag * fact(abs(n)));
}
