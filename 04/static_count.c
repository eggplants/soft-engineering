#include <stdio.h>

int static_count() {
  static int i = 0;
  i++;
  return i;
}

int main() {
  for (int j = 0; j < 100; j++) {
    printf("%d\n", static_count());
  }
  // printf("%d\n", i);
}
