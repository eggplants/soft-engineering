#include <stdio.h>
int i = 0;

int global_count() {
  i++;
  return -1;
}

int main() {
  for (int j = 0; j < 100; j++) {
    printf("return value = %d, global i = %d\n", global_count(), i);
  }
}
