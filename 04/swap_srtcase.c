#include <stdio.h>

char _swap_case(char c) {
  if (64 < c && c < 91) {
    c += 32;
  } else if (96 < c && c < 123) {
    c -= 32;
  }
  return c;
}

void swap_case(char *arr) {
  int i = 0;
  while (arr[i] != '\0') arr[i++] = _swap_case(arr[i]);
}

void main() {
  char s[] = "Doraemon (September 3, 2112-)";
  printf("original: %s\n", s);
  swap_case(s);
  printf("swapped: %s\n", s);
}
