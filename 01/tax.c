main() {
  float price;
  printf("Please input price: ");
  scanf("%f", &price);
  price *= 1.08;
  printf("The total price is %.0f yen (reduced tax rate)\n", price);
}
