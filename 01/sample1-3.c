#include <stdio.h>

int main(int argc, char* argv[]) {
  char str1[] = "Hello";
  char str2[] = "world";
  char* t = argv[0];
  printf("%s %s! I'm %s!\n", str1, str2, t);
}
