int arg_test(int a) {
  printf("!! a before calc in the function is: %d\n", a);
  a *= 5;
  printf("!! a after calc in the function is: %d\n", a);
  return a;
}

main() {
  int a = 100;
  int b;
  printf("a before run function is: %d\n", a);
  b = arg_test(a);
  printf("a after run function is: %d\n", a);
  printf("return value b is: %d\n", b);
}
