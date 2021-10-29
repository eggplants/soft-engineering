#include <stdio.h>

int pointer_count(int *i) {
  i[0]++;
  return i[0];
}

int main() {
  int i[] = {0};
  for (int j = 0; j < 100; j++) {
    printf("%d\n", pointer_count(i));
  }
  printf("%d", i[0]);
}
