#include <stdio.h>

char* func_arr() {
  char ret_arr[] = "Hey! This is a local string in a function\n";
  return ret_arr;
}

int main() { printf("%s", func_arr()); }
