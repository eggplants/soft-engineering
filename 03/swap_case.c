char swap_case(char c) {
  if (64 < c && c < 91) {
    c += 32;
  } else if (96 < c && c < 123) {
    c -= 32;
  }
  return c;
}

main() {
  puts("Input your name and postal code:");
  char s[50];
  scanf("%50[^\n]", &s);
  int i = 0;
  char cc;
  while (s[i] != '\0') {
    cc = swap_case(s[i]);
    s[i++] = cc;
  }
  printf("Cases have swapped: %s\n", s);
}
