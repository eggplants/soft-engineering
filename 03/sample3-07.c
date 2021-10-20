main() {
  double number = 0;
  printf("Please input number: ");
  scanf("%lf", &number);
  printf("(%lf)² = %lf\n", number, pow(number, 2));
}
