#include <stdio.h>

int var_global = 0;

int func(int num) {
  int var_func = 0;
  for (int i = 0; i < 1; i++) {
    int var_block = 0;
    // printf("var_global = %d", var_global);//1
    // printf("var_func = %d", var_func);//2
    // printf("var_block = %d", var_block);//3
  }
  // printf("var_global = %d", var_global);//4
  // printf("var_func = %d", var_func);//5
  // printf("var_block = %d", var_block);//6
  return num;
}

void main() {
  func(100);
  // printf("var_global = %d", var_global);//7
  // printf("var_func = %d", var_func);//8
  printf("var_block = %d", var_block);  // 9
}
