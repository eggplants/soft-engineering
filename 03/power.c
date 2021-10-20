float power(float a, float b) {
  float result = 1.0;
  for (int i = 1; i <= b; i++) {
    result *= a;
  }
  return result;
}

main() {
  for (float i = 1; i <= 9; i++) {
    for (float j = 1; j <= 9; j++) {
      printf("%10.0f", power(i, j));
    }
    printf("\n");
  }
}
