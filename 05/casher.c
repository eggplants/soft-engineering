#include <stdio.h>

#define N 3
#define TAX 10

typedef struct purchase {
  char purchaser_name[20];
  char product_name[20];
  int price;
  int number;
} Purchase;

int calc_tax(int price, int tax) {
  return (int)(price / 100.0 * tax);
}

int main() {
  Purchase p[N];
  int i;

  for (i = 0; i < N;) {
    printf("%02d: name> ", i);
    scanf("%s", p[i].purchaser_name);
    printf("%02d: good name> ", i);
    scanf("%s", p[i].product_name);
    printf("%02d: price of %s> ", i, p[i].product_name);
    scanf("%d", &p[i].price);
    printf("%02d: count of %s> ", i, p[i].product_name);
    scanf("%d", &p[i++].number);
  }
  for (i = 0; i < N;) {
    Purchase j = p[i++];
    int subtotal = j.price * j.number;
    int tax = calc_tax(subtotal, TAX) ;
    printf(
      "`%s' bought %d `%s', ",
      j.purchaser_name, j.number, j.product_name
    );
    printf(
      "{subtotal => %d, tax => %d, total => %d}\n",
      subtotal, tax, subtotal + tax
    );
  }
  return 0;
}

