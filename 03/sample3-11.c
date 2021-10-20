float calc_tax(float price) {
  float new_price = price * 1.08;
  return new_price;
}

int main() {
  float f;
  f = calc_tax(100);
  printf("%f", f);
}
