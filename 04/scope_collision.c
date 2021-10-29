main() {
  int v = 0;
  for (;;) {
    printf("%d\n", v);  // 0
    int v = 1;
    printf("%d\n", v);  // 1
    break;
  }
  printf("%d\n", v);  // 0
}
