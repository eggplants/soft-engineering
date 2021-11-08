#include <stdio.h>

typedef struct person {
  char name[20];
  float weight;
  int height;
} Person;

int main() {
  Person p[] = {{"TaroYAMADA", 50.3, 159},
                {"HanakoKIMURA", 42.1, 149},
                {"JiroSUZUKI", 54.3, 165},
                {"MiyoSATOH", 39.3, 155}};

  int len = sizeof(p) / sizeof(p[0]);
  for (int i = 0; i < len;) {
    Person _p = p[i++];
    printf("%s: {weight => %f, height => %d}\n", _p.name, _p.weight, _p.height);
  }
}
