main(i) {
  double arctan1 = 0;
  for (i = 0; i < 10000; i++) {
    arctan1 += pow(-1, i) / (i * 2 + 1);
    if (i % 100 == 0) {
      printf("pi = %f\n", arctan1 * 4);
    }
  }
}
