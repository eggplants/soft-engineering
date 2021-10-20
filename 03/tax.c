main() {
  float price;
  printf("input price: ");
  scanf("%f", &price);
  printf("current price is %f yen (tax. .08%%)\n", price * 1.08);
}
