#include <stdio.h>

void swap(char *s, int a, int b) {
  char tmp = s[a];
  s[a] = s[b];
  s[b] = tmp;
}

void reverse(char *s) {
  int n = sizeof(s) - 1;
  for (int i = 0; i < n / 2; i++) {
    swap(s, i, n - i - 1);
  }
}

void main() {
  char a[] = "abcdefg";
  printf("original: %s\n", a);
  reverse(a);
  printf("reversed: %s\n", a);
}
