#include <iostream>

using namespace std;

class Person {
 public:
  int weight;
  int& w() { return weight; };
};

int main() {
  Person p;
  p.w() = 50;
  cout << "p.w = " << p.weight << endl;
};
