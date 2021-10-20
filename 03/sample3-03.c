main() {
  int i;
  float f;
  double dbl;
  printf("input an integer number: ");
  scanf("%d", &i);
  printf("i = %d as int, %d as float\n", i, i);
  printf("input a float number: ");
  scanf("%f", &f);
  printf("f = %d as int, %d as float\n", f, f);
  printf("input an integer number: ");
  scanf("%d", &dbl);
  printf("dbl = %d as int, %lf as double\n", dbl, dbl);
  dbl += 1.0;
  printf("dbl + 1 = %d as int, %lf as double\n", dbl, dbl);
}
