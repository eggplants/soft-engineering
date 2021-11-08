#include <stdio.h>

//名前、体重、身長からなる構造体 person
typedef struct person {
  char name[20];
  float weight;
  int height;
} Person;  // Person型

float calc_bmi(Person p) {
  return p.weight / (p.height / 100.0 * p.height / 100.0);
}

int main() {
  Person p = {"TaroYAMADA", 50.3, 159};
  printf("%s: {weight => %f, height => %d, ", p.name, p.weight, p.height);
  printf("BMI => %f}\n", calc_bmi(p));

  p.weight = 51.5;
  printf("%s: {weight => %f, height => %d, ", p.name, p.weight, p.height);
  printf("BMI => %f}\n", calc_bmi(p));
  return 0;
}
