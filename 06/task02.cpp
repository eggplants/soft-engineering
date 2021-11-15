#include <stdio.h>

#include <iostream>
#include <string>

using namespace std;

class Person {
 public:
  // member
  string name;
  int height, birth_year;
  float weight, bmi;

  // constructor
  Person(string name, int h, float w, int birth_year);

  // method
  void show_name();
  void self_introduce(int current_year);
};

Person::Person(string n, int h, float w, int y) {
  name = n;
  height = h;
  weight = w;
  birth_year = y;
  bmi = weight / ((height / 100.0) * (height / 100.0));
}

void Person::show_name() { cout << name << endl; };

void Person::self_introduce(int current_year) {
  cout << "Hello, I am " << name << "! My BMI is " << bmi << ", ";
  cout << "and I am " << current_year - birth_year << " years old in "
       << current_year << endl;
};

int main() {
  int current_year = 2021;
  Person taro("Taro YAMADA", 168, 52.5, 1988);
  taro.show_name();
  taro.self_introduce(current_year);
  Person jiro("Jiro SASAKI", 170, 50.0, 2000);
  jiro.show_name();
  jiro.self_introduce(current_year);
  Person mari("Mari SAKAI", 180, 85.0, 1999);
  mari.show_name();
  mari.self_introduce(current_year);
  return 0;
}
