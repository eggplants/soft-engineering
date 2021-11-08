#include <stdio.h>

typedef struct person {
  char name[20];
  float weight;
  int height;
} Person;

float calc_bmi(Person p) {
  return p.weight / (p.height / 100.0 * p.height / 100.0);
}

int main() {
  Person p[5];
  int i;

  for (i = 0; i < 5;) {
    printf("%02d: name> ", i);
    scanf("%s", p[i].name);
    printf("%02d: weight> ", i);
    scanf("%f", &p[i].weight);
    printf("%02d: height> ", i);
    scanf("%d", &p[i++].height);
  }
  for (i = 0; i < 5;) {
    Person j = p[i];
    float bmi = calc_bmi(j);
    printf("%s (%02d): BMI => %f\n", j.name, i++, bmi);
  }
  return 0;
}
